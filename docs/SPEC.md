# MiniMat v1 specification

Status: draft 1 (2026-11-12), written by Claude for review.
- Source: `Doc/minimat_project_overview.pdf` (pp. 4, 6-7, 9-10, 12) plus the existing `src/PE.v` / `src/PE_Top.v`.
- **[PICK]** marks a decision the PDF leaves open; Claude chose it. Challenge any of them.
- Every rule has an ID (e.g. `CMD-5`). The vPlan traces to these IDs.

---

## 1. Scope

- **SCOPE-1** MiniMat computes one 2x2 output tile C = A x B, where A is 2xK, B is Kx2, and K = 1..8.
- **SCOPE-2** A host loads K, A and B over SPI, starts the job, polls STATUS, and reads C over SPI.
- **SCOPE-3** v1 does **not** support:
  - K > 8, or tiling larger matrices on-chip
  - double buffering [loading the next job while one runs]
  - saturation [clamping on overflow], bias, ReLU
  - more than one clock domain
  - SPI modes other than mode 0
  - interrupts

## 2. Arithmetic

- **MATH-1** `C[i][j] = sum over k = 0..K-1 of A[i][k] * B[k][j]`, for i, j in {0, 1}.
- **MATH-2** A and B elements are two's-complement signed 8-bit (-128..127).
- **MATH-3** Each product is exact signed 16-bit. Both operands are treated as signed.
- **MATH-4** Accumulation is signed 32-bit and wraps on overflow. (For K <= 8 the largest magnitude is 8 x 16384 = 131072, so wrap is unreachable in v1; it is still the rule.)
- **MATH-5** Results are returned exactly; no rounding or truncation.

## 3. Clock and reset

- **CLK-1** One clock domain, `clk`. SPI pins are asynchronous inputs, sampled by `clk`.
- **CLK-2** **[PICK]** SCLK frequency <= clk / 8. (The PDF says >= 6x; 8x leaves margin for the MISO path, see SPI-6.) Example: clk 20 MHz, SCLK <= 2.5 MHz.
- **RST-1** `rst_n` is active-low and synchronous to `clk`. While it is low for >= 2 clk edges, all state goes to its reset value.
- **RST-2** Reset values:
  - busy = 0, done = 0
  - K = 0 (meaning "not set")
  - A_loaded = B_loaded = 0
  - all buffer bytes = 0, all accumulators = 0, all result registers = 0
  - all error flags = 0
  - SPI receive state idle, MISO = 0
- **RST-3** No RTL behaviour depends on `initial` blocks or power-up values.

## 4. External pins

| Pin | Dir | Meaning |
|---|---|---|
| `clk` | in | system clock |
| `rst_n` | in | synchronous active-low reset |
| `sclk` | in | SPI clock from host |
| `cs_n` | in | SPI chip select, active low |
| `mosi` | in | host → chip data |
| `miso` | out | chip → host data |

- **PIN-1** `miso` is always driven: 0 while `cs_n` is high, and 0 wherever this spec says "0x00".
- **PIN-2** The Tiny Tapeout pin mapping is out of scope for v1 (Phase 5).

## 5. SPI transport

- **SPI-1** Mode 0 [CPOL=0, CPHA=0]: SCLK idles low; both sides sample on the SCLK rising edge; both sides change data after the falling edge.
- **SPI-2** Bytes are MSB first.
- **SPI-3** A frame [one transaction] is everything between `cs_n` falling and `cs_n` rising. One frame carries exactly one command.
- **SPI-4** Byte 0 of a frame is the opcode. Bytes 1.. are payload (writes) or response slots (reads).
- **SPI-5** Host timing the chip relies on:
  - first SCLK rise >= 4 clk after `cs_n` falls
  - `cs_n` rises >= 4 clk after the last SCLK fall
  - `cs_n` stays high >= 4 clk between frames
- **SPI-6** For read commands, response byte n is shifted out during frame byte n (n >= 1), so the host clocks a dummy byte (send 0x00) to receive each response byte. During byte 0 (the opcode), MISO = 0x00.
- **SPI-7** A frame that ends mid-byte (`cs_n` rises after 1-7 bits of a byte) has a partial byte. The partial byte is discarded. For a write command, or a partial opcode byte, this is a length error (CMD-2). For a read command after its opcode, it is allowed (CMD-3).
- **SPI-8** An empty frame (no SCLK edges) is ignored: no error, no action.

## 6. Commands

| Opcode | Name | Frame length (bytes, incl. opcode) | Response |
|---|---|---|---|
| 0x10 | SET_K | exactly 2 | none |
| 0x20 | LOAD_A | exactly 1 + 2K | none |
| 0x21 | LOAD_B | exactly 1 + 2K | none |
| 0x30 | START | exactly 1 | none |
| 0x31 | STATUS | >= 1 | 2 bytes: STATUS, ERRORS |
| 0x40 | READ_C | >= 1 | 16 bytes: C00, C01, C10, C11, each little-endian |
| 0x50 | CLEAR | exactly 1 | none |
| 0x60 | READ_ID | >= 1 | 2 bytes: 0x4D, 0x01 |

