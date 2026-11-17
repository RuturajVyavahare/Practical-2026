
`timescale 1ns/1ps

module mux2_1(
    input w0,
    input w1,
    input s,
    output f
);

assign f = s ? w1 : w0;

endmodule
