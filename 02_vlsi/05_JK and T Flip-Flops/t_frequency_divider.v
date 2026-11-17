`timescale 1ns / 1ps

module t_frequency_divider (
    input wire clk,
    input wire rst_n,
    output reg clk_out
);

// T Flip-Flop configured in toggle mode
always @(posedge clk or negedge rst_n) begin

    if (!rst_n)
        clk_out <= 1'b0;

    else
        clk_out <= ~clk_out;

end

endmodule