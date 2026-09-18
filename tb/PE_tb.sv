`timescale 1ns/1ps

module PE_tb;

    // DUT inputs driven by the testbench
    logic clk;
    logic rst_n;
    logic pe_valid;
    logic accum_clr;

    logic signed [7:0] A;
    logic signed [7:0] B;

    // DUT outputs observed by the testbench
    wire signed [31:0] C;
    wire signed [7:0]  A_forw_op;
    wire signed [7:0]  B_forw_op;

    // Device Under Test
    PE dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .pe_valid   (pe_valid),
        .A          (A),
        .B          (B),
        .C          (C),
        .accum_clr  (accum_clr),
        .A_forw_op  (A_forw_op),
        .B_forw_op  (B_forw_op)
    );

    // 10 ns clock period
    initial begin
        clk = 1'b0;
    end

    always #5 clk = ~clk;

    // Basic directed stimulus
    initial begin
        // Safe initial values
        rst_n     = 1'b0;
        pe_valid  = 1'b0;
        accum_clr = 1'b0;
        A         = 8'sd0;
        B         = 8'sd0;

        // Synchronous reset across two rising clock edges
        repeat (2) @(posedge clk);

        // Deassert reset away from the active sampling edge
        @(negedge clk);
        rst_n = 1'b1;

        // Idle cycle
        @(negedge clk);
        pe_valid = 1'b0;

        // Clear before starting a new operation
        @(negedge clk);
        accum_clr = 1'b1;

        @(negedge clk);
        accum_clr = 1'b0;

        // First valid operand pair
        pe_valid = 1'b1;
        A        = 8'sd3;
        B        = -8'sd2;

        // Second valid operand pair
        @(negedge clk);
        pe_valid = 1'b1;
        A        = -8'sd4;
        B        = 8'sd5;

        // Bubble containing intentionally dangerous data
        @(negedge clk);
        pe_valid = 1'b0;
        A        = 8'sd99;
        B        = 8'sd99;

        // Additional drain cycle
        @(negedge clk);
        pe_valid = 1'b0;

        // Clear the completed result
        @(negedge clk);
        accum_clr = 1'b1;

        @(negedge clk);
        accum_clr = 1'b0;

//------------------------------------

        // Create a pending product
        @(negedge clk);
        pe_valid  = 1'b1;
        accum_clr = 1'b0;
        A         = 8'sd6;
        B         = 8'sd7;

        // Clear the pending product while another valid pair is presented
        @(negedge clk);
        accum_clr = 1'b1;
        pe_valid  = 1'b1;
        A         = 8'sd2;
        B         = 8'sd9;

        // Accept a new pair before testing reset during activity
        @(negedge clk);
        accum_clr = 1'b0;
        pe_valid  = 1'b1;
        A         = 8'sd3;
        B         = 8'sd4;

        // Assert synchronous reset with a product still pending
        @(negedge clk);
        rst_n    = 1'b0;
        pe_valid = 1'b0;

        // Hold reset across two rising clock edges, then release it
        repeat (2) @(negedge clk);
        rst_n = 1'b1;
        A     = 8'sd0;
        B     = 8'sd0;

        // Allow the simulation to continue briefly
        repeat (2) @(posedge clk);

        $finish;
    end

    // Optional waveform generation
    initial begin
        $dumpfile("PE_tb.vcd");
        $dumpvars(0, PE_tb);
    end

    /*
     * Add your SVA properties here.
     *
     * Public DUT signals:
     *   rst_n, pe_valid, accum_clr
     *   A, B, C, A_forw_op, B_forw_op
     *
     * Internal DUT state can currently be observed using:
     *   dut.mult_reg
     *   dut.mult_valid_reg
     *   dut.accum_reg
     *   dut.A_forw_reg
     *   dut.B_forw_reg
     */
     
`include "PE_sva.sv"



endmodule