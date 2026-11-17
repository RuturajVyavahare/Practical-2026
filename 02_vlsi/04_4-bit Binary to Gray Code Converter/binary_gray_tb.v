`timescale 1ns/1ps

module binary_gray_tb;

reg [3:0] B;
wire [3:0] G;
integer i;

// Instantiate the design
binary_gray uut(
    .B(B),
    .G(G)
);

// Apply all 16 possible binary input combinations
initial begin

    for (i = 0; i < 16; i = i + 1) begin
        B = i;
        #10;
    end

    $finish;

end

// Display results
initial begin
    $monitor("Time=%0t | B=%b | G=%b", $time, B, G);
end

endmodule
