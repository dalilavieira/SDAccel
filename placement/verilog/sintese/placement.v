`include "memorias/memoryROM.v"
`include "memorias/memoryRAM.v"

module placement(out, clk, reset, evalResult);
	input clk, reset;
	output reg out;
	output reg [32-1:0] evalResult;
	parameter n = 4, n_edge = 15, size_offset = 28;
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
	reg signed [32-1:0] sum;
	reg signed [32-1:0] diff_pos_x, diff_pos_y;
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
			sum <= 0;
		end
		else begin
			reEA <= 0; reEB <= 0;
			reOX <= 0; reOY <= 0;
			rePX <= 0; wePX <= 0;
			rePY <= 0; wePY <= 0;
			reGrid <= 0; weGrid <= 0;
			//State machine:
			case (state)
				0: begin
					reEA <= 1; addrEA <= 0;
					state <= 1;
				end
				1: begin
					wePX <= 1; addrPX <= a; dinPX <= 0;
					wePY <= 1; addrPY <= a; dinPY <= 0;
					state <= 2;
				end
				2: begin
					rePX <= 1; addrPX <= 0;
					rePY <= 1; addrPY <= 0;
					i <= 0;
					j <= 0;
					state <= 32;
					next_state <= 3;
				end
				3: begin
					weGrid <= 1; addrGrid <= outPX*n+outPY; dinGrid <= a;
					state <= 4;
				end
				4: begin
					if(i == n_edge) begin
						i <= 0;
						state <= 23;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= 32;
						next_state <= 5;
					end
				end
				5: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					state <= 32;
					next_state <= 6;
				end
				6: begin
					pos_a_X <= outPX;
					pos_a_Y <= outPY;
					state <= 7;
					next_state <= 8;
				end
				7: begin
					rePX <= 1; addrPX <= b;
					rePY <= 1; addrPY <= b;
					state <= 32;
				end
				8: begin
					pos_b_X <= outPX;
					pos_b_Y <= outPY;
					if(i==0) begin
						state <= 17;
					end
					else begin
						state <= 9;
					end
				end
				9: begin
					if(pos_a_X != -1) begin
	          state <= 17;
				 		j <= 0;
			  		end
					else begin
						rePX <= 1; addrPX <= i-1;
						reOX <= 1; addrOX <= j;
						rePY <= 1; addrPY <= i-1;
						reOY <= 1; addrOY <= j;
						state <= 32;
						next_state <= 10;
					end
				end
				10: begin
					aux1 <= outPX + outOX;
					aux3 <= outPY + outOY;
					state <= 11;
				end
				11: begin
					wePX <= 1; addrPX <= a; dinPX <= aux1;
					wePY <= 1; addrPY <= a; dinPY <= aux3;
					state <= 12;
				end
				12: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					j++;
					state <= 32;
					next_state <= 13;
				end
				13: begin
					xi <= outPX;
					xj <= outPY;
					aux1 <= outPX*n+outPY;
					state <= 14;
				end
				14: begin
					reGrid <= 1; addrGrid <= aux1;
					state <= 32;
					next_state <= 15;
				end
				15: begin
					aux2 <= outGrid;
					state <= 16;
				end
				16: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= a;
						pos_a_X <= xi;
						pos_a_Y <= xj;
						state <= 17;
						j <= 0;
					end
					else if(pos_a_X == -1) begin
						state <= 9;
					end
					if(j > size_offset) begin
						out <= 0;
						state <= 31;
					end
				end
				17: begin
					if(pos_b_X != -1) begin
						state <= 4;
						j <= 0;
						i++;
					end
					else begin
						reOX <= 1; addrOX <= j;
						reOY <= 1; addrOY <= j;
						state <= 32;
						next_state <= 18;
					end
				end
				18: begin
					xi <= pos_a_X + outOX;
					xj <= pos_a_Y + outOY;
					state <= 19;
				end
				19: begin
					aux1 <= xi*n+xj;
					state <= 20;
				end
				20: begin
					j++;
					reGrid <= 1; addrGrid <= aux1;
					state <= 32;
					next_state <= 21;
				end
				21: begin
					aux2 <= outGrid;
					state <= 22;
				end
				22: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= b;
						pos_b_X <= xi;
						pos_b_Y <= xj;
						wePX <= 1; addrPX <= b; dinPX <= xi;
						wePY <= 1; addrPY <= b; dinPY <= xj;
						j <= 0;
						i++;
						state <= 4;
					end
					else if(pos_b_X == -1) begin
						state <= 17;
					end
					if(j > size_offset) begin
						out <= 0;
						state <= 31;
					end
				end
				23: begin
					if(i == n_edge) begin
					 	state <= 31;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= 32;
						next_state <= 24;
					end
				end
				24: begin
					rePX <= 1; addrPX <= a;
					rePY <= 1; addrPY <= a;
					state <= 32;
					next_state <= 25;
				end
				25: begin
					aux1 <= outPX;
					aux2 <= outPY;
					state <= 7;
					next_state <= 26;
				end
				26: begin
					aux3 <= outPX;
					aux4 <= outPY;
					state <= 27;
				end
				27: begin
					diff_pos_x <= aux1 - aux3;
					state <= 28;
				end
				28: begin
					if(diff_pos_x < 0) begin
						diff_pos_x <= (diff_pos_x ^ (32'b11111111111111111111111111111111)) + 1;
					end
					diff_pos_y <= aux2 - aux4;
					state <= 29;
				end
				29: begin
					if(diff_pos_y < 0) begin
						diff_pos_y <= (diff_pos_y ^ (32'b11111111111111111111111111111111)) + 1;
					end
					state <= 30;
				end
				30: begin
					sum += diff_pos_x + diff_pos_y - 1;
					i++;
					state <= 23;
				end
				31: begin
					out <= 1;
					evalResult <= sum;
					state <= 0;
				end
				32: begin
					state <= next_state;
				end
			endcase
		end
	end
	memoryROM #(.init_file("dados/eaData.txt"), .data_depth(4)) ea (.clk(clk), .read(reEA), .addr(addrEA), .data(doutEA));
	memoryROM #(.init_file("dados/ebData.txt"), .data_depth(4)) eb (.clk(clk), .read(reEB), .addr(addrEB), .data(doutEB));
	memoryROM #(.init_file("dados/offsetXData.txt"), .data_depth(5)) offset_x (.clk(clk), .read(reOX), .addr(addrOX), .data(doutOX));
	memoryROM #(.init_file("dados/offsetYData.txt"), .data_depth(5)) offset_y (.clk(clk), .read(reOY), .addr(addrOY), .data(doutOY));
	memoryRAM #(.init_file("dados/posData.txt"), .data_depth(4)) pos_X (.clk(clk), .read(rePX), .write(wePX), .addr(addrPX), .dataRead(doutPX), .dataWrite(dinPX));
	memoryRAM #(.init_file("dados/posData.txt"), .data_depth(4)) pos_Y (.clk(clk), .read(rePY), .write(wePY), .addr(addrPY), .dataRead(doutPY), .dataWrite(dinPY));
	memoryRAM #(.init_file("dados/gridData.txt"), .data_depth(4)) grid (.clk(clk), .read(reGrid), .write(weGrid), .addr(addrGrid), .dataRead(doutGrid), .dataWrite(dinGrid));
endmodule
