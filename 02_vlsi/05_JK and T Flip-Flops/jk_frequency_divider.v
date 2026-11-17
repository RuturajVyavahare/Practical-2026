`timescale 1ns / 1ps

module jk_frequency_divider (
    input wire clk,
    input wire rst_n,
    output reg clk_out
);

// JK Flip-Flop configured in toggle mode
always @(posedge clk or negedge rst_n) begin

    if (!rst_n)
        clk_out <= 1'b0;

    else begin
        clk_out <= ~clk_out;
    end

end

endmodule
