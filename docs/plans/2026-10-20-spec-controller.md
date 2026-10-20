# MiniMat Day 2 spec + Days 3–4 controller: Plan

**Goal:** a written rulebook (`docs/SPEC.md`), then a controller around `PE_Top` that runs a whole job (START → clear → issue → drain → capture → sticky done) and passes K = 1..8 against a reference model.

**Architecture:** a new module wraps the proven `PE_Top`. `PE_Top`'s existing start/clear rules become the controller→array contract. Completion comes from a token [marker bit riding with the last valid] through the real pipeline, never from a cycle count.

**Tech stack:** Verilog RTL; SystemVerilog TB + SVA include fragments; Verilator (5.032 yours, 5.020 cloud); Yosys; `make`.

**Spec:** `Doc/minimat_project_overview.pdf` pp. 9–10 (+ p. 12 assertions), the day 2–4 brief from the 30 Sep chat, then `docs/SPEC.md` once written.

**Execution:** you build your tasks on your laptop; Claude does its tasks in a Claude Code session. No subagents (you write the RTL).

## Context
- You asked: catch up on the earlier chats, read the code, plan Day 2 + Days 3–4. The TT trial harden is your own time, out of scope.
- Your answers (2026-10-20): ref model = Claude; scoreboard = you + Claude; controller = new module around `PE_Top`.
- Earlier chats:
  - 30 Sep: roadmap (`docs/ROADMAP.md`). You skipped days 1–2 (ref model, random jobs, checker fixes). The day 2–4 brief came from that chat.
  - 18 Oct (TT chat): the trial wrapper commit `c996e4b` was never pushed (GitHub 403), so it's likely lost and area is still unknown.
- Assumed: your spec-lite notes exist but aren't in the repo yet.

## Who does what
- You: all RTL, stimulus, protocol-aware checks, SVA, the content of `docs/SPEC.md`.
- Claude: ref model + its self-test, scoreboard plumbing [counters, summary, watchdog, mismatch report], Makefile, docs, reviews, runs, mutation tests [plant one bug, confirm a check fails].
- `CLAUDE.md` gets this exception written in (Task 1).

## Where you stand (measured 2026-10-20, cloud container: Verilator 5.020, Yosys 0.33)
- `make all`: PASS, `FINAL C = {19, 22, 43, 50}`.
- `make lint`: only the 3 known warnings.
- `make synth` (`PE_Top`): 3,032 cells, 279 flops (260 in PEs, 19 in the counter), no latches.
- `make seeds-pe` fails seeds 2–5; `make seeds-top` fails seeds 1, 3, 4. All at the first edge (5 ns): the known `$past` artifact, on more seeds than `CLAUDE.md` says.
- Missing for a controller: busy/done, result registers, internal data skew (your TB fakes it), any rule for K=0 or START while busy.
- Kill list: 4/10 as of 30 Sep (no RTL/SVA change since). The ref model comes back inside Task 7.

## Global constraints
- Math: signed INT8 × signed INT8 → signed 16-bit product → signed 32-bit accumulate, wrap. K = 1..8, latched at START.
- busy: high from an accepted START until results are captured. done: set at capture, sticky until CLEAR or the next accepted START.
- done comes from the token. No S+K+3-style count anywhere in RTL.
- Synchronous active-low reset on every new flop; no `initial` in RTL.
- `make pe` and `make top` keep passing after every task.
- No new lint warnings from new or changed code.
- SVA, ref model and scoreboard files are include fragments; never pass them to Verilator directly.

## Review focus (each gets a test in Task 7 or 8)
1. START with K=0 or K>8: never hangs (rejected, or the watchdog fails the run).
2. CLEAR or reset mid-job: the aborted job's token never raises done later.
3. START while busy, on every cycle of a job incl. the last drain cycle: ignored, result unchanged.
4. Back-to-back jobs with different K (8 then 1), incl. START on the first done cycle: no leftover products.
5. Operand bytes changing outside the issue window or after done: results unchanged; result registers stable while done.

---

### Task 1 (Claude): docs sync
**Files:** create `docs/plans/2026-10-20-spec-controller.md` (this plan); modify `docs/ROADMAP.md`, `CLAUDE.md`.
- [x] This plan, on branch `claude/blissful-fermi-hgu70i` for you to merge.
- [ ] ROADMAP: status rows, split line per your answers, TT note (wrapper never pushed).
- [ ] CLAUDE.md: the working-agreement exception; cloud tool install (`apt-get install -y verilator yosys` → 5.020 / 0.33); seed-failure counts on 5.020.
- [ ] `make all` still PASS. Commit + push to `claude/blissful-fermi-hgu70i`; you open the PR and merge.

