`timescale 1ns / 1ps

module tb_jk_flip_flop;

reg clk;
reg rst_n;
reg j;
reg k;

wire q_jk;
wire q_bar_jk;

// Instantiate JK Flip-Flop
jk_flip_flop uut (
    .clk(clk),
    .rst_n(rst_n),
    .j(j),
    .k(k),
    .q(q_jk),
    .q_bar(q_bar_jk)
);

// Generate 10 ns clock
always #5 clk = ~clk;

initial begin

    // Initialize
    clk = 0;
    rst_n = 0;
    j = 0;
    k = 0;

    // Release reset
    #12 rst_n = 1;

    // Set
    #10 j = 1;
    k = 0;

    // Reset
    #10 j = 0;
    k = 1;

    // Toggle
    #10 j = 1;
    k = 1;

    // Hold
    #20 j = 0;
    k = 0;

    #20 $finish;

end

// Generate waveform
initial begin
    $dumpfile("tb_jk_flip_flop.vcd");
    $dumpvars(0, tb_jk_flip_flop);
end

endmodule
