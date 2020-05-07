`include "placement.v"

module test;
 	 reg clk;
	 reg reset, rst;
         reg loads = 0;
        reg [31:0] seed = 1520401299;
 	 initial begin
	 	 $dumpfile("placement.vcd");
	 	 $dumpvars;
	 	 clk = 0;
	 	 reset = 0;
	 	 #1 reset = 1;
	 	 #23 reset = 0;
		 #0 rst = 1;
		 #0 loads = 1;
		 #2 loads = 0;
	 	 //#50 rst = 0;
                //#140 $finish;
	 end
	 always #1 clk = !clk;
	 wire out;
	 placement p1 (out, clk, reset, loads, rst, seed);
endmodule
