/*
 * Assumption: A and B come in pairs (dependent)
 *
 * start is a one-clock pulse.
 * accum_clr must occur before start.
 * start arms the controller and the first pair is accepted
 * on the following rising clock edge.
 *
 * K contains the number of operand pairs in the operation.
 */
module PE_Top #(
    parameter K_WIDTH = 8
) (
    input  wire                     clk,
    input  wire                     rst_n,
    input  wire                     accum_clr,
    input  wire                     start,

    // Runtime-modifiable number of operand pairs
    input  wire [K_WIDTH-1:0]       K,

    input  wire signed [7:0]        A_row0,
    input  wire signed [7:0]        A_row1,
    input  wire signed [7:0]        B_col0,
    input  wire signed [7:0]        B_col1,

    output wire signed [31:0]       C00,
    output wire signed [31:0]       C01,
    output wire signed [31:0]       C10,
    output wire signed [31:0]       C11
);


    // Horizontal A connections
    wire signed [7:0] A_PE00_to_PE01;
    wire signed [7:0] A_PE10_to_PE11;


    // Vertical B connections
    wire signed [7:0] B_PE00_to_PE10;
    wire signed [7:0] B_PE01_to_PE11;


    // Forwarding outputs leaving the array
    wire signed [7:0] unused_A_PE01;
    wire signed [7:0] unused_B_PE10;
    wire signed [7:0] unused_A_PE11;
    wire signed [7:0] unused_B_PE11;


    // ====== PE_valid Controller =======

    // Controller state
    reg                       issuing;
    reg [K_WIDTH-1:0]         accepted_count;
    reg [K_WIDTH-1:0]         active_K;
    reg                       valid_delay_1;
    reg                       valid_delay_2;


    // Local PE-valid signals
    wire v00;
    wire v01;
    wire v10;
    wire v11;


    // PE00 receives the original issue-valid stream.
    assign v00 = issuing && (accepted_count < active_K);

    // PE01 and PE10 are one forwarding clock away from PE00.
    assign v01 = valid_delay_1;
    assign v10 = valid_delay_1;

    // PE11 is two forwarding clocks away from PE00.
    assign v11 = valid_delay_2;


    always @(posedge clk) begin
        if (!rst_n) begin
            // Reset controller state
            issuing        <= 1'b0;
            accepted_count <= {K_WIDTH{1'b0}};
            active_K       <= {K_WIDTH{1'b0}};
            valid_delay_1  <= 1'b0;
            valid_delay_2  <= 1'b0;
        end

        else if (accum_clr) begin
            // Flush controller state
            issuing        <= 1'b0;
            accepted_count <= {K_WIDTH{1'b0}};
            active_K       <= {K_WIDTH{1'b0}};
            valid_delay_1  <= 1'b0;
            valid_delay_2  <= 1'b0;
        end

        else begin
            /*
             * These memories must advance every ordinary clock,
             * including the drain cycles.
             */
            valid_delay_1 <= v00;
            valid_delay_2 <= valid_delay_1;


            // Start/issue-state control
            if (start) begin
                /*
                 * Capture K so that changing the external K input
                 * during an operation cannot change the active job.
                 */
                active_K       <= K;
                accepted_count <= {K_WIDTH{1'b0}};

                /*
                 * K = 0 represents an empty operation, so no operand
                 * pairs should be accepted.
                 */
                if (K == {K_WIDTH{1'b0}})
                    issuing <= 1'b0;
                else
                    issuing <= 1'b1;
            end

            else if (v00) begin
                /*
                 * v00 means PE00 accepts exactly one operand pair
                 * on this edge.
                 */
                accepted_count <= accepted_count + 1'b1;

                /*
                 * Nonblocking assignments observe the old count.
                 * Therefore, old count = active_K - 1 means this
                 * edge accepts the final operand pair.
                 */
                if (accepted_count == (active_K - 1'b1))
                    issuing <= 1'b0;
            end
        end
    end


    // =================================


    PE PE00 (
        .clk        (clk),
        .rst_n      (rst_n),
        .pe_valid   (v00),

        .A          (A_row0),
        .B          (B_col0),
        .C          (C00),

        .accum_clr  (accum_clr),

        .A_forw_op  (A_PE00_to_PE01),
        .B_forw_op  (B_PE00_to_PE10)
    );


    PE PE01 (
        .clk        (clk),
        .rst_n      (rst_n),
        .pe_valid   (v01),

        .A          (A_PE00_to_PE01),
        .B          (B_col1),
        .C          (C01),

        .accum_clr  (accum_clr),

        .A_forw_op  (unused_A_PE01),
        .B_forw_op  (B_PE01_to_PE11)
    );


    PE PE10 (
        .clk        (clk),
        .rst_n      (rst_n),
        .pe_valid   (v10),

        .A          (A_row1),
        .B          (B_PE00_to_PE10),
        .C          (C10),

        .accum_clr  (accum_clr),

        .A_forw_op  (A_PE10_to_PE11),
        .B_forw_op  (unused_B_PE10)
    );


    PE PE11 (
        .clk        (clk),
        .rst_n      (rst_n),
        .pe_valid   (v11),

        .A          (A_PE10_to_PE11),
        .B          (B_PE01_to_PE11),
        .C          (C11),

        .accum_clr  (accum_clr),

        .A_forw_op  (unused_A_PE11),
        .B_forw_op  (unused_B_PE11)
    );

endmodule