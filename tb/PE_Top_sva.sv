localparam logic [K_WIDTH-1:0] MAX_SUPPORTED_K = 8;

// ---------------------------------------------------------
// Helpful white-box status expressions
// ---------------------------------------------------------

wire controller_cleared;
wire pe_state_cleared;
wire results_cleared;
wire array_idle;

assign controller_cleared =
    (dut.issuing        == 1'b0) &&
    (dut.accepted_count == '0)   &&
    (dut.active_K       == '0)   &&
    (dut.valid_delay_1  == 1'b0) &&
    (dut.valid_delay_2  == 1'b0) &&
    ({dut.v00, dut.v01, dut.v10, dut.v11} == 4'b0000);

assign pe_state_cleared =
    (dut.PE00.mult_valid_reg == 1'b0) &&
    (dut.PE01.mult_valid_reg == 1'b0) &&
    (dut.PE10.mult_valid_reg == 1'b0) &&
    (dut.PE11.mult_valid_reg == 1'b0) &&

    (dut.PE00.accum_reg == '0) &&
    (dut.PE01.accum_reg == '0) &&
    (dut.PE10.accum_reg == '0) &&
    (dut.PE11.accum_reg == '0);

assign results_cleared =
    (C00 == '0) &&
    (C01 == '0) &&
    (C10 == '0) &&
    (C11 == '0);

// An old result may remain in accum_reg and C while idle.
// Only active validity and pending products prevent a new start.
assign array_idle =
    !dut.issuing       &&
    !dut.valid_delay_1 &&
    !dut.valid_delay_2 &&

    !dut.PE00.mult_valid_reg &&
    !dut.PE01.mult_valid_reg &&
    !dut.PE10.mult_valid_reg &&
    !dut.PE11.mult_valid_reg;


// =========================================================
// 1. PROTOCOL ASSERTIONS
// =========================================================

// start may be high for only one sampled clock.
property p_start_one_clock;
    @(posedge clk)
    disable iff (!rst_n)
    start |=> !start;
endproperty

a_start_one_clock:
    assert property (p_start_one_clock)
    else $error("start remained high for more than one clock");


// Clear and start must use separate clock edges.
property p_start_clear_no_overlap;
    @(posedge clk)
    disable iff (!rst_n)
    !(start && accum_clr);
endproperty

a_start_clear_no_overlap:
    assert property (p_start_clear_no_overlap)
    else $error("start and accum_clr were asserted together");


// This implements your comment that clear must occur before start.
// It specifically means the immediately preceding sampled edge.
property p_start_follows_clear;
    @(posedge clk)
    disable iff (!rst_n)
    start |-> $past(accum_clr);
endproperty

a_start_follows_clear:
    assert property (p_start_follows_clear)
    else $error("start was not preceded by an accum_clr edge");


// No restart while an earlier wave or product remains in flight.
property p_start_only_when_idle;
    @(posedge clk)
    disable iff (!rst_n)
    start |-> array_idle;
endproperty

a_start_only_when_idle:
    assert property (p_start_only_when_idle)
    else $error("start occurred before the previous operation drained");


// K=0 is illegal in this version.
// Change MAX_SUPPORTED_K if your specification supports another maximum.
property p_legal_K_on_start;
    @(posedge clk)
    disable iff (!rst_n)
    start |-> (
        !$isunknown(K) &&
        K != '0        &&
        K <= MAX_SUPPORTED_K
    );
endproperty

a_legal_K_on_start:
    assert property (p_legal_K_on_start)
    else $error("K was unknown, zero, or outside the supported range");


// ---------------------------------------------------------
// Operand known-value properties
// ---------------------------------------------------------

property p_PE00_operands_known;
    @(posedge clk)
    disable iff (!rst_n)
    dut.v00 |-> !$isunknown({A_row0, B_col0});
endproperty

a_PE00_operands_known:
    assert property (p_PE00_operands_known)
    else $error("PE00 received unknown operands while valid");


property p_PE01_operands_known;
    @(posedge clk)
    disable iff (!rst_n)
    dut.v01 |->
        !$isunknown({dut.A_PE00_to_PE01, B_col1});
endproperty

a_PE01_operands_known:
    assert property (p_PE01_operands_known)
    else $error("PE01 received unknown operands while valid");


property p_PE10_operands_known;
    @(posedge clk)
    disable iff (!rst_n)
    dut.v10 |->
        !$isunknown({A_row1, dut.B_PE00_to_PE10});
endproperty

a_PE10_operands_known:
    assert property (p_PE10_operands_known)
    else $error("PE10 received unknown operands while valid");


property p_PE11_operands_known;
    @(posedge clk)
    disable iff (!rst_n)
    dut.v11 |->
        !$isunknown({
            dut.A_PE10_to_PE11,
            dut.B_PE01_to_PE11
        });
endproperty

a_PE11_operands_known:
    assert property (p_PE11_operands_known)
    else $error("PE11 received unknown operands while valid");


// =========================================================
// 2. RESET AND CLEAR ASSERTIONS
// =========================================================

// Do not use disable iff here: reset is the event being checked.
property p_reset_clears_array;
    @(posedge clk)
    !rst_n |=> (
        controller_cleared &&
        pe_state_cleared   &&
        results_cleared
    );
endproperty

a_reset_clears_array:
    assert property (p_reset_clears_array)
    else $error("Reset failed to clear controller, PE, or result state");


// Reset may disable this property because reset has higher priority.
property p_accum_clear_clears_array;
    @(posedge clk)
    disable iff (!rst_n)
    accum_clr |=> (
        controller_cleared &&
        pe_state_cleared   &&
        results_cleared
    );
endproperty

a_accum_clear_clears_array:
    assert property (p_accum_clear_clears_array)
    else $error("accum_clr failed to clear controller, PE, or result state");