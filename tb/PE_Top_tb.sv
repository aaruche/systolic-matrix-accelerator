`timescale 1ns/1ps

module PE_Top_tb;

    localparam int K_WIDTH = 8;

    logic                     clk;
    logic                     rst_n;
    logic                     accum_clr;
    logic                     start;
    logic [K_WIDTH-1:0]       K;

    logic signed [7:0]        A_row0;
    logic signed [7:0]        A_row1;
    logic signed [7:0]        B_col0;
    logic signed [7:0]        B_col1;

    wire signed [31:0]        C00;
    wire signed [31:0]        C01;
    wire signed [31:0]        C10;
    wire signed [31:0]        C11;

    // Bit order matches your controller table.
    wire [3:0] local_valids = {
        dut.v00, dut.v01, dut.v10, dut.v11
    };

    PE_Top #(
        .K_WIDTH(K_WIDTH)
    ) dut (
        .clk       (clk),
        .rst_n     (rst_n),
        .accum_clr (accum_clr),
        .start     (start),
        .K         (K),

        .A_row0    (A_row0),
        .A_row1    (A_row1),
        .B_col0    (B_col0),
        .B_col1    (B_col1),

        .C00       (C00),
        .C01       (C01),
        .C10       (C10),
        .C11       (C11)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task automatic drive_cycle (
        input logic               next_start,
        input logic               next_clear,
        input logic [K_WIDTH-1:0] next_K,
        input logic signed [7:0]  next_A_row0,
        input logic signed [7:0]  next_A_row1,
        input logic signed [7:0]  next_B_col0,
        input logic signed [7:0]  next_B_col1
    );
        begin
            @(negedge clk);

            start     = next_start;
            accum_clr = next_clear;
            K         = next_K;

            A_row0 = next_A_row0;
            A_row1 = next_A_row1;
            B_col0 = next_B_col0;
            B_col1 = next_B_col1;
        end
    endtask

    initial begin
        $dumpfile("PE_Top_tb.vcd");
        $dumpvars(0, PE_Top_tb);

        rst_n     = 1'b0;
        accum_clr = 1'b0;
        start     = 1'b0;
        K         = '0;

        A_row0 = '0;
        A_row1 = '0;
        B_col0 = '0;
        B_col1 = '0;

        // Synchronous reset.
        repeat (2) @(posedge clk);

        @(negedge clk);
        rst_n = 1'b1;

        /*
         * First directed calculation:
         *
         * A = [1 2]     B = [5 6]
         *     [3 4]         [7 8]
         *
         * Expected C = [19 22]
         *              [43 50]
         */

        // Dedicated clear edge.
        drive_cycle(
            1'b0, 1'b1, 8'd0,
            8'sd0, 8'sd0, 8'sd0, 8'sd0
        );

        // E0: start. No operand pair is accepted yet.
        drive_cycle(
            1'b1, 1'b0, 8'd2,
            8'sd0, 8'sd0, 8'sd0, 8'sd0
        );

        // E1: k=0 reaches PE00.
        // Row1 and column1 are still invalid, so use poison values.
        drive_cycle(
            1'b0, 1'b0, 8'd2,
            8'sd1, 8'sd99,
            8'sd5, 8'sd99
        );

        // E2:
        // PE00 receives k=1.
        // PE01 and PE10 receive k=0.
        drive_cycle(
            1'b0, 1'b0, 8'd2,
            8'sd2, 8'sd3,
            8'sd7, 8'sd6
        );

        // E3:
        // PE01 and PE10 receive k=1.
        // PE11 receives k=0 through the internal forwarding paths.
        drive_cycle(
            1'b0, 1'b0, 8'd2,
            8'sd99, 8'sd4,
            8'sd99, 8'sd8
        );

        // E4: only PE11 accepts its final pair.
        drive_cycle(
            1'b0, 1'b0, 8'd2,
            8'sd99, 8'sd99,
            8'sd99, 8'sd99
        );

        // E5: PE11's final registered product enters C11.
        drive_cycle(
            1'b0, 1'b0, 8'd2,
            -8'sd88, -8'sd88,
            -8'sd88, -8'sd88
        );

        @(posedge clk);
        #1;

        $display(
            "FINAL C = {%0d, %0d, %0d, %0d}",
            C00, C01, C10, C11
        );

        // Expected: C00=19, C01=22, C10=43, C11=50.
        // Add your result checks here.

        repeat (2) @(posedge clk);
        $finish;
    end

    /*
     * Write properties here, or include them from:
     *
     * `include "PE_Top_sva.sv"
     *
     * Recommended first properties:
     *   1. Controller reset
     *   2. Controller clear
     *   3. v00-to-v01/v10 delay
     *   4. v01-to-v11 delay
     *   5. accepted_count increment/hold
     */

endmodule