
`timescale 1ns / 1ps

module siso(
    input wire clk,
    input wire reset,
    input wire S_in,
    output wire S_out
);

reg [25:0] counter;
reg clk_div;
reg [3:0] shift_reg;

// Clock divider
always @(posedge clk or posedge reset) begin
    if (reset) begin
        counter <= 26'd0;
        clk_div <= 1'b0;
    end
    else begin
        if (counter == 26'd4) begin
            counter <= 26'd0;
            clk_div <= ~clk_div;
        end
        else begin
            counter <= counter + 1'b1;
        end
    end
end

// 4-bit SISO shift register
always @(posedge clk_div or posedge reset) begin
    if (reset) begin
        shift_reg <= 4'b0000;
    end
    else begin
        shift_reg <= {shift_reg[2:0], S_in};
    end
end

// Serial output
assign S_out = shift_reg[3];

endmodule

