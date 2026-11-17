`timescale 1ns / 1ps

module alu_4bit_tb;

reg [3:0] A;
reg [3:0] B;
reg [2:0] sel;
wire [3:0] Y;

// Instantiate ALU
alu_4bit uut (
    .A(A),
    .B(B),
    .sel(sel),
    .Y(Y)
);

initial begin

    // Subtraction
    A = 4'b1001;
    B = 4'b0011;
    sel = 3'b000;
    #10;

    // Addition
    A = 4'b0101;
    B = 4'b0011;
    sel = 3'b001;
    #10;

    // OR
    A = 4'b1010;
    B = 4'b0101;
    sel = 3'b010;
    #10;

    // AND
    A = 4'b1010;
    B = 4'b1100;
    sel = 3'b011;
    #10;

    // XOR
    A = 4'b1010;
    B = 4'b1100;
    sel = 3'b100;
    #10;

    // NOT
    A = 4'b1010;
    B = 4'b0000;
    sel = 3'b101;
    #10;

    // Right Shift
    A = 4'b1000;
    B = 4'b0000;
    sel = 3'b110;
    #10;

    // Left Shift
    A = 4'b0011;
    B = 4'b0000;
    sel = 3'b111;
    #10;

    $finish;

end

// Display results
initial begin
    $monitor("Time=%0t | A=%b | B=%b | SEL=%b | Y=%b",
             $time, A, B, sel, Y);
end

// Generate waveform
initial begin
    $dumpfile("alu_4bit_tb.vcd");
    $dumpvars(0, alu_4bit_tb);
end

endmodule