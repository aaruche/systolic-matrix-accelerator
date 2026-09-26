# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Working agreement
- The user writes all RTL, SVA and testbench logic. Claude is the supervisor: review, run, try to break it (mutation tests), set exit criteria.
- Never give RTL/SVA/TB code, pseudocode or signal-level fixes. Conceptual explanations only when asked.
- Claude may edit repo infrastructure only: build scripts/Makefile, .gitignore, docs, CLAUDE.md. Experiments on RTL/TB go in a scratch copy, never the repo.
- Reply style: terse bullets, no paragraphs. Put a short explanation in brackets after a technical term, e.g. bind [attach a checker module to an RTL module].

## Project
- MiniMat: 2x2 signed INT8 output-stationary systolic MAC array, SPI-controlled, planned flow RTL → GDSII.
- Specs and 14-stage roadmap: `Doc/minimat_project_overview.pdf`, `Doc/minimat_introductory_lecture.pdf` (read with `pdftotext`).
- Current stage: 5 (four-PE array). Stage 3 (independent reference model + scoreboard [compares DUT results against plain math]) is not done yet.
- No spec doc in the repo; the only cycle table is the header of `src/PE_Top.v`.

## Commands (run from repo root)
- No single entry point yet (no Makefile). `COMMANDS.md` uses paths from the user's machine (`/home/h1jda/aaru_sama/MiniMat`); read them as the repo root.
- PE unit test:
  ```
  verilator --binary --timing --assert --trace --timescale 1ns/1ps -Wno-fatal -Itb --top-module PE_tb --Mdir obj_dir_wave tb/PE_tb.sv src/PE.v
  ./obj_dir_wave/VPE_tb
  ```
- Array test (expected output `FINAL C = {19, 22, 43, 50}`):
  ```
  verilator --binary --timing --assert --trace --timescale 1ns/1ps -Wno-fatal -Itb --top-module PE_Top_tb --Mdir obj_dir_top_wave tb/PE_Top_tb.sv src/PE_Top.v src/PE.v
  ./obj_dir_top_wave/VPE_Top_tb
  ```
- Never list `tb/*_sva.sv` on the command line; the TB includes them (`-Itb`).
- Running a sim writes its VCD into the current directory. `PE_tb.vcd` is tracked, so run from a scratch dir to avoid dirtying the tree.
- Lint: `verilator --lint-only -Wall --top-module PE_Top src/PE_Top.v src/PE.v`. Known warnings: EOFNEWLINE on both src files, WIDTHEXPAND at `PE.v:83`.
- Covers: add `--coverage-user` at build time, otherwise cover properties are silently dropped.
- See every assertion failure: run with `+verilator+error+limit+100` (default stops at the first `$error`).
- Random power-up state: build with `--x-assign unique --x-initial unique`, run with `+verilator+rand+reset+2 +verilator+seed+N`.
- Waves: `gtkwave PE_tb.vcd` / `gtkwave PE_Top_tb.vcd`. `PE_Top_tb.vcd.gtkw` holds an absolute path from the user's machine.
- Storage/latch check: `yosys -p "read_verilog src/PE.v src/PE_Top.v; synth -top PE_Top; stat"` (currently only `$_SDFF*` flops, no latches).
- The user runs Verilator 5.032; the cloud container has 5.020.

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
  - Testbenches drive inputs on negedge and do not self-check yet (no PASS/FAIL; exit code always 0).
  - `PE_sva.sv` and `PE_Top_sva.sv` are include fragments [no module wrapper; they use `dut.*` hierarchical paths and the TB's localparams]. They must be `` `include ``d inside the TB module.
  - `PE_sva.sv` is included by `PE_tb.sv`.
  - `PE_Top_sva.sv` is NOT compiled: its only `` `include `` sits inside a `/* */` comment in `PE_Top_tb.sv`.
- `Sim_img/`: reference waveform screenshots.

## Verification traps (confirmed)
- Verilator is two-state [X becomes 0], so `$isunknown` never fires. Catch X with random-init runs plus a result check.
- `$past` / `|=>` on the first clock edge have no real history. Random-init runs can false-fail reset properties there.
- A checker compared against a DUT register inherits that register's width [Verilog sizes expressions by context]. Use independent widths or a reference model.
- Mutation testing [plant one bug, confirm a check fails, restore] is the acceptance test. As of commit `bb2859c`, 0 of 10 planted bugs were caught by assertions.

## Repo hygiene
- Build outputs are committed: `obj_dir_top_wave/`, `PE_tb.vcd`, `coverage.dat`. `.gitignore` does not cover `obj_dir_top_wave/`.
- Removing them needs `git rm --cached`; ask the user first.
