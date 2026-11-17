`timescale 1ns / 1ps

module siso_tb;

reg clk;
reg reset;
reg S_in;
wire S_out;

// Instantiate SISO module
siso uut (
    .clk(clk),
    .reset(reset),
    .S_in(S_in),
    .S_out(S_out)
);

// Generate 10 ns clock
always #5 clk = ~clk;

// Apply serial input bits
task send_bit;
    input bit_value;
    begin
        @(negedge uut.clk_div);
        S_in = bit_value;

        @(posedge uut.clk_div);
        #1;

        $display("Time=%0t | S_in=%b | S_out=%b",
                 $time, S_in, S_out);
    end
endtask

initial begin
    clk = 1'b0;
    reset = 1'b1;
    S_in = 1'b0;

    // Apply reset
    #20;
    reset = 1'b0;

    // Send serial data
    send_bit(1'b1);
    send_bit(1'b0);
    send_bit(1'b1);
    send_bit(1'b1);

    // Allow remaining simulation
    #20;
    $finish;
end

// Monitor signals
initial begin
    $monitor("Time=%0t | Reset=%b | S_in=%b | S_out=%b",
             $time, reset, S_in, S_out);
end

// Generate waveform
initial begin
    $dumpfile("siso_tb.vcd");
    $dumpvars(0, siso_tb);
end

endmodule