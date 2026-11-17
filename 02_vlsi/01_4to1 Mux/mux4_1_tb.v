`timescale 1ns/1ps

module mux4_1_tb;

reg w0, w1, w2, w3;
reg [1:0] s;
wire f;

mux4_1 uut (
    .w0(w0),
    .w1(w1),
    .w2(w2),
    .w3(w3),
    .s(s),
    .f(f)
);

initial begin
    w0 = 0;
    w1 = 1;
    w2 = 0;
    w3 = 1;

    s = 2'b00; #10;
    s = 2'b01; #10;
    s = 2'b10; #10;
    s = 2'b11; #10;

    $finish;
end

initial begin
    $monitor("time=%0t s=%b f=%b", $time, s, f);
end

endmodule