# MiniMat command reference

Commands used during the PE simulation and SVA waveform setup. The main workflow below is for this repository, `/home/h1jda/aaru_sama/MiniMat`, and works in the VS Code integrated terminal, including fish.

## 1. Enter the repository

```bash
cd "/home/h1jda/aaru_sama/MiniMat"
```

Run the build and simulation commands from this directory so relative source paths resolve correctly and the waveform is written here.

## 2. Compile the PE and SVA testbench

```bash
verilator --binary --timing --assert --trace \
  --timescale 1ns/1ps -Wno-fatal \
  -Itb --top-module PE_tb --Mdir obj_dir_wave \
  tb/PE_tb.sv src/PE.v
```

| Option | Purpose |
| --- | --- |
| `--binary` | Build an executable simulation, including the generated C++ model. |
| `--timing` | Support testbench delays and timing controls, including the clock generator. |
| `--assert` | Enable the supported SVA checks. |
| `--trace` | Enable waveform tracing used by `$dumpfile` and `$dumpvars`. |
| `--timescale 1ns/1ps` | Supply a default timescale where the source does not specify one. |
| `-Wno-fatal` | Allow compilation to continue with warnings; errors still stop compilation. |
| `-Itb` | Search `tb` for included files. |
| `--top-module PE_tb` | Select the testbench as the simulation top. |
| `--Mdir obj_dir_wave` | Put generated build files and the executable in this directory. |

Source files:

- `src/PE.v`: your PE RTL.
- `tb/PE_tb.sv`: clock, stimulus, DUT instance, waveform dumping, and the SVA include.
- `tb/PE_sva.sv`: your existing assertions, included inside `PE_tb`.

Do not add `tb/PE_sva.sv` separately to this compile command: the testbench already includes it. The assertion file has no standalone module wrapper and no closing `endmodule`.

Recompile after editing RTL, assertions, or stimulus. Run the executable only after compilation succeeds, otherwise an old executable may still be present.

## 3. Run the simulation

```bash
./obj_dir_wave/VPE_tb
```

This runs the stimulus and enabled assertions. The existing testbench writes `PE_tb.vcd` in the current directory. Another run replaces that waveform file.

Passing assertions are normally silent. An assertion failure reports its error in the terminal. Reaching `$finish` without assertion failures means no enabled assertion failed during that particular simulation; it does not prove the design for every possible input.

The recorded successful run reached `$finish` at 120 ns. Inspection of its VCD showed:

| Time | `C` as signed decimal | Event |
| --- | --- | --- |
| 65 ns | -6 | First product, 3 × -2, accumulated. |
| 75 ns | -26 | Second product, -4 × 5, accumulated during an input bubble. |
| 95 ns | 0 | Accumulator cleared. |

## 4. Open the waveform

From the repository directory:

```bash
gtkwave PE_tb.vcd
```

Or use absolute paths from any directory:

```bash
/usr/bin/gtkwave /home/h1jda/aaru_sama/MiniMat/PE_tb.vcd
```

In GTKWave, expand `PE_tb` and `dut`, then add `clk`, `rst_n`, `accum_clr`, `pe_valid`, `A`, `B`, `A_forw_op`, `B_forw_op`, `mult_reg`, `mult_valid_reg`, and `C`. Set the arithmetic signals to Signed Decimal to read negative values.

GTKWave displays the signal transitions. The existing SVA checks report failures in the simulation terminal; they do not automatically appear as separate pass/fail waveform signals.

## 5. Launch from VS Code if GTKWave reports a Snap library error

The recorded GTKWave launch failed with:

```text
/snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0:
undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE
```

Compilation and simulation had already succeeded. This error came from launching the viewer.

The following workaround was provided for the VS Code integrated terminal:

```bash
env -u LD_LIBRARY_PATH -u LD_PRELOAD -u GTK_PATH -u GIO_MODULE_DIR /usr/bin/gtkwave /home/h1jda/aaru_sama/MiniMat/PE_tb.vcd
```

It removes those inherited environment settings only for this launch. It does not change the source code, shell configuration, or VS Code settings. GTKWave opens in a separate window. The conversation has not yet confirmed whether this workaround succeeded on your machine.

## 6. Read-only diagnostic commands used during setup

Check installed tool locations:

```bash
command -v iverilog
command -v verilator
command -v gtkwave
```

The runnable SVA workflow above uses Verilator; locating Icarus Verilog does not mean it was used for this run.

Check the Verilator version:

```bash
verilator --version
```

The recorded build used Verilator 5.032.

Inspect changed and untracked files:

```bash
git status --short
```

Inspect inherited library settings and GTKWave's linked libraries:

```bash
printenv LD_LIBRARY_PATH LD_PRELOAD GTK_PATH GIO_MODULE_DIR
ldd /usr/bin/gtkwave
```

An unset variable produces no value in the `printenv` output. The environment of a VS Code terminal can differ from that of another terminal.

Inspect the text waveform file without launching a GUI:

```bash
sed -n '1,240p' PE_tb.vcd
```

The recorded VCD declares a 1 ps timescale: for example, `#65000` means 65 ns. Signal values in this file are binary.

## 7. Synthesis status

No synthesis command has been run in this workflow yet. `verilator --binary` compiles a simulation executable; it does not synthesize the PE into a hardware netlist. Add synthesis commands here when you reach that stage.

## 8. Earlier commands from the separate prototype workspace

These commands were used earlier in `/home/h1jda/Documents/ChatGPT/custom processor`, before this MiniMat repository became the source of truth:

```bash
cd "/home/h1jda/Documents/ChatGPT/custom processor"
make pe-sva
make pe-wave
gtkwave pe_sva.vcd
```

They depend on the Makefile and filenames in that older workspace. They are recorded for reference, not as commands to run in this repository. The current MiniMat workflow is sections 1–5 above.

The older build also used `--coverage-user` for an added cover property. Your current assertions do not require that option. Its `sva_*_pending` markers and extra assertions are not part of this repository's workflow.

That earlier build encountered a generated GNU Make build-path error because its directory contained spaces; its build output was redirected to `/tmp/custom_processor_pe_sva`. The current MiniMat path has no spaces and uses `obj_dir_wave` normally.
