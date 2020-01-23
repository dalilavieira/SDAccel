module placement(clk, n, n_node, n_edge, size_offset);
	input clk;
	input wire [31:0] n;
	input wire [7:0] n_node, n_edge, size_offset;


endmodule

module test;
	/* Make a regular pulsing clock. */
	reg clk = 0;
	always #5 clk = !clk;
	parameter n = 9;
	wire [7:0] n_node;
	wire [7:0] n_edge;
	wire [7:0] size_offset;

	placement p1 (clk, n, n_node, n_edge, size_offset);
endmodule // test
