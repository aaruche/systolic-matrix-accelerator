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


endmodule