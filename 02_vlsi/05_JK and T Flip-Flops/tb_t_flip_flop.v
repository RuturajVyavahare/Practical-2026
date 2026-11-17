`timescale 1ns / 1ps

module tb_t_flip_flop;

reg clk;
reg rst_n;
reg t;

wire q_t;
wire q_bar_t;

// Instantiate T Flip-Flop
t_flip_flop uut (
    .clk(clk),
    .rst_n(rst_n),
    .t(t),
    .q(q_t),
    .q_bar(q_bar_t)
);

// Generate 10 ns clock
always #5 clk = ~clk;

initial begin

    // Initialize
    clk = 0;
    rst_n = 0;
    t = 0;

    // Release reset
    #12 rst_n = 1;

    // T = 1 : Toggle
    #10 t = 1;

    // T = 0 : Hold
    #20 t = 0;

    #30 $finish;

end

// Generate waveform
initial begin
    $dumpfile("tb_t_flip_flop.vcd");
    $dumpvars(0, tb_t_flip_flop);
end

endmodule