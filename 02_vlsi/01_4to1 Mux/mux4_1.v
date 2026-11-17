
`timescale 1ns/1ps

module mux4_1(
    input w0,
    input w1,
    input w2,
    input w3,
    input [1:0] s,
    output f
);

assign f = s[1] ? (s[0] ? w3 : w2)
                : (s[0] ? w1 : w0);

endmodule