### Task 2 (you; Claude reviews): `docs/SPEC.md`, Day 2
- [ ] Paste your notes into the chat or push them. Claude tidies formatting; your words stay.
- [ ] Cover the brief's 12 decisions and the PDF p.19 table, plus these gaps (Claude's suggestion in brackets):
  - K after reset/CLEAR [if 0, START is rejected until SET_K]
  - SET_K after a LOAD changes the payload length [clears A_loaded/B_loaded]
  - SET_K / LOAD_A / LOAD_B while busy [rejected + flag; PDF: buffers stable START→DONE]
  - CLEAR while busy [aborts the job]; does CLEAR also zero the result registers?
  - START while done [allowed; done drops; old results readable until the new capture]
  - READ_C while busy; which error flags exist and what clears them; READ_ID bytes
  - result registers vs readable accumulators [PDF: result registers; revisit after the trial harden]
- [ ] Add an outcome table: 8 commands × {IDLE, BUSY, DONE}, one outcome per cell.
- Exit: no "TBD"; Claude finds no contradiction with PDF pp. 9–10.

### Task 3 (you; Claude reviews): controller on paper, Day 3 morning
Decide (Claude's suggestion in brackets):
- D1 token path [enters with the last issue, rides `PE_Top`'s valid delay and PE11's product stage, reported when PE11 adds its last product]. A cycle count, or a copy of the delay inside the controller, is the "guessed count" the PDF bans.
- D2 step index source [one counter: `PE_Top` reports its accepted count]
- D3 row-1/col-1 skew [controller delays those two bytes one cycle; one index]
- D4 operand read latency [same cycle]. Your TB model and the day-5 buffer must match it.
- D5 START while busy [controller ignores it; the command layer (days 6–7) owns `start_rejected`]
- D6 results [result registers in the controller, loaded once per job]
- D7 CLEAR request mid-job [back to IDLE; array cleared; token killed]
- D8 K outside 1..8 at START [controller ignores START, same as busy]
- Module and port names [yours; the PDF calls it `systolic_controller`]

Draw:
- [ ] State diagram: 5 states, reset and abort arrows, the condition on every arrow.
- [ ] Cycle tables for K=1 and K=3: edge, state, step k, which k sits on row0/col0 and on row1/col1, v00/v01/v10/v11, PE11 product-valid, token position, busy, done, result load.
- [ ] A short abort table (CLEAR mid-issue).
- [ ] The done edge as a formula of K.
- Exit: Claude's independent derivation (from `PE_Top`'s header table, the S+K+3 rule and your choices) matches every row.

### Task 4 (Claude): reference model, in parallel with Tasks 2–3
**Files:** create `tb/ref_model.sv` (fragment) and `tb/ref_model_tb.sv`; Makefile `ref` target.
**Produces:** `function automatic logic signed [31:0] ref_c(input int i, input int j, input int k_len, input logic signed [7:0] a [2][8], input logic signed [7:0] b [8][2])` = sum over k < k_len of a[i][k]·b[k][j], 32-bit wrap. Plain math, no systolic schedule.
- [ ] Self-test values: K=2 brief matrices → {19, 22, 43, 50}; PDF K=3 example → {10, −11, 6, 6}; K=8 all −128 → 131072; K=8 127 × −128 → −130048; K=1 corners.
- [ ] Self-test proves it flags a wrong expectation.
- Exit: `make ref` prints `PASS: ref model self-test`. Signature confirmed on Verilator 5.020 (if unsupported, Claude adjusts it and notes the change here).

### Task 5 (you): token path in the array
**Files:** modify `src/PE.v`, `src/PE_Top.v` (+ step-index output if D2); tie the new ports in `tb/PE_tb.sv` and `tb/PE_Top_tb.sv`; update the `PE_Top.v` header table.
- [ ] The token is cleared by reset and by clear, exactly like the valids.
- Exit: `make pe` + `make top` PASS unchanged; in the K=2 test the token exits on the edge PE11 adds its final product (E5 in your header table); no new lint warnings.

### Task 6 (you + Claude): controller RTL, Day 3 afternoon
**Files:** create `src/<your_ctrl>.v`. Claude, once names exist: Makefile `ctrl`, `seeds-ctrl`, `wave-ctrl`; `lint` and `synth` on the new top.
**Consumes:** Task 3 decisions and names; Task 5 ports.
- [ ] IDLE → CLEAR → ISSUE → DRAIN → DONE per your Task 3 diagram: K latched at START, row-1/col-1 skew, capture on the token, busy/done.
- Exit: no lint warnings from the new file; `make synth` shows no latches and a flop delta near +160 (128 result bits + skew + K + state); a directed K=2 job through the controller gives `{19, 22, 43, 50}`.

