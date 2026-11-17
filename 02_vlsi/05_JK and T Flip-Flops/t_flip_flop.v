`timescale 1ns / 1ps

module t_flip_flop (
    input wire clk,
    input wire rst_n,
    input wire t,
    output reg q,
    output wire q_bar
);

always @(posedge clk or negedge rst_n) begin

    if (!rst_n)
        q <= 1'b0;

    else begin
        if (t)
            q <= ~q;
        else
            q <= q;
    end

end

assign q_bar = ~q;

endmodule
