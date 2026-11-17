`timescale 1ns / 1ps

module alu_4bit(
    input [3:0] A,
    input [3:0] B,
    input [2:0] sel,
    output reg [3:0] Y
);

always @(*) begin

    if (sel == 3'b000)
        Y = A - B;       // Subtraction

    else if (sel == 3'b001)
        Y = A + B;       // Addition

    else if (sel == 3'b010)
        Y = A | B;       // OR

    else if (sel == 3'b011)
        Y = A & B;       // AND

    else if (sel == 3'b100)
        Y = A ^ B;       // XOR

    else if (sel == 3'b101)
        Y = ~A;          // NOT

    else if (sel == 3'b110)
        Y = A >> 1;      // Right Shift

    else if (sel == 3'b111)
        Y = A << 1;      // Left Shift

    else
        Y = 4'b0000;

end

endmodule