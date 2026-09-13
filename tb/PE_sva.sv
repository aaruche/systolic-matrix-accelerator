

// reset properties 
property rst_n_property;
    @(posedge clk)
    !rst_n |=> (
        dut.A_forw_reg      == 8'b0  &&
        dut.B_forw_reg      == 8'b0  &&
        dut.mult_reg        == 16'b0 &&
        dut.mult_valid_reg  == 1'b0  &&
        dut.accum_reg       == 32'b0
    );
endproperty

assert(rst_n_property) 
    else   $error("Reset Operation Failed miserably like your love life"); ; 


// forwarding properties 
property forwarding_property;
    @(posedge clk)
    disable iff (!rst_n)
    (pe_valid && !accum_clr)|=> 
    (
        dut.A_forw_reg == $past(A) &&
        dut.B_forw_reg == $past(B)
    );
endproperty

a_forwarding: assert property (forwarding_property)
    else $error("Operand forwarding property failed");