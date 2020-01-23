module placement(clk);
	input clk;
	//COLOCAR COMO parameter(constante recebida)
	parameter n = 4, n_node = 14, n_edge = 15, size_offset = 28;

	reg [0:2] state;
	reg [0:63] i, j;
	reg [0:63] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;	
	reg [0:63] a, b;
	reg [0:63] xi, xj;

	reg [0:63] sum = 0;
	reg [0:63] diff_pos_x, diff_pos_y;	
	reg [0:n_edge] e_a, e_b;
	reg [0:n_node] pos_X, pos_Y;
	reg [0:n*n] grid;
	reg [0:size_offset] offset_x, offset_y;


endmodule

module test;
	/* Make a regular pulsing clock. */
	reg clk = 0;
	always #5 clk = !clk;
	
	//wire [7:0] n_node;
	//wire [7:0] n_edge;
	//wire [7:0] size_offset;

	placement p1 (clk);
endmodule // test
