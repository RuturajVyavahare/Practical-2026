
`timescale 1ns/1ps

module mux4_1_behavioral(
    input w0,
    input w1,
    input w2,
    input w3,
    input [1:0] s,
    output reg f
);

always @(*) begin
    case(s)
        2'b00: f = w0;
        2'b01: f = w1;
        2'b10: f = w2;
        2'b11: f = w3;
        default: f = 1'b0;
    endcase
end

endmodule
