
`timescale 1ns/1ps

module binary_gray(
    input B3,
    input B2,
    input B1,
    output G3,
    output G2,
    output G1
);

xor XOR1(G2, B3, B2);
xor XOR2(G1, B2, B1);

assign G3 = B3;

endmodule