### Task 7 (you + Claude): TB + scoreboard, Day 4
**Files:** create `tb/<your_ctrl>_tb.sv` (you) and `tb/scoreboard.sv` (Claude, fragment).
**Consumes:** `ref_c` (Task 4); your Task 3 done formula.
- Claude: `sb_compare(...)` [expected via `ref_c`; prints job id, K, A, B, expected vs got for the first mismatch], pass/fail counters, `sb_final()` [prints `SCOREBOARD: N jobs, M mismatches`; `$fatal` if M>0 or N=0], watchdog [fails a job with no done within a bound], `JOBS`/`SEED` run options. Argument lists fitted to your TB skeleton.
- You: operand source model (arrays indexed by step k, D4 latency), job sequencing + job record, when to sample results, done-cycle check against your formula, busy/done checks.
- [ ] Directed K=1 and K=3: valids, busy and done match your tables cycle for cycle.
- [ ] K = 1..8 × ≥100 random jobs each, values weighted to −128, 127, 0, −1.
- [ ] Review-focus cases 1–5.
- Exit: `make ctrl` prints `SCOREBOARD: ≥800 jobs, 0 mismatches` with every K hit; same for `SEED=2..5`.

### Task 8 (you): controller SVA
**Files:** create `tb/<your_ctrl>_sva.sv` (fragment, included at the end of your TB after `past_valid`).
- [ ] Invariants (PDF pp. 10, 12): busy/done rules; latched K stable while busy; exactly K valids per PE per job; accumulators zero before a job's first valid; START while busy changes nothing; done implies no product pending and stable results.
- [ ] Port the array contract from `tb/PE_Top_sva.sv`: clear one edge before array start; start lasts one cycle; start only when the array is idle.
- [ ] Gate every `$past` / `|=>` with `past_valid`; any cycle counter saturates (the `count_cycles` lesson).
- [ ] Covers: START while busy, CLEAR mid-job, K=1, K=8, back-to-back.
- Exit: `make ctrl` clean; `make ctrl COVERAGE=1` prints every COVER line; `make seeds-ctrl` 5/5 PASS.

### Task 9 (Claude): break it
- [ ] 10 mutants in a scratch copy, never the repo: token one stage early; CLEAR skipped; live K into the array; row-1 skew missing; col-1 skew missing; done as a 1-cycle pulse; busy falls a cycle before capture; START while busy restarts; C01/C10 captured swapped; CLEAR doesn't kill the token.
- [ ] Table: mutant → check that fired, or "missed" + why.
- Exit: ≥ 8/10 caught; each miss gets a test or a written reason; table + status into `docs/ROADMAP.md`; `CLAUDE.md` current stage → 6.

## Done when (Days 3–4)
- Exits of Tasks 5–9 all hold, `make pe` / `make top` still PASS, and the `SPEC.md` controller rows match the RTL.
- Only then day 5 (buffers). PDF rule: don't start the next block before this one exits.

## Traps from your code
- K=0 → `PE_Top` does nothing → no token → busy forever.
- `PE_Top` latches K at its own start, which now comes after CLEAR → the controller must hold K from START.
- `PE` forwarding registers hold during clear; safe only because the valids clear → the token must clear the same way.
- The step index can point past K−1 when nothing issues → the operand source must tolerate it.
- Verilator is 2-state [X becomes 0]: init bugs show up only in random-init seeds plus result checks.
- Every wait for done needs the watchdog, or a lost token hangs the sim instead of failing it.

## Verification (end to end)
- `make ref` → `PASS: ref model self-test`
- `make pe` / `make top` → PASS, `FINAL C = {19, 22, 43, 50}`
- `make ctrl` (+ `SEED=2..5`, `COVERAGE=1`) → `SCOREBOARD: ≥800 jobs, 0 mismatches`, COVER lines printed
- `make seeds-ctrl` → 5/5 PASS
- `make lint` → only the 3 known warnings; `make synth` → no latch cells, flop delta reported
- Kill list ≥ 8/10, table in `docs/ROADMAP.md`

## Next
- Claude: rest of Task 1 (ROADMAP + CLAUDE.md sync) and Task 4 (ref model), once you say go.
- You: spec notes for Task 2.
