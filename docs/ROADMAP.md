# MiniMat roadmap

Target: a **Tiny Tapeout** chip in **~2 weeks**. Status checked against `main` at `6c4e789`.

The Codex 14-stage plan is the right order (it follows the project overview PDF). With 2 weeks, stages are merged and optional work is cut; the order stays the same.

## Where you are (~20% of the project)

| Block | Status |
|---|---|
| PE (`src/PE.v`) | RTL + directed SVA done. No random test yet. |
| 2x2 array + issue counter (`src/PE_Top.v`) | RTL done. SVA done for protocol, reset/clear, valid delay, counter, S+K+3 drain. Only one directed K=2 job. |
| Reference model + scoreboard | Not started |
| Controller (IDLE/CLEAR/ISSUE/DRAIN/DONE, busy, done) | Not started (only the issue counter exists) |
| Operand buffers | Not started |
| Command layer | Not started |
| SPI slave | Not started |
| Tiny Tapeout top + full-chip TB | Not started |
| Hardening (GDS) | Not started |

### Kill list (10 planted one-line bugs, run against `main` SVA)

| Bug | Caught by |
|---|---|
| v11 one cycle early | `a_v11_tracks_v01` |
| issuing never falls | `a_array_drains_by_SK3`, `a_issuing_bounded_deassert` |
| PE10 B wired to boundary | wrong C only (needs a result check) |
| PE11 A from wrong neighbour | wrong C only (needs a result check) |
| clear forgets 2nd delay stage | nothing (needs clear mid-wave) |
| live K instead of latched K | nothing (needs K changed after start) |
| start doesn't reset the count | nothing (hidden by the clear-before-start rule) |
| unsigned multiply | nothing (needs negative operands) |
| 15-bit product register | nothing (needs -128 x -128 + a reference model) |
| clear keeps product-valid | nothing (needs clear while a product is in flight) |

- Assertions: 2/10. The K=2 self-check in `tb/PE_Top_tb.sv` adds the two wiring bugs: 4/10.
- Target before moving on: >= 8/10. #7 may stay "harmless by protocol" if written down.

### Open bugs in the checker (yours to fix)

- `count_cycles` in `tb/PE_Top_sva.sv` wraps after 512 cycles. `a_issuing_window_width` then false-fires (count=1, K=2 seen about 512 cycles after start). Any long random run will hit it. Make it saturate instead of wrap.
- `a_reset_clears_array` fails at the first clock edge on 2 of 5 random power-up seeds (`make seeds-top`). Gate it with `past_valid` (the TB now provides it).
- A 1-cycle reset in the middle of a wave will likely false-fire `a_v11_tracks_v01` / `a_v01_v10_track_v00`: they only disable on `$past(accum_clr)`, not on reset in the previous cycle. Decide whether a 1-cycle reset is legal.

## 2-week plan

Split: you write RTL + property logic; Claude does TB plumbing, harness, scoreboard, Makefile, docs, TT config, and reviews / breaks your code.

| Days | Work | Exit |
|---|---|---|
| 1-2 | Close the compute core: reference model [plain triple-loop math] + scoreboard [compares every C]; random PE_Top jobs (K 1-8, -128/127/0/-1, garbage in bubble cycles, K changed after start, clear/reset mid-job, back-to-back); fix the two checker bugs above | >= 500 random jobs pass; kill list >= 8/10 |
| 2 | `docs/SPEC.md` (1 page): SPI table from the PDF p.9; decide K=0/K>8, START while busy, sticky DONE, LOAD overwrite, READ_C before done | No "TBD" left |
| 3 | **Trial harden PE_Top** in the TT flow to learn the tile count (Yosys already shows ~3k cells for PE_Top alone; expect a multi-tile design) | Area known |
| 3-4 | Controller: IDLE -> CLEAR -> ISSUE -> DRAIN -> DONE; busy, sticky done; completion token [valid bit that travels the real pipeline, not a guessed count]; generates the row1/col1 data skew | All K pass through the controller |
| 5 | Operand buffers: A 2x8 bytes, B 8x2 bytes; write port, read by k, locked while busy, A_loaded/B_loaded | Repeated jobs, no stale data |
| 6-7 | Command layer: byte in -> opcode -> payload count -> action; STATUS; READ_C 16 bytes little-endian; error flags | Every command + error has one outcome |
| 8 | SPI slave: mode 0, 2-flop synchronizers [make async pins safe], edge detect, system clk >= 6x SCLK, CS framing, abort | Random phase/gaps/aborts pass |
| 9 | TT top `tt_um_*` (SPI on `ui_in`/`uo_out`, unused outputs tied 0) + full-chip TB with an SPI driver | Load -> start -> status -> read passes |
| 10-11 | Verification closure (cut-down): 1000 random matrices through SPI, all K, sign corners, error commands, reset mid-job; one gate-level sim [run the synthesized netlist] | 0 unexplained failures |
| 12-14 | Harden with the TT template's GitHub Actions flow (no local LibreLane); DRC/LVS/antenna clean; `info.yaml`, docs; submit | GDS accepted |

### Area lever
- Either keep separate C result registers (per the PDF), or define the accumulators as readable only while done/idle. The second option saves ~128 flops. Decide on day 2.

### Cut for 2 weeks
- Pipelined-vs-unpipelined PPA experiment.
- 50/25/20 ns clock sweep: close timing at one clock instead (e.g. 20-25 MHz).
- Heavy functional coverage.
- Splitting the array from the issue counter.

### Check yourself
- The current TT shuttle deadline, and tile sizes/prices. These change per shuttle.
