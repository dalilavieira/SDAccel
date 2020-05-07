`include "memorias/memoryRAM.v"
`include "memorias/memoryROM.v"

module placement(out, clk, reset);
	//Parameters of states:
	parameter v = 11;
	parameter init0 = 0, init1 = 1, init2 = 2, init3 = 3;
	parameter reMem0 = 4, reMem1 = 5, reMem2 = 6, reMem3 = 7, reMem4 = 8;
	parameter posA0 = 9, posA1 = 10, posA2 = 11, posA3 = 12, posA4 = 13, posA5 = 14, posA6 = 15, posA7 = 16;
	parameter posB0 = 17, posB1 = 18, posB2 = 19, posB3 = 20, posB4 = 21, posB5 = 22;
	parameter eval0 = 23, eval1 = 24, eval2 = 25, eval3 = 26, eval4 = 27, eval5 = 28, eval6 = 29, eval7 = 30;
	parameter exit = 31, waitState = 32;
	//Parameters of datas:
	parameter n = 8, n_edge = 65, size_offset = 63, tam_ex_mem = 4, tam_off_mem = 5, tam_pos_mem = 4;
	//Inputs and output:
	input clk, reset;
	output reg out;
	//Controls:
	reg reEA, reEB, reOX, reOY, rePX, rePY, reGrid;
	reg signed [32-1:0] addrEA, addrEB, addrOX, addrOY, addrPX, addrPY, addrGrid;
	wire signed [32-1:0] doutEA, doutEB, doutOX, doutOY, doutPX, doutPY, doutGrid;
	reg wePX, wePY, weGrid;
	reg signed [32-1:0] dinPX, dinPY, dinGrid;
	wire [32-1:0] outPX, outPY, outOX, outOY, outGrid;
	//Regs and wires:
	reg [32-1:0] state, next_state, i, j;
	reg [32-1:0] aux1, aux2, aux3, aux4;
	reg signed [32-1:0] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;
	wire signed [32-1:0] a, b;
	reg signed [32-1:0] xi, xj;
	reg signed [32-1:0] sum, sum_1hop;
	reg signed [32-1:0] diff_pos_x, diff_pos_y;
	reg [32-1:0] cont;
	//Outputs of memories:
	assign a = doutEA;
	assign b = doutEB;
	assign outPX = doutPX;
	assign outPY = doutPY;
	assign outOX = doutOX;
	assign outOY = doutOY;
	assign outGrid = doutGrid;

	/*
	States [0,3]: Initialization;
	States [4,8]: Read of memories;
	States [9,16]: Position X of A;
	States [17,22]: Position X of B;
	States [23,30]: Evaluation;
	State 31: End;
	OBS.: States 32 = Wait state.
	*/

	always @(posedge clk) begin
		if(reset) begin
			reEA <= 0; addrEA <= 0;
			reEB <= 0; addrEB <= 0;
			reOX <= 0; addrOX <= 0;
			reOY <= 0; addrOY <= 0;
			rePX <= 0; wePX <= 0; addrPX <= 0; dinPX <= 0;
			rePY <= 0; wePY <= 0; addrPY <= 0; dinPY <= 0;
			reGrid <= 0; weGrid <= 0; addrGrid <= 0; dinGrid <= 0;
			state <= 0; next_state <= 0;
			sum <= 0; cont <= 0; sum_1hop <= 0;
		end
		else begin
			cont <= cont + 1;
			reEA <= 0; reEB <= 0;
			reOX <= 0; reOY <= 0;
			rePX <= 0; wePX <= 0;
			rePY <= 0; wePY <= 0;
			reGrid <= 0; weGrid <= 0;
			//State machine:
			case (state)
				init0: begin
					reEA <= 1; addrEA <= 0;
					reOX <= 1; addrOX <= 62; //le primeiro valor offsetX
					reOY <= 1; addrOY <= 62; //le primeiro valor offsetY
					//state <= init1;
					state <= waitState;
					next_state <= init1;
				end
				init1: begin
					//$display("OFFSET Y ",outOY);
					if(outOY >= 0) begin						
						wePY <= 1; addrPY <= a; dinPY <= outOY;
					end else begin
						wePY <= 1; addrPY <= a; dinPY <= (outOY ^ (32'b11111111111111111111111111111111)) + 1;
					end

					if(outOX >= 0)begin
						wePX <= 1; addrPX <= a; dinPX <= outOX;
					end else begin
						wePX <= 1; addrPX <= a; dinPX <= (outOX ^ (32'b11111111111111111111111111111111)) + 1;
					end

					state <= init2;
				end
				init2: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					i <= 0;
					j <= 0;
					state <= waitState;
					next_state <= init3;
				end
				init3: begin
					weGrid <= 1; addrGrid <= outPX*n+outPY; dinGrid <= a;
					state <= reMem0;
				end
				reMem0: begin
					if(i == n_edge) begin
						i <= 0;
						state <= eval0;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= waitState;
						next_state <= reMem1;
					end
				end
				reMem1: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					state <= waitState;
					next_state <= reMem2;
				end
				reMem2: begin
					pos_a_X <= outPX;
					pos_a_Y <= outPY;
					state <= reMem3;
					next_state <= reMem4;
				end
				reMem3: begin
					rePX <= 1; addrPX <= b;
					rePY <= 1; addrPY <= b;
					state <= waitState;
				end
				reMem4: begin
					pos_b_X <= outPX;
					pos_b_Y <= outPY;
					if(i==0) begin
						state <= posB0;
					end
					else begin
						state <= posA0;
					end
				end
				posA0: begin
					if(pos_a_X != -1) begin
	          state <= posB0;
				 		j <= 0;
			  		end
					else begin
						rePX <= 1; addrPX <= i-1;
						reOX <= 1; addrOX <= j;
						rePY <= 1; addrPY <= i-1;
						reOY <= 1; addrOY <= j;
						state <= waitState;
						next_state <= posA1;
					end
				end
				posA1: begin
					aux1 <= outPX + outOX;
					aux3 <= outPY + outOY;
					state <= posA2;
				end
				posA2: begin
					wePX <= 1; addrPX <= a; dinPX <= aux1;
					wePY <= 1; addrPY <= a; dinPY <= aux3;
					state <= posA3;
				end
				posA3: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					j++;
					state <= waitState;
					next_state <= posA4;
				end
				posA4: begin
					xi <= outPX;
					xj <= outPY;
					aux1 <= outPX*n+outPY;
					state <= posA5;
				end
				posA5: begin
					reGrid <= 1; addrGrid <= aux1;
					state <= waitState;
					next_state <= posA6;
				end
				posA6: begin
					aux2 <= outGrid;
					state <= posA7;
				end
				posA7: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= a;
						pos_a_X <= xi;
						pos_a_Y <= xj;
						state <= posB0;
						j <= 0;
					end
					else if(pos_a_X == -1) begin
						state <= posA0;
					end
					if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= exit;
					end
				end
				posB0: begin
					if(pos_b_X != -1) begin
						state <= reMem0;
						j <= 0;
						i++;
					end
					else begin
						reOX <= 1; addrOX <= j;
						reOY <= 1; addrOY <= j;
						state <= waitState;
						next_state <= posB1;
					end
				end
				posB1: begin
					xi <= pos_a_X + outOX;
					xj <= pos_a_Y + outOY;
					state <= posB2;
				end
				posB2: begin
					aux1 <= xi*n+xj;
					state <= posB3;
				end
				posB3: begin
					j++;
					reGrid <= 1; addrGrid <= aux1;
					state <= waitState;
					next_state <= posB4;
				end
				posB4: begin
					aux2 <= outGrid;
					state <= posB5;
				end
				posB5: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= b;
						pos_b_X <= xi;
						pos_b_Y <= xj;
						wePX <= 1; addrPX <= b; dinPX <= xi;
						wePY <= 1; addrPY <= b; dinPY <= xj;
						j <= 0;
						i++;
						state <= reMem0;
					end
					else if(pos_b_X == -1) begin
						state <= posB0;
					end
					if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= exit;
					end
				end
				eval0: begin
					if(i == n_edge) begin
					 	state <= exit;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= waitState;
						next_state <= eval1;
					end
				end
				eval1: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					state <= waitState;
					next_state <= eval2;
				end
				eval2: begin
					aux1 <= outPX;
					aux2 <= outPY;
					state <= reMem3;
					next_state <= eval3;
				end
				eval3: begin
					aux3 <= outPX;
					aux4 <= outPY;
					state <= eval4;
				end
				eval4: begin
					diff_pos_x <= aux1 - aux3;
					state <= eval5;
				end
				eval5: begin
					if(diff_pos_x < 0) begin
						diff_pos_x <= (diff_pos_x ^ (32'b11111111111111111111111111111111)) + 1;
					end
					diff_pos_y <= aux2 - aux4;
					state <= eval6;
				end
				eval6: begin
					if(diff_pos_y < 0) begin
						diff_pos_y <= (diff_pos_y ^ (32'b11111111111111111111111111111111)) + 1;
					end
					state <= eval7;
				end
				eval7: begin
					sum <= sum + diff_pos_x + diff_pos_y - 1;
					sum_1hop <= sum_1hop + ((diff_pos_x >> 1) + diff_pos_x[0]) + ((diff_pos_y >> 1) + diff_pos_y[0]) - 1;
					i++;
					state <= eval0;
				end
				exit: begin
					out <= 1;
					$write("\nEvaluation = %1d\nEvaluation 1-hop = %1d\nCycles = %1d\n", sum, sum_1hop, cont);
					$finish;
				end
				waitState: begin
					state <= next_state;
				end
			endcase
		end
	end
	memoryROM #(.init_file("dados/benchmarks/h2v2_smooth/eaData.txt"), .data_depth(v)) ea (.clk(clk), .reset(reset), .read(reEA), .addr(addrEA), .data(doutEA));
	memoryROM #(.init_file("dados/benchmarks/h2v2_smooth/ebData.txt"), .data_depth(v)) eb (.clk(clk), .reset(reset), .read(reEB), .addr(addrEB), .data(doutEB));
	memoryROM #(.init_file("offsetXData.txt"), .data_depth(6)) offset_x (.clk(clk), .reset(reset), .read(reOX), .addr(addrOX), .data(doutOX));
	memoryROM #(.init_file("offsetYData.txt"), .data_depth(6)) offset_y (.clk(clk), .reset(reset), .read(reOY), .addr(addrOY), .data(doutOY));
	memoryRAM #(.init_file("dados/benchmarks/h2v2_smooth/posData.txt"), .data_depth(v)) pos_X (.clk(clk), .reset(reset), .read(rePX), .write(wePX), .addr(addrPX), .dataRead(doutPX), .dataWrite(dinPX));
	memoryRAM #(.init_file("dados/benchmarks/h2v2_smooth/posData.txt"), .data_depth(v)) pos_Y (.clk(clk), .reset(reset), .read(rePY), .write(wePY), .addr(addrPY), .dataRead(doutPY), .dataWrite(dinPY));
	memoryRAM #(.init_file("dados/gridData.txt"), .data_depth(n)) grid (.clk(clk), .reset(reset), .read(reGrid), .write(weGrid), .addr(addrGrid), .dataRead(doutGrid), .dataWrite(dinGrid));

endmodule

module test;
	reg clk;
	reg reset;
	initial begin
		$dumpfile("placement_1hop.vcd");
		$dumpvars;
		clk = 0;
		reset = 0;
		#1 reset = 1;
		#2 reset = 0;
	end
	always #1 clk = !clk;
	wire out;
	placement p1 (out, clk, reset);
endmodule
