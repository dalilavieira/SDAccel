module placement(out, clk, reset);
	input clk, reset;
	output reg out;
	//COLOCAR COMO parameter(constante recebida)
	parameter n = 4, n_node = 14, n_edge = 15, size_offset = 28;

	reg [0:2] state;
	reg [0:63] i, j;
	reg [0:63] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;
	reg [0:63] a, b;
	reg [0:63] xi, xj;

	reg [0:63] sum;
	reg [0:63] diff_pos_x, diff_pos_y;
	reg [0:n_edge] e_a, e_b;
	reg [0:n_node] pos_X, pos_Y;
	reg [0:n*n-1] grid;
	reg [0:size_offset] offset_x, offset_y;

	always @(reset) begin
		state = 0;
		sum = 0;
	end

	always @(posedge clk) begin
		if(~reset) begin
			case (state)
				0: //INICIALIZACOES
				begin
					e_a[0] = 0; e_b[0] = 4;
					e_a[1] = 1; e_b[1] = 5;
					e_a[2] = 2; e_b[2] = 6;
					e_a[3] = 3; e_b[3] = 7;
					e_a[4] = 4; e_b[4] = 8;
					e_a[5] = 5; e_b[5] = 9;
					e_a[6] = 6; e_b[6] = 10;
					e_a[7] = 7; e_b[7] = 4;
					e_a[8] = 7; e_b[8] = 5;
					e_a[9] = 7; e_b[9] = 6;
					e_a[10] = 8; e_b[10] = 11;
					e_a[11] = 9; e_b[11] = 11;
					e_a[12] = 10; e_b[12] = 12;
					e_a[13] = 11; e_b[13] = 13;
					e_a[14] = 12; e_b[14] = 13;

					offset_x[0] = 0; offset_y[0] = 1;
					offset_x[1] = 1; offset_y[1] = 0;
					offset_x[2] = 0; offset_y[2] = -1;
					offset_x[3] = -1; offset_y[3] = 0;
					offset_x[4] = -1; offset_y[4] = 1;
					offset_x[5] = 1; offset_y[5] = 1;
					offset_x[6] = 1; offset_y[6] = -1;
					offset_x[7] = -1; offset_y[7] = -1;
					offset_x[8] = 0; offset_y[8] = 2;
					offset_x[9] = 2; offset_y[9] = 0;
					offset_x[10] = 0; offset_y[10] = -2;
					offset_x[11] = -2; offset_y[11] = 0;
					offset_x[12] = -1; offset_y[12] = 2;
					offset_x[13] = 1; offset_y[13] = 2;
					offset_x[14] = 1; offset_y[14] = -2;
					offset_x[15] = -1; offset_y[15] = -2;
					offset_x[16] = -2; offset_y[16] = 1;
					offset_x[17] = 2; offset_y[17] = 1;
					offset_x[18] = 2; offset_y[18] = -1;
					offset_x[19] = -2; offset_y[19] = -1;
					offset_x[20] = 0; offset_y[20] = 4;
					offset_x[21] = 4; offset_y[21] = 0;
					offset_x[22] = 0; offset_y[22] = -4;
					offset_x[23] = -4; offset_y[23] = 0;
					offset_x[24] = 1; offset_y[24] = 3;
					offset_x[25] = 1; offset_y[25] = -3;
					offset_x[26] = -1; offset_y[26] = -3;
					offset_x[27] = -1; offset_y[27] = 3;

					for(i=0; i<n; i++)begin
						for(j=0; j<n; j++)begin
							grid[i*n+j] = -1;
							//$display("%d ", grid[i*n+j]);
						end
					end

					for(i=0; i<n_node; i++)begin
					  pos_X[i] = -1;
					  pos_Y[i] = -1;
					end

					a = e_a[0];
					pos_X[a] = 0;
					pos_Y[a] = 0;

					//Talvez possa ser eliminado
					//grid[pos_X[0]*n+pos_Y[0]] = a;
					grid[0] = a;

					i=0;
					j=0;
					state = 1;
				end
				1://Leitura das memórias
				begin
					if(i == n_edge)begin
						i=0;
						state = 4;
						//break;
					end
					else begin
						a = e_a[i];
						b = e_b[i];
						pos_a_X = pos_X[a];
						pos_a_Y = pos_Y[a];
						pos_b_X = pos_X[b];
						pos_b_Y = pos_Y[b];

						if(i==0)begin
							state = 3;
						end
						else begin
							state = 2;
						end
					end
				end
				2://Posição X de a
				begin
					if(pos_a_X != -1)begin
	          state = 3;
					 	j=0;
						//break;
					end
					else begin
						pos_X[a] = pos_X[i-1] + offset_x[j];
						pos_Y[a] = pos_Y[i-1] + offset_y[j];

						xi = pos_X[a];
						xj = pos_Y[a];
						j++;

						if(grid[xi*n+xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0)begin
							grid[xi*n+xj] = a;
							pos_a_X = xi;
							pos_a_Y = xj;
						end
						else if(j > size_offset)begin
							$display("No solution\n");
							out = 0;
							state = 5;
						end

						else if(pos_a_X == -1)begin
							state = 2;
						end
						else begin
							state = 3;
							j=0;
						end
					end
				end
				3://Posição X de bs
				begin
					if(pos_b_X != -1)begin
						state = 1;
						j=0;
						i++;
					  //break;
					end
					else begin
						xi = pos_a_X + offset_x[j];
						xj = pos_a_Y + offset_y[j];
						j++;
						if(grid[xi*n+xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0)begin
							grid[xi*n+xj] = b;
							pos_b_X = xi;
							pos_b_Y = xj;
							pos_X[b] = xi;
							pos_Y[b] = xj;
							state = 1;
							j=0;
							i++;
						  	//break; SWITCH ??? É NECESSARIO ?
						end
						else if(j > size_offset)begin
							$display("No solution\n");
							out = 0;
							state = 5;
						end
						else if(pos_b_X == -1)begin
							state = 3;
						end
						else begin
							state = 1;
							j=0;
							i++;
						end
					end
				end
				4://Evaluation
				begin
					if(i == n_edge)begin
					 	state = 5;
					 	//break;
					end
					else begin
						a = e_a[i];
						b = e_b[i];
						diff_pos_x = pos_X[a]-pos_X[b];

						if(diff_pos_x < 0)
							diff_pos_x *= -1;

						diff_pos_y = pos_Y[a]-pos_Y[b];

						if(diff_pos_y < 0)
							diff_pos_y *= -1;

						if (diff_pos_x + diff_pos_y > 0)
							sum += diff_pos_x + diff_pos_y - 1;
						i++;
					end
				end
				5: //Exibe a grid OBS: display existe apenas na simulacao
				begin
					for(i=0; i<n; i++)begin
						for(j=0; j<n; j++)begin
							$display("%d ", grid[i*n+j]);
					  	end
					 	$display("\n");
					 end
					 $display("Evaluation = %d\n", sum);
					 out = 1;
				end
			endcase
		end
	end

endmodule

module test;
	/* Make a regular pulsing clock. */
	reg clk = 0;
	reg reset = 1;
	wire out;

	initial begin
    		$dumpfile("placement.vcd");
    		$dumpvars(0, test);
		//$monitor("reset = %d\nclk = %d\n", reset, clk);
		#4 reset = 0;
		#200 $finish;
  	end

	always #1 clk = !clk;

	placement p1 (out, clk, reset);
endmodule // test