### General rules

- **CMD-1** **[PICK]** A write command (SET_K, LOAD_A, LOAD_B, START, CLEAR) takes effect only when its frame ends (`cs_n` rises) with exactly the listed length. LOAD data bytes are written into the buffer as they arrive (CMD-LOAD-3).
- **CMD-2** A write command whose frame has the wrong length (too short, too long, or a partial byte) is not executed and sets `ERR_LEN`. A partial opcode byte also sets `ERR_LEN`.
- **CMD-3** **[PICK]** Read commands (STATUS, READ_C, READ_ID) may be cut short by the host without error. Response slots past the end of the response return 0x00, also without error.
- **CMD-4** An unknown opcode sets `ERR_OPCODE`. The rest of the frame is ignored, MISO stays 0x00, and nothing else changes.
- **CMD-5** **[PICK]** Error flags are sticky: they stay set until CLEAR or reset. A new error never clears an older one.
- **CMD-6** A rejected command changes no state except setting its error flag(s).

### SET_K (0x10)

- **CMD-SETK-1** Payload byte = K. Accepted only if 1 <= K <= 8 and not busy.
- **CMD-SETK-2** K = 0 or K > 8 sets `ERR_BAD_K`; K keeps its old value.
- **CMD-SETK-3** SET_K while busy sets `ERR_BUSY`.
- **CMD-SETK-4** **[PICK]** An accepted SET_K clears A_loaded and B_loaded (the payload length of a load depends on K), even if K didn't change.
- **CMD-SETK-5** An accepted SET_K does not change done or the result registers.

### LOAD_A (0x20) / LOAD_B (0x21)

- **CMD-LOAD-1** Payload is row-major, 2K bytes:
  - LOAD_A: A[0][0..K-1], then A[1][0..K-1].
  - LOAD_B: B[0][0], B[0][1], B[1][0], B[1][1], ... B[K-1][1].
- **CMD-LOAD-2** Rejected with `ERR_NOT_READY` if K = 0 (not set); rejected with `ERR_BUSY` if busy. A rejected load writes nothing.
- **CMD-LOAD-3** **[PICK]** When an accepted LOAD_x frame begins (opcode received while idle/done and K set):
  - that matrix's loaded flag drops to 0;
  - each payload byte is written to the buffer as it arrives.
- **CMD-LOAD-4** At frame end:
  - exact length → the loaded flag goes to 1;
  - any other length → the flag stays 0 and `ERR_LEN` is set. Contents are then unspecified until the next complete load.
- **CMD-LOAD-5** A second complete load of the same matrix overwrites it.
- **CMD-LOAD-6** Buffer bytes beyond index K-1 are never used for the current K.
- **CMD-LOAD-7** Loads do not change done or the result registers.

### START (0x30)

- **CMD-START-1** Accepted only if not busy, K is set, A_loaded = 1 and B_loaded = 1.
- **CMD-START-2** START while busy sets `ERR_BUSY`, and the running job is unaffected.
- **CMD-START-3** START with K unset or either matrix not loaded sets `ERR_NOT_READY`.
- **CMD-START-4** An accepted START: done drops to 0 and busy rises to 1 within 2 clk; K is latched for the job.
- **CMD-START-5** Loaded flags stay 1 after a job, so START again re-runs the same matrices.
- **CMD-START-6** Result registers keep the previous job's values until the new job's capture (COMP-4).

### STATUS (0x31)

- **CMD-STAT-1** Response byte 1 = STATUS, byte 2 = ERRORS. It is allowed in every state and changes nothing.
- **CMD-STAT-2** STATUS byte:

| Bit | Name | Meaning |
|---|---|---|
| 0 | busy | a job is running |
| 1 | done | the last job finished and its results are in the result registers |
| 2 | k_valid | K is set (1..8) |
| 3 | a_loaded | A fully loaded for the current K |
| 4 | b_loaded | B fully loaded for the current K |
| 5 | error | OR of all ERRORS bits |
| 7:6 | - | always 0 |

- **CMD-STAT-3** ERRORS byte:

| Bit | Name | Set by |
|---|---|---|
| 0 | ERR_OPCODE | unknown opcode (CMD-4) |
| 1 | ERR_LEN | wrong frame length or partial byte (CMD-2, CMD-LOAD-4) |
| 2 | ERR_BUSY | SET_K, LOAD, START or READ_C while busy |
| 3 | ERR_NOT_READY | START without K/A/B; LOAD without K |
| 4 | ERR_BAD_K | SET_K with 0 or > 8 |
| 7:5 | - | always 0 |

- **CMD-STAT-4** STATUS reflects state as of the opcode byte's last rising SCLK edge.

### READ_C (0x40)

- **CMD-READ-1** Returns the result registers as 16 bytes: C00, C01, C10, C11, each lowest byte first.
- **CMD-READ-2** **[PICK]** READ_C while busy returns 16 bytes of 0x00 and sets `ERR_BUSY`. Busy is decided at the opcode byte. So a READ_C frame never mixes bytes from two jobs.
- **CMD-READ-3** Before the first completed job after reset/CLEAR, READ_C returns all zeros.
- **CMD-READ-4** READ_C does not change done.

