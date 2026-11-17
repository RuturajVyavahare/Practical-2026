`timescale 1ns/1ps

module binary_gray_tb;

reg B3, B2, B1;
wire G3, G2, G1;

// Instantiate the design
binary_gray uut(
    .B3(B3),
    .B2(B2),
    .B1(B1),
    .G3(G3),
    .G2(G2),
    .G1(G1)
);

initial begin

B3=0; B2=0; B1=0; #10;
    B3=0; B2=0; B1=1; #10;
    B3=0; B2=1; B1=0; #10;
    B3=0; B2=1; B1=1; #10;
    B3=1; B2=0; B1=0; #10;
    B3=1; B2=0; B1=1; #10;
    B3=1; B2=1; B1=0; #10;
    B3=1; B2=1; B1=1; #10;

    $finish;

end

initial begin
    $monitor("Time=%0t | B=%b%b%b | G=%b%b%b",
             $time, B3, B2, B1, G3, G2, G1);
end

endmodule