`timescale 1ns / 1ps

module async_counter_tb;

reg clk;
reg reset;
wire [2:0] count;

// Instantiate the counter
async_counter uut (
    .clk(clk),
    .reset(reset),
    .count(count)
);

// Generate clock: 10 ns period
always #5 clk = ~clk;

initial begin
    clk = 1'b0;
    reset = 1'b1;

    // Apply reset
    #20;
    reset = 1'b0;

    // Run simulation
    #300;

    $finish;
end

// Display output values
initial begin
    $monitor("Time=%0t | Reset=%b | Count=%b",
             $time, reset, count);
end

// Generate waveform file
initial begin
    $dumpfile("async_counter_tb.vcd");
    $dumpvars(0, async_counter_tb);
end

endmodule