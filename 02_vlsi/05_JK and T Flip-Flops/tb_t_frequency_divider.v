`timescale 1ns / 1ps

module tb_t_frequency_divider;

reg clk;
reg rst_n;
wire clk_out;

// Instantiate T frequency divider
t_frequency_divider uut (
    .clk(clk),
    .rst_n(rst_n),
    .clk_out(clk_out)
);

// Generate 10 ns clock
always #5 clk = ~clk;

initial begin

    clk = 1'b0;
    rst_n = 1'b0;

    // Apply reset
    #12 rst_n = 1'b1;

    // Run simulation
    #200;

    $finish;

end

// Display output
initial begin
    $monitor("Time=%0t | Reset=%b | Input Clock=%b | Output Clock=%b",
             $time, rst_n, clk, clk_out);
end

// Generate waveform
initial begin
    $dumpfile("t_frequency_divider.vcd");
    $dumpvars(0, tb_t_frequency_divider);
end

endmodule