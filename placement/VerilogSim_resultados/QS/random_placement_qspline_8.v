`include "memorias/memoryRAM.v"
`include "memorias/memoryROM.v"

module placement(out, clk, reset);
	//Parameters of states:
	parameter init0 = 0, init1 = 1, init2 = 2, init3 = 3, init4 = 34, rnd_state = 33, prox_rnd = 35, prox_rnd2 = 36;
	parameter reMem0 = 4, reMem1 = 5, reMem2 = 6, reMem3 = 7, reMem4 = 8;
	parameter posA0 = 9, posA1 = 10, posA2 = 11, posA3 = 12, posA4 = 13, posA5 = 14, posA6 = 15, posA7 = 16;
	parameter posB0 = 17, posB1 = 18, posB2 = 19, posB3 = 20, posB4 = 21, posB5 = 22;
	parameter eval0 = 23, eval1 = 24, eval2 = 25, eval3 = 26, eval4 = 27, eval5 = 28, eval6 = 29, eval7 = 30;
	parameter exit = 31, waitState = 32;
	//Parameters of datas:
	parameter n = 9, n_edge = 85, size_offset = 62, tam_off_mem = 6, tam_grid_mem = 12, tam_pos_mem = 7, WALK = 4;
	//Inputs and output:
	input clk, reset;
	output reg out;
	//Controls:
	reg reEA, reEB, reOX1, reOX2, reOX3, reOX4, reOY1, reOY2, reOY3, reOY4, rePX, rePY, reGrid;
	reg signed [32-1:0] addrEA, addrEB, addrOX1, addrOX2, addrOX3, addrOX4, addrOY1, addrOY2, addrOY3, addrOY4, addrPX, addrPY, addrGrid;
	wire signed [32-1:0] doutEA, doutEB, doutOX1, doutOX2, doutOX3, doutOX4, doutOY1, doutOY2, doutOY3, doutOY4, doutPX, doutPY, doutGrid;
	reg wePX, wePY, weGrid;
	reg signed [32-1:0] dinPX, dinPY, dinGrid;
	wire [32-1:0] outPX, outPY, outOX1, outOX2, outOX3, outOX4, outOY1, outOY2, outOY3, outOY4, outGrid;
	//Regs and wires:
	reg [32-1:0] state, next_state, i, j;
	reg [32-1:0] aux1, aux2, aux3, aux4;
	reg signed [32-1:0] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;
	wire signed [32-1:0] a, b;
	reg signed [32-1:0] xi, xj;
	reg signed [32-1:0] sum, sum_1hop;
	reg signed [32-1:0] diff_pos_x, diff_pos_y;
	reg [32-1:0] cont;
	reg [32-1:0] seed, k;
	reg [32-1:0] rnd_number;
	reg [32-1:0] CASR_reg, LFSR_reg;
	reg outbitLFSR;
	//Outputs of memories:
	assign a = doutEA;
	assign b = doutEB;
	assign outPX = doutPX;
	assign outPY = doutPY;
	assign outOX1 = doutOX1;
	assign outOX2 = doutOX2;
	assign outOX3 = doutOX3;
	assign outOX4 = doutOX4;
	assign outOY1 = doutOY1;
	assign outOY2 = doutOY2;
	assign outOY3 = doutOY3;
	assign outOY4 = doutOY4;
	assign outGrid = doutGrid;

	reg imp, imprime;
	/*
	States [0,3]: Initialization;
	States [4,8]: Read of memories;
	States [9,16]: Position X of A;
	States [17,22]: Position X of B;
	States [23,30]: Evaluation;
	State 31: End;
	OBS.: State 32 = Wait state.
	*/

	always @(posedge clk) begin
		if(reset) begin
			reEA <= 0; addrEA <= 0;
			reEB <= 0; addrEB <= 0;
			reOX1 <= 0; addrOX1 <= 0;
			reOY1 <= 0; addrOY1 <= 0;
			reOX2 <= 0; addrOX2 <= 0;
			reOY2 <= 0; addrOY2 <= 0;
			reOX3 <= 0; addrOX3 <= 0;
			reOY3 <= 0; addrOY3 <= 0;
			reOX4 <= 0; addrOX4 <= 0;
			reOY4 <= 0; addrOY4 <= 0;
			rePX <= 0; wePX <= 0; addrPX <= 0; dinPX <= 0;
			rePY <= 0; wePY <= 0; addrPY <= 0; dinPY <= 0;
			reGrid <= 0; weGrid <= 0; addrGrid <= 0; dinGrid <= 0;
			state <= rnd_state; next_state <= init0;
			sum <= 0; cont <= 0; sum_1hop <= 0;
			imp <= 0; imprime <= 0;
			seed <= 99438435458;
		end
		else begin
			cont <= cont + 1;
			reEA <= 0; reEB <= 0;
			reOX1 <= 0; reOY1 <= 0;
			reOX2 <= 0; reOY2 <= 0;
			reOX3 <= 0; reOY3 <= 0;
			reOX4 <= 0; reOY4 <= 0;
			rePX <= 0; wePX <= 0;
			rePY <= 0; wePY <= 0;
			reGrid <= 0; weGrid <= 0;
			//State machine:
			case (state)
				rnd_state: begin
					CASR_reg <= seed;
					LFSR_reg <= seed;
					outbitLFSR <= 1;
					state <= prox_rnd;
				end
				prox_rnd: begin
					CASR_reg <= CASR_reg ^ (CASR_reg-1);
					LFSR_reg <= LFSR_reg ^ outbitLFSR;
					state <= prox_rnd2;
				end
				prox_rnd2: begin
					rnd_number <= CASR_reg ^ LFSR_reg;
					state <= next_state;
				end
				init0: begin
					reEA <= 1; addrEA <= 0;
					state <= waitState;
					next_state <= init1;
				end
				init1: begin
					wePX <= 1; addrPX <= a; dinPX <= rnd_number % n;
					seed <= seed + 1;
					state <= rnd_state;
					next_state <= init4;
				end
				init4: begin
					wePY <= 1; addrPY <= a; dinPY <= rnd_number % n;
					seed <= seed + 1;
					state <= rnd_state;
					next_state <= init2;
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
						k <= rnd_number % WALK;
						seed <= seed + 1;
						reOX1 <= 1; addrOX1 <= j;
						reOX2 <= 1; addrOX2 <= j;
						reOX3 <= 1; addrOX3 <= j;
						reOX4 <= 1; addrOX4 <= j;
						reOY1 <= 1; addrOY1 <= j;
						reOY2 <= 1; addrOY2 <= j;
						reOY3 <= 1; addrOY3 <= j;
						reOY4 <= 1; addrOY4 <= j;
						state <= rnd_state;
						next_state <= posA1;
					end
				end
				posA1: begin
					if(pos_b_X != -1) begin
						if(k == 0) begin
							xi <= pos_b_X + outOX1;
							xj <= pos_b_Y + outOY1;
						end
						else if(k == 1) begin
							xi <= pos_b_X + outOX2;
							xj <= pos_b_Y + outOY2;
						end
						else if(k == 2) begin
							xi <= pos_b_X + outOX3;
							xj <= pos_b_Y + outOY3;
						end
						else if(k == 3) begin
							xi <= pos_b_X + outOX4;
							xj <= pos_b_Y + outOY4;
						end
						state <= posA4;
					end
					else begin
						state <= posA2;
					end
				end
				posA2: begin
					if(k == 0) begin
						xi <= (rnd_number % n) + outOX1;
						seed <= seed + 1;	
					end
					else if(k == 1) begin
						xi <= (rnd_number % n) + outOX2;
						seed <= seed + 1;	
					end
					else if(k == 2) begin
						xi <= (rnd_number % n) + outOX3;
						seed <= seed + 1;	
					end
					else if(k == 3) begin
						xi <= (rnd_number % n) + outOX4;
						seed <= seed + 1;
					end
					state <= rnd_state;
					next_state <= posA3;
				end
				posA3: begin
					if(k == 0) begin
						xj <= (rnd_number % n) + outOY1;
						seed <= seed + 1;
					end
					else if(k == 1) begin
						xj <= (rnd_number % n) + outOY2;
						seed <= seed + 1;	
					end
					else if(k == 2) begin
						xj <= (rnd_number % n) + outOY3;
						seed <= seed + 1;	
					end
					else if(k == 3) begin
						xj <= (rnd_number % n) + outOY4;
						seed <= seed + 1;
					end
					state <= rnd_state;
					next_state <= posA4;
				end
				posA4: begin
					j++;
					aux1 <= xi*n+xj;
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
						wePX <= 1; addrPX <= a; dinPX <= xi;
						wePY <= 1; addrPY <= a; dinPY <= xj;
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
						k <= rnd_number % WALK;
						seed <= seed + 1;
						reOX1 <= 1; addrOX1 <= j;
						reOX2 <= 1; addrOX2 <= j;
						reOX3 <= 1; addrOX3 <= j;
						reOX4 <= 1; addrOX4 <= j;
						reOY1 <= 1; addrOY1 <= j;
						reOY2 <= 1; addrOY2 <= j;
						reOY3 <= 1; addrOY3 <= j;
						reOY4 <= 1; addrOY4 <= j;
						state <= rnd_state;
						next_state <= posB1;
					end
				end
				posB1: begin
					if(k == 0) begin
						xi <= pos_a_X + outOX1;
						xj <= pos_a_Y + outOY1;
					end
					else if(k == 1) begin
						xi <= pos_a_X + outOX2;
						xj <= pos_a_Y + outOY2;
					end
					else if(k == 2) begin
						xi <= pos_a_X + outOX3;
						xj <= pos_a_Y + outOY3;
					end
					else if(k == 3) begin
						xi <= pos_a_X + outOX4;
						xj <= pos_a_Y + outOY4;
					end
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
					$write("\n%d\n",n);
					imprime <= 1;
					out <= 1;
					//$write("\nEvaluation = %1d\nEvaluation 1-hop = %1d\nCycles = %1d\n", sum, sum_1hop, cont);
					//$finish;
				end
				waitState: begin
					state <= next_state;
				end
			endcase
		end
	end
	memoryROM #(.init_file("dados/qspline/eaData.txt"), .data_depth(10)) ea (.clk(clk), .read(reEA), .addr(addrEA), .data(doutEA));
	memoryROM #(.init_file("dados/qspline/ebData.txt"), .data_depth(10)) eb (.clk(clk), .read(reEB), .addr(addrEB), .data(doutEB));
	memoryROM #(.init_file("offsetX1Data.txt"), .data_depth(tam_off_mem)) offset_x1 (.clk(clk), .read(reOX1), .addr(addrOX1), .data(doutOX1));
	memoryROM #(.init_file("offsetX2Data.txt"), .data_depth(tam_off_mem)) offset_x2 (.clk(clk), .read(reOX2), .addr(addrOX2), .data(doutOX2));
	memoryROM #(.init_file("offsetX3Data.txt"), .data_depth(tam_off_mem)) offset_x3 (.clk(clk), .read(reOX3), .addr(addrOX3), .data(doutOX3));
	memoryROM #(.init_file("offsetX4Data.txt"), .data_depth(tam_off_mem)) offset_x4 (.clk(clk), .read(reOX4), .addr(addrOX4), .data(doutOX4));
	memoryROM #(.init_file("offsetY1Data.txt"), .data_depth(tam_off_mem)) offset_y1 (.clk(clk), .read(reOY1), .addr(addrOY1), .data(doutOY1));
	memoryROM #(.init_file("offsetY2Data.txt"), .data_depth(tam_off_mem)) offset_y2 (.clk(clk), .read(reOY2), .addr(addrOY2), .data(doutOY2));
	memoryROM #(.init_file("offsetY3Data.txt"), .data_depth(tam_off_mem)) offset_y3 (.clk(clk), .read(reOY3), .addr(addrOY3), .data(doutOY3));
	memoryROM #(.init_file("offsetY4Data.txt"), .data_depth(tam_off_mem)) offset_y4 (.clk(clk), .read(reOY4), .addr(addrOY4), .data(doutOY4));
	memoryRAM #(.init_file("posData.txt"), .data_depth(tam_pos_mem)) pos_X (.clk(clk), .reset(reset), .read(rePX), .write(wePX), .addr(addrPX), .dataRead(doutPX), .dataWrite(dinPX), .imp(imp));
	memoryRAM #(.init_file("posData.txt"), .data_depth(tam_pos_mem)) pos_Y (.clk(clk), .reset(reset), .read(rePY), .write(wePY), .addr(addrPY), .dataRead(doutPY), .dataWrite(dinPY), .imp(imp));
	memoryRAM #(.init_file("gridData.txt"), .data_depth(n)) grid (.clk(clk), .reset(reset), .read(reGrid), .write(weGrid), .addr(addrGrid), .dataRead(doutGrid), .dataWrite(dinGrid), .imp(imprime));

endmodule

module test;
	reg clk;
	reg reset;
	initial begin
		$dumpfile("random_placement_qspline.vcd");
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
