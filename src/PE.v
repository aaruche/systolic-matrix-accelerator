/* 

Processing Element ( Qty = 4) 
- 1 Product reg and 1 Accum reg 
- Forwarding reg x 2 for both A and B (forwards to the next PE horizontally/vertically)
- Priority of flags : rst_n > accum_clr > PE_valid > valid_A/B or mult_reg_valid

*/
module PE (
    input clk, 
    input rst_n,
    input pe_valid, 
    

    input signed [7:0] A , 
    input signed [7:0] B ,  
    output signed [31:0] C ,

    input A_valid_forw,                      // whether the current A input contains valid matrix data (F3)
    input B_valid_forw,                      // whether the current B input contains valid matrix data (F3)

    input accum_clr,                         // begin a new matrix multiplication / clear the previous C result 

    output signed [7:0] A_forw_op,           // corresponding 8 bit forwarding output for forw_reg (F1) 
    output signed [7:0] B_forw_op

);
 reg signed [15:0] mult_reg ; 
 reg mult_valid_reg;                         // whether the product stored in mult_reg is valid and should be accumulated (F2)
 
 reg signed [31:0] accum_reg ; 
 
 // Fowards operands to the neighboring PE 
 reg signed [7:0] A_forw_reg ;
 reg signed[7:0] B_forw_reg ;

                   



endmodule