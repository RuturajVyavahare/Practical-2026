`timescale 1ns/1ps

module mux4_1_gate(
    input w0,
    input w1,
    input w2,
    input w3,
    input [1:0] s,
    output f
);

wire s0_bar, s1_bar;
wire y0, y1, y2, y3;

not (s0_bar, s[0]);
not (s1_bar, s[1]);

and (y0, w0, s1_bar, s0_bar);
and (y1, w1, s1_bar, s[0]);
and (y2, w2, s[1], s0_bar);
and (y3, w3, s[1], s[0]);

or (f, y0, y1, y2, y3);

endmodule