### CLEAR (0x50)

- **CMD-CLR-1** **[PICK]** An accepted CLEAR puts every architectural state back to its reset value (RST-2), in every state, including busy. A running job is aborted and must never later raise done or change the result registers.
- **CMD-CLR-2** CLEAR is never rejected (except for wrong length, CMD-2).

### READ_ID (0x60)

- **CMD-ID-1** Returns 0x4D ('M'), then 0x01 (revision 1). Allowed in every state; changes nothing.

### Outcome table (one outcome per cell)

| Command | IDLE (not busy, not done) | BUSY | DONE (not busy, done = 1) |
|---|---|---|---|
| SET_K legal | K set, loaded flags cleared | ERR_BUSY | K set, loaded flags cleared, done stays 1 |
| SET_K 0 or > 8 | ERR_BAD_K | ERR_BUSY only (busy is checked first) **[PICK]** | ERR_BAD_K |
| LOAD_A / LOAD_B | load (ERR_NOT_READY if K unset) | ERR_BUSY | load, done stays 1 |
| START | start if ready, else ERR_NOT_READY | ERR_BUSY | start if ready (done → 0), else ERR_NOT_READY |
| STATUS | response | response | response |
| READ_C | results (zeros if no job yet) | 16 x 0x00 + ERR_BUSY | results |
| CLEAR | reset state | abort + reset state | reset state |
| READ_ID | ID | ID | ID |
| unknown | ERR_OPCODE | ERR_OPCODE | ERR_OPCODE |

## 7. Compute behaviour

- **COMP-1** K is latched at an accepted START and used for the whole job. SET_K/LOAD are rejected while busy (CMD-SETK-3, CMD-LOAD-2), so buffers and K are stable from START to done.
- **COMP-2** All four accumulators are zero before the first valid product of a job.
- **COMP-3** Each PE performs exactly K multiply-accumulates per job, pairing A[i][k] with B[k][j] for the same k.
- **COMP-4** The result registers are loaded exactly once per job, after the last product has been accumulated in all four PEs, from the accumulators.
- **COMP-5** Completion comes from a token [a marker that travels with the last valid data through the real pipeline], never from a cycle count.
- **COMP-6** The result registers load, done rises and busy falls on the same clk edge.
- **COMP-7** done is sticky: it stays 1 until an accepted START or CLEAR, or reset.
- **COMP-8** **[PICK]** Latency: done rises exactly `K + L_CTRL` clk cycles after the controller receives start. `L_CTRL` is a constant set by the controller design, written in its header, and <= 10.
- **COMP-9** Result registers never change while done = 1.

## 8. Blocks and internal interfaces

| Block | Owner | Responsibility |
|---|---|---|
| `PE` | user (done) | signed multiply, product register, 32-bit accumulate, forward A right / B down |
| `PE_Top` | user (done) + Claude extension | 2x2 PEs, issue counter, valid delay chain; Claude adds the completion token |
| controller | **user** | IDLE → CLEAR → ISSUE → DRAIN → DONE, busy/done, K latch, row-1/col-1 data skew, result registers |
| `operand_buffer` | Claude | A 2x8 and B 8x2 bytes, write port, read by step k |
| `command_ctrl` | Claude | opcode decode, frame length, errors, STATUS/READ_C/READ_ID responses |
| `spi_slave` | user (synchronizers + edge detect), Claude (shift/framing/MISO) | serial bits ↔ bytes |
| `minimat_top` | Claude | wiring |

Exact port names live in each block's header; these are the contracts:

- **IF-CTRL** (command_ctrl → controller):
  - `start` is a 1-clk pulse, issued only for an accepted START.
  - `k` is stable whenever busy.
  - `abort` is a 1-clk pulse on CLEAR.
  - The controller returns `busy`, `done`, and four 32-bit results.
- **IF-BUF-RD** (controller → buffer):
  - The controller drives step index `k_idx`.
  - The buffer returns A[0][k_idx], A[1][k_idx], B[k_idx][0], B[k_idx][1] **in the same cycle** (combinational read) **[PICK]**.
- **IF-BUF-WR** (command_ctrl → buffer):
  - Write strobe, matrix select (A or B), row, column, data byte.
  - A clear input zeros all bytes.
- **IF-SPI** (spi_slave ↔ command_ctrl):
  - `frame_start` is a 1-clk pulse after `cs_n` falls.
  - `rx_valid` is a 1-clk pulse with `rx_byte` for each complete byte.
  - `frame_end` is a 1-clk pulse after `cs_n` rises, with `partial` = 1 if the frame ended mid-byte.
  - **[PICK]** command_ctrl must present the next `tx_byte` within 2 clk after `rx_valid`; spi_slave loads it before the next byte starts. Before the first `rx_valid` of a frame, `tx_byte` = 0x00.

## 9. Open items to decide in review

- Any **[PICK]** above you disagree with.
- Whether result registers stay, or the accumulators are read directly. This is an area trade-off; decide when Tiny Tapeout sizing is known (Phase 5).
