# MiniMat roadmap: verification-first

Updated 2026-11-12. Replaces the 2-week Tiny Tapeout plan (and `docs/plans/2026-10-20-spec-controller.md`).

## Why the change
- You're starting as an Infineon Verification Engineering Trainee. The posting asks for:
  - SystemVerilog **UVM** testbenches
  - debugging failing tests
  - judging when verification is complete
  - basic **Python**
- So MiniMat becomes a verification training ground. Claude plays the designer: spec + most RTL, with hidden bugs. You play the verification engineer.
- Tiny Tapeout is deferred until after verification closes.

## Roles

| | You (verification engineer) | Claude (designer) |
|---|---|---|
| Spec | Review it, challenge gaps | Write `docs/SPEC.md` |
| RTL | Controller FSM; SPI synchronizers + edge detect | Everything else, with 1-3 medium/low hidden bugs per block |
| Verification | vPlan, testbenches, ref model, scoreboard, SVA, UVM, coverage, Python regression script | Reviews your logic, fills in syntax only after review, mutation-tests your TB |
| Infra | - | Makefile, EDA Playground bundle, docs |

- Hidden bugs:
  - Sealed on branch `sealed/bug-list`. Don't open it.
  - Each bug you find gets a bug report (template below). Claude confirms a bug only once you've named the root cause.
  - Full reveal at the end of each phase; anything missed becomes a lesson, and Claude adds a test idea for it.
- Tools:
  - Verilator (local) for block-level SystemVerilog tests and SVA.
  - EDA Playground (browser) for UVM and covergroups [functional coverage bins]: pick a commercial simulator there with UVM 1.2.

## Where you are
- Done (yours):
  - PE RTL + SVA.
  - `PE_Top` RTL (2x2 array + issue counter) + SVA (protocol, reset/clear, valid delay, counter, S+K+3 drain).
  - Make flow; directed K=2 self-check passes.
- Open, from before (folded into Phase 2): `count_cycles` wrap, first-edge `$past` failures, no reference model, kill list 4/10.
- Not started: spec, controller, buffers, command layer, SPI, top, any UVM.

## Phases

### Phase 0: spec + verification plan
- Claude: `docs/SPEC.md`.
  - Math, widths, timing, every SPI command, every error case.
  - STATUS bits, reset behaviour, an outcome table (command × IDLE/BUSY/DONE).
  - Decisions taken from the PDF; flagged where Claude picked.
- You: `docs/VPLAN.md` [verification plan]. Spec section → feature → how it's checked (test / assertion / coverage point) → done criteria.
- You learn: reading a spec like a verifier; testpoints; "done" = every vPlan row closed. This is the posting's "when is verification complete".
- Exit: every spec rule maps to at least 1 vPlan row; you and Claude agree there are no spec gaps.

### Phase 1: controller (your RTL) + block testbench on Verilator
- Claude: adds the completion token [marker bit riding the real pipeline] to `PE_Top`. No bugs planted in your files.
- You:
  - Controller FSM: IDLE → CLEAR → ISSUE → DRAIN → DONE, busy, sticky done, result registers, row-1/col-1 skew.
  - Self-checking TB: reference model [plain matrix math], scoreboard, constrained-random jobs (K 1-8, -128/127/0/-1, back-to-back, mid-job clear/reset), watchdog [fails a hung job].
  - FSM SVA: legal transitions, busy/done rules, K stable while busy.
  - Cover properties for every state and arc.
- You learn: self-checking TBs, reference-model independence, constrained random + seeds, FSM coverage, SVA for protocols.
- Exit: ≥800 random jobs, 0 mismatches, 5 seeds; every FSM state/arc covered; Claude's mutation run catches ≥8/10.

### Phase 2: operand buffer + command layer (Claude's RTL, hidden bugs)
- Claude: `operand_buffer` + `command_ctrl` RTL from the spec.
- You:
  - Block TBs for both.
  - Find the bugs; write a bug report for each.
  - Triage every failure [decide: RTL bug, TB bug, or spec bug].
- You learn: verifying someone else's RTL, debug from waveform to root cause, bug reports, triage.
- Exit: reveal; ≥ all-but-one bug found; fixes re-verified by your regression.

### Phase 3: SPI slave + first UVM agent (EDA Playground)
- You: synchronizers + edge detect RTL.
- Claude: shift register, byte framing, MISO path, with hidden bugs.
- You build a UVM SPI agent: sequence item, sequencer, driver, monitor, agent, config object; plus a tiny env + test.
- Stimulus: random SCLK phase and ratio, byte gaps, CS aborts.
- You learn: UVM components and phases, TLM [transaction-level] analysis ports, config_db, factory overrides.
- Exit: agent drives and monitors byte transactions; SPI bugs found; reveal.

### Phase 4: full-chip UVM environment (EDA Playground)
- Claude: `minimat_top` (SPI → command → buffers → controller → array), with a few integration bugs.
- You:
  - UVM env: SPI agent + predictor [ref model in UVM] + scoreboard + covergroups (K, signs, extremes, every command, every error, FSM states).
  - Sequences: load/start/status/read, error sequences, virtual sequence.
  - Tests: smoke, random, errors, reset.
  - A Python script that runs or parses many seeds and summarises pass/fail + coverage.
- You learn: env/test layering, sequences, coverage-driven closure, regressions, Python for verification.
- Exit:
  - 1000+ random jobs across seeds, 0 unexplained failures.
  - Coverage goals in the vPlan met, or each hole explained in writing.
  - Final reveal.

### Phase 5 (later): Tiny Tapeout
- Claude: TT wrapper, `info.yaml`, GitHub Actions hardening.
- You: gate-level sim [run the synthesized netlist] with a compact regression from Phase 4.
- Start only after Phase 4 exits and all seeded bugs are fixed.

## Bug report template (`docs/bugs/BUG-NNN.md`)
- Title, block, seed / test name
- Symptom (what you saw, which check fired, sim time)
- Expected per spec (section number)
- Root cause (signal / line / cycle)
- Classification: RTL, TB, or spec
- Fix verified by (test/regression)

## Kill list carried over (`PE_Top`, 10 one-line bugs)
- Caught today: v11 early, issuing never falls (assertions); PE10/PE11 wiring (K=2 self-check). 4/10.
- Still missed (needs Phase 1 stimulus + ref model): clear mid-wave, live K, unsigned multiply, 15-bit product, clear keeps product-valid. Start-without-count-reset is hidden by the clear-before-start rule.
