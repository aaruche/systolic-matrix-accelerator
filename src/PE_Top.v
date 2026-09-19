module PE_Top (
    input  wire                     clk,
    input  wire                     rst_n,
    input  wire                     accum_clr,

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


    PE PE00 (
        .clk       (clk),
        .rst_n     (rst_n),

        .A         (A_row0),
        .B         (B_col0),
        .C         (C00),

        .accum_clr (accum_clr),

        .A_forw_op (A_PE00_to_PE01),
        .B_forw_op (B_PE00_to_PE10)
    );


    PE PE01 (
        .clk       (clk),
        .rst_n     (rst_n),

        .A         (A_PE00_to_PE01),
        .B         (B_col1),
        .C         (C01),

        .accum_clr (accum_clr),

        .A_forw_op (unused_A_PE01),
        .B_forw_op (B_PE01_to_PE11)
    );


    PE PE10 (
        .clk       (clk),
        .rst_n     (rst_n),

        .A         (A_row1),
        .B         (B_PE00_to_PE10),
        .C         (C10),

        .accum_clr (accum_clr),

        .A_forw_op (A_PE10_to_PE11),
        .B_forw_op (unused_B_PE10)
    );


    PE PE11 (
        .clk       (clk),
        .rst_n     (rst_n),

        .A         (A_PE10_to_PE11),
        .B         (B_PE01_to_PE11),
        .C         (C11),

        .accum_clr (accum_clr),

        .A_forw_op (unused_A_PE11),
        .B_forw_op (unused_B_PE11)
    );

endmodule