// reset properties
property rst_n_property;
    @(posedge clk)
    !rst_n |=> (
        dut.A_forw_reg       == 8'b0  &&
        dut.B_forw_reg       == 8'b0  &&
        dut.mult_reg         == 16'b0 &&
        dut.mult_valid_reg   == 1'b0  &&
        dut.accum_reg        == 32'b0
    );
endproperty

assert property (rst_n_property)
    else $error("Reset operation failed");


// forwarding properties
property forwarding_property;
    @(posedge clk)
    disable iff (!rst_n)
    (pe_valid && !accum_clr) |=>
    (
        dut.A_forw_reg == $past(A) &&
        dut.B_forw_reg == $past(B)
    );
endproperty

a_forwarding: assert property (forwarding_property)
    else $error("Operand forwarding property failed");


// Product properties
// Product clear
property product_clear_property;
    @(posedge clk)
    disable iff (!rst_n)
    accum_clr
    |=> (
        dut.mult_reg         == 16'b0 &&
        dut.mult_valid_reg   == 1'b0
    );
endproperty

a_product_clear: assert property (product_clear_property)
    else $error("Product pipeline was not cleared");


// Product Capture
property product_capture_property;
    @(posedge clk)
    disable iff (!rst_n)
    (pe_valid && !accum_clr) |=>
    (
        dut.mult_reg ==
            ($signed($past(A)) * $signed($past(B))) &&
        dut.mult_valid_reg == 1'b1
    );
endproperty

a_product_capture: assert property (product_capture_property)
    else $error("Product capture failed");


// Product dealing with Bubble (pe_valid = 0)
property product_bubble_property;
    @(posedge clk)
    disable iff (!rst_n)
    (!pe_valid && !accum_clr)
    |=> (
        dut.mult_valid_reg == 1'b0
    );
endproperty

a_product_bubble: assert property (product_bubble_property)
    else $error("Product-valid was not cleared after a bubble");


// Accumulation Stage

// Product Valid high
property p_valid_product_accumulates;
    @(posedge clk)
    disable iff (!rst_n)
    (!accum_clr && dut.mult_valid_reg)
    |=> dut.accum_reg ==
        ($past(dut.accum_reg) + $past(dut.mult_reg));
endproperty

assert property (p_valid_product_accumulates)
    else $error("Accumulator did not add the previous valid product");


// Product reg when accum_clr is high
property p_clear_accumulator;
    @(posedge clk)
    disable iff (!rst_n)
    accum_clr |=> (dut.accum_reg == '0);
endproperty

assert property (p_clear_accumulator)
    else $error("Accumulator was not cleared");


// Accumulator holds when the registered product is invalid
property p_invalid_product_holds_accumulator;
    @(posedge clk)
    disable iff (!rst_n)
    (!dut.mult_valid_reg && !accum_clr)
    |=> $stable(dut.accum_reg);
endproperty

a_invalid_product_holds_accumulator:
    assert property (p_invalid_product_holds_accumulator)
    else $error("Accumulator changed without a valid product");


// Forwarding registers hold when forwarding is disabled
property forwarding_hold_property;
    @(posedge clk)
    disable iff (!rst_n)
    (accum_clr || !pe_valid) |=>
    (
        $stable(dut.A_forw_reg) &&
        $stable(dut.B_forw_reg)
    );
endproperty

a_forwarding_hold: assert property (forwarding_hold_property)
    else $error("Forwarding registers changed while forwarding was disabled");

// External forwarding outputs match their corresponding registers
property forwarding_outputs_property;
    @(posedge clk)
    disable iff (!rst_n)
    (
        A_forw_op == dut.A_forw_reg &&
        B_forw_op == dut.B_forw_reg
    );
endproperty

a_forwarding_outputs: assert property (forwarding_outputs_property)
    else $error("Forwarding outputs do not match their registers");


// C matches the accumulator register
property accumulator_output_property;
    @(posedge clk)
    disable iff (!rst_n)
    C == dut.accum_reg;
endproperty

a_accumulator_output: assert property (accumulator_output_property)
    else $error("C does not match the accumulator register");

//==========================================================


// Coverage: a valid pair followed by a bubble
c_valid_then_bubble: cover property (
    @(posedge clk)
    disable iff (!rst_n)
    $past(rst_n && pe_valid && !accum_clr) &&
    !pe_valid && !accum_clr
) $display("COVER: valid pair followed by a bubble at %0t", $time);


// Coverage: two consecutive accepted operand pairs
c_consecutive_valid: cover property (
    @(posedge clk)
    disable iff (!rst_n)
    $past(rst_n && pe_valid && !accum_clr) &&
    pe_valid && !accum_clr
) $display("COVER: consecutive valid pairs at %0t", $time);


// Coverage: clear while a registered product is pending
c_clear_pending_product: cover property (
    @(posedge clk)
    disable iff (!rst_n)
    accum_clr && dut.mult_valid_reg
) $display("COVER: clear with a pending product at %0t", $time);


// Coverage: clear and pe_valid asserted together
c_clear_and_valid: cover property (
    @(posedge clk)
    disable iff (!rst_n)
    accum_clr && pe_valid
) $display("COVER: clear and pe_valid together at %0t", $time);


// Coverage: reset immediately after accepting a pair, with a product pending
// Do not disable this cover during reset: reset is the event being observed.
c_reset_during_activity: cover property (
    @(posedge clk)
    !rst_n &&
    $past(rst_n && pe_valid && !accum_clr) &&
    dut.mult_valid_reg
) $display("COVER: reset during activity at %0t", $time);