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

    

    input accum_clr,                         // begin a new matrix multiplication / clear the previous C result 

    output signed [7:0] A_forw_op,           // corresponding 8 bit forwarding output for A/B_forw_reg (F1) 
    output signed [7:0] B_forw_op

);
 reg signed [15:0] mult_reg ; 
 reg mult_valid_reg;                         // whether the product stored in mult_reg is valid and should be accumulated (F3)
 
 reg signed [31:0] accum_reg ; 
 
 // Fowards operands to the neighboring PE 
 reg signed [7:0] A_forw_reg ;
 reg signed[7:0] B_forw_reg ;

     // Operands Forwarding               
always @(posedge clk) begin
    if (!rst_n) begin 
        accum_reg   <= 32'b0; 
        A_forw_reg  <= 8'b0;
        B_forw_reg  <= 8'b0;
    end 

    else if (pe_valid && !accum_clr) begin 
        A_forw_reg <= A; 
        B_forw_reg <= B; 
    end 

end 

// Operands forwarding 
assign A_forw_op = A_forw_reg ;
assign B_forw_op = B_forw_reg ;

// Product Pipeline Stage
always @(posedge clk) begin
    if (!rst_n) begin
        mult_reg       <= 16'b0;
        mult_valid_reg <= 1'b0;
    end
    else if (accum_clr) begin
        mult_reg       <= 16'b0;
        mult_valid_reg <= 1'b0;
    end
    else if (pe_valid) begin
        mult_reg       <= A * B;
        mult_valid_reg <= 1'b1;
    end
    else begin
        mult_valid_reg <= 1'b0;  // Bubble; previous product can still be accumulated on this edge
    end

end 


endmodule