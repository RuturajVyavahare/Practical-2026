
`timescale 1ns / 1ps

module async_counter(
    input clk,
    input reset,
    output [2:0] count
);

reg [2:0] q;

// First flip-flop
always @(posedge clk or posedge reset) begin
    if (reset)
        q[0] <= 0;
    else
        q[0] <= ~q[0];
end

// Second flip-flop
always @(negedge q[0] or posedge reset) begin
    if (reset)
        q[1] <= 0;
    else
        q[1] <= ~q[1];
end

// Third flip-flop
always @(negedge q[1] or posedge reset) begin
    if (reset)
        q[2] <= 0;
    else
        q[2] <= ~q[2];
end

assign count = q;

endmodule
