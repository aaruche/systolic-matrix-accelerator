# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Working agreement (verification-first, from 2026-11-12)
- Purpose: the user is training as a verification engineer (Infineon Verification Engineering Trainee: SystemVerilog UVM testbenches, debugging failing tests, judging when verification is complete, basic Python). MiniMat is the vehicle for learning verification.
- Roles: Claude is the designer/architect; the user is the verification engineer.
- Claude writes `docs/SPEC.md` and all remaining RTL except the user's pieces below.
- User writes RTL only for: the controller FSM, and the SPI synchronizers + edge detect. Claude reviews it and does not write it.
- Hidden bugs: Claude plants 1–3 medium-to-low difficulty bugs in each RTL block Claude writes.
  - The list lives only on branch `sealed/bug-list`. Never read it out, hint at it, or fix a seeded bug until the user files a bug report naming the root cause, or the phase-end reveal.
  - Every seeded bug is fixed (and re-verified by the user's regression) before any tapeout.
- User writes all verification: vPlan [verification plan], testbenches, reference model, scoreboard, SVA, UVM components, coverage, regression scripts (Python).
  - Claude reviews the user's logic first (right or wrong, and why). Only then may Claude fill in syntax/boilerplate for logic the user wrote. Claude invents no new checking logic.
  - Concepts are explained on request.
- Claude also owns: Makefile, the EDA Playground bundle, docs, CLAUDE.md, reviews, and mutation tests on the user's testbench (scratch copy only, never the repo).
- Existing `src/PE.v`, `src/PE_Top.v`, `tb/PE_sva.sv`, `tb/PE_Top_sva.sv` are user-written.
  - Claude may extend the two RTL files only where the spec needs it (e.g. the completion token), says so in the commit, and plants no bugs in them.
  - The two SVA files stay the user's (only harness changes, as before).
- Reply style: terse bullets, no paragraphs. Put a short explanation in brackets after a technical term, e.g. bind [attach a checker module to an RTL module].

## Project
- MiniMat: 2x2 signed INT8 output-stationary systolic MAC array, SPI-controlled, planned flow RTL → GDSII.
- Specs and 14-stage roadmap: `Doc/minimat_project_overview.pdf`, `Doc/minimat_introductory_lecture.pdf` (read with `pdftotext`).
- Plan + status: `docs/ROADMAP.md` (verification-first; Tiny Tapeout deferred). `docs/plans/2026-10-20-spec-controller.md` is superseded.
- Simulators: Verilator (local, block-level SV tests + SVA); EDA Playground (UVM, coverage; browser-based).
- No spec doc in the repo yet; Claude writes `docs/SPEC.md` first. The only cycle table today is the header of `src/PE_Top.v`.

## Commands (run from repo root)
- Entry point: `Makefile` (`make help`). Everything builds and runs under `build/` (ignored), so sims never dirty the tree.
  - `make pe` / `make top` / `make all`: build + run the PE test / array test. Array test should print `FINAL C = {19, 22, 43, 50}` and `PASS:`.
  - Options: `COVERAGE=1` (adds `--coverage-user`; without it cover properties are silently dropped), `XRAND=1 SEED=N` (random power-up state), `ERRLIMIT=N` (keep running past the first `$error`).
  - `make seeds-pe` / `make seeds-top` (`SEEDS="1 2 3 4 5"` default): random power-up run per seed, stops at the first failing seed.
  - `make lint`: `verilator -Wall`. Exits non-zero today on 3 known warnings: EOFNEWLINE on both src files, WIDTHEXPAND at `PE.v:83`.
  - `make synth`: Yosys generic synth + `stat` (currently only `$_SDFF*` flops, no latches).
  - `make wave-pe` / `make wave-top`: gtkwave on the last waves (`PE_Top_tb.vcd.gtkw` save file holds an absolute path from the user's machine).
- A `make` sim target fails if the sim exits non-zero or prints any `%Error` (log kept as `sim.log` in the build dir). `PE_Top_tb` self-checks the K=2 result (`PASS:` line, `$fatal` on mismatch); `PE_tb` has no result check yet.
- Known today: `make seeds-pe` (seed 2, `PE_sva.sv:14`) and `make seeds-top` (`a_reset_clears_array`, 2 of 5 seeds) fail at the first clock edge: a checker artifact, not an RTL bug. `PE_Top_tb` provides `past_valid` for the gate. `count_cycles` in `PE_Top_sva.sv` wraps after 512 cycles and false-fires `a_issuing_window_width` in long runs. User owns both fixes.
- Never pass `tb/*_sva.sv` to Verilator directly; the TB includes them (`-Itb`).
- `COMMANDS.md` is the user's older manual notes, with paths from their machine (`/home/h1jda/aaru_sama/MiniMat`).
- Verilator versions: the user runs 5.032; the cloud container has 5.020. On 5.020 `--binary` does not write `coverage.dat`; the covers' `$display` lines are the evidence there.

## Architecture
- `src/PE.v`: one PE.
  - A is forwarded right and B down through registers.
  - Registered 16-bit signed product with a product-valid bit feeds a 32-bit accumulator. `C` = the live accumulator (no separate result register).
  - Priority: `rst_n` > `accum_clr` > `pe_valid`. Forwarding registers hold during clear; this is safe only because PE_Top also clears the downstream valids.
- `src/PE_Top.v`: the 2x2 grid plus the issue controller in one module (roadmap Stage 5 plus part of Stage 6).
  - Controller: latches `K` on `start`, counts accepted pairs, drives `v00`.
  - Valid delay chain: `v00` → `valid_delay_1` (`v01` = `v10`) → `valid_delay_2` (`v11`).
  - Valid skew is internal; data skew is external. `A_row1`/`B_col1` must arrive one cycle after `A_row0`/`B_col0`.
  - Timing: `start` sampled at edge S → PE00 valid S+1..S+K → all `C` final after S+K+3.
  - Undefined today: K=0 (silent no-op), start while busy, when results count as "done".
- `tb/`:
  - Testbenches drive inputs on negedge.
  - `PE_sva.sv` and `PE_Top_sva.sv` are include fragments [no module wrapper; they use `dut.*` hierarchical paths and the TB's localparams]. They must be `` `include ``d inside the TB module.
  - `PE_sva.sv` is included by `PE_tb.sv`.
  - `PE_Top_sva.sv` is included at the end of `PE_Top_tb.sv`, after the harness signal `past_valid` (low until the first sampled clock edge).
- `Sim_img/`: reference waveform screenshots.

## Verification traps (confirmed)
- Verilator is two-state [X becomes 0], so `$isunknown` never fires. Catch X with random-init runs plus a result check.
- `$past` / `|=>` on the first clock edge have no real history. Random-init runs can false-fail reset properties there.
- A checker compared against a DUT register inherits that register's width [Verilog sizes expressions by context]. Use independent widths or a reference model.
- Mutation testing [plant one bug, confirm a check fails, restore] is the acceptance test. As of commit `bb2859c`, 0 of 10 planted bugs were caught by assertions.

## Repo hygiene
- Build outputs (`build/`, `obj_dir*/`, `*.vcd`, `coverage.dat`) are ignored and untracked. Keep it that way; don't commit sim outputs.
