`include "memorias/memoryROM.v"
`include "memorias/memoryRAM.v"

module placement(out, clk, reset);
	input clk, reset;
	output reg out;
	parameter n = 4, n_edge = 15, n_node = 14, size_offset = 28;
	//Controles:
	reg reEA, reEB, reOX, reOY, rePX, rePY, reGrid;
	reg signed [32-1:0] addrEA, addrEB, addrOX, addrOY, addrPX, addrPY, addrGrid;
	wire signed [32-1:0] doutEA, doutEB, doutOX, doutOY, doutPX, doutPY, doutGrid;
	reg wePX, wePY, weGrid;
	reg signed [32-1:0] dinPX, dinPY, dinGrid;
	wire [32-1:0] outPX, outPY, outOX, outOY, outGrid;
	//Registradores e fios:
	reg [32-1:0] state, i, j;
	reg [32-1:0] aux1, aux2, aux3, aux4;
	reg signed [32-1:0] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;
	wire signed [32-1:0] a, b;
	reg signed [32-1:0] xi, xj;
	reg signed [32-1:0] sum;
	reg signed [32-1:0] diff_pos_x, diff_pos_y;
	//Atribuição das saídas das memórias:
	assign a = doutEA;
	assign b = doutEB;
	assign outPX = doutPX;
	assign outPY = doutPY;
	assign outOX = doutOX;
	assign outOY = doutOY;
	assign outGrid = doutGrid;

	/*
		Estados 0 ao 6: Inicialização;
		Estados 7 ao 14: Leitura das memórias;
		Estados 15 ao 25: Posição X de A;
		Estados 26 ao 34: Posição X de B;
		Estados 35 ao 47: Avaliação;
		Estado 48: Final;
		OBS.: Estados 1,4,8,10,13,16,20,23,27,32,36,38,41 = Estados de espera.
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
			diff_pos_x <= 0; diff_pos_y <= 0;
			state <= 0;
			sum <= 0;
		end
		else begin
			case (state)
				0: begin
					reEA <= 1; addrEA <= 0;
					state <= 1;
				end
				1: begin
					reEA <= 0;
					state <= 2;
				end
				2: begin
					rePX <= 0; wePX <= 1; addrPX <= a; dinPX <= 0;
					rePY <= 0; wePY <= 1; addrPY <= a; dinPY <= 0;
					state <= 3;
				end
				3: begin
					wePX <= 0; rePX <= 1; addrPX <= 0;
					wePY <= 0; rePY <= 1; addrPY <= 0;
					i <= 0;
					j <= 0;
					state <= 4;
				end
				4: begin
					rePX <= 0; rePY <= 0;
					state <= 5;
				end
				5: begin
					aux3 <= outPX*n+outPY;
					state <= 6;
				end
				6: begin
					reGrid <= 0; weGrid <= 1; addrGrid <= aux3; dinGrid <= a;
					state <= 7;
				end
				7: begin
					if(i == n_edge) begin
						i <= 0;
						state <= 35;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= 8;
					end
				end
				8: begin
					reEA <= 0; reEB <= 0;
					state <= 9;
				end
				9: begin
					wePX <= 0; rePX <= 1; addrPX <= a;
					wePY <= 0; rePY <= 1; addrPY <= a;
					state <= 10;
				end
				10: begin
					rePX <= 0; rePY <= 0;
					state <= 11;
				end
				11: begin
					pos_a_X <= outPX;
					pos_a_Y <= outPY;
					state <= 12;
				end
				12: begin
					wePX <= 0; rePX <= 1; addrPX <= b;
					wePY <= 0; rePY <= 1; addrPY <= b;
					state <= 13;
				end
				13: begin
					rePX <= 0; rePY <= 0;
					state <= 14;
				end
				14: begin
					pos_b_X <= outPX;
					pos_b_Y <= outPY;
					if(i==0) begin
						state <= 26;
					end
					else begin
						state <= 15;
					end
				end
				15: begin
					if(pos_a_X != -1) begin
	          state <= 26;
				 		j <= 0;
			  	end
					else begin
						wePX <= 0; rePX <= 1; addrPX <= i-1;
						reOX <= 1; addrOX <= j;
						wePY <= 0; rePY <= 1; addrPY <= i-1;
						reOY <= 1; addrOY <= j;
						state <= 16;
					end
				end
				16: begin
					rePX <= 0; reOX <= 0;
					rePY <= 0; reOY <= 0;
					state <= 17;
				end
				17: begin
					aux1 <= outPX + outOX;
					aux3 <= outPY + outOY;
					state <= 18;
				end
				18: begin
					rePX <= 0; wePX <= 1; addrPX <= a; dinPX <= aux1;
					rePY <= 0; wePY <= 1; addrPY <= a; dinPY <= aux3;
					state <= 19;
				end
				19: begin
					wePX <= 0; rePX <= 1; addrPX <= a;
					wePY <= 0; rePY <= 1; addrPY <= a;
					j++;
					state <= 20;
				end
				20: begin
					rePX <= 0; rePY <= 0;
					state <= 21;
				end
				21: begin
					xi <= outPX;
					xj <= outPY;
					aux1 <= outPX*n+outPY;
					state <= 22;
				end
				22: begin
					weGrid <= 0; reGrid <= 1; addrGrid <= aux1;
					state <= 23;
				end
				23: begin
					reGrid <= 0;
					state <= 24;
				end
				24: begin
					aux2 <= outGrid;
					state <= 25;
				end
				25: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						reGrid <= 0; weGrid <= 1; addrGrid <= aux1; dinGrid <= a;
						pos_a_X <= xi;
						pos_a_Y <= xj;
						state <= 26;
						j <= 0;
					end
					else if(pos_a_X == -1) begin
						state <= 15;
					end
					if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= 48;
					end
				end
				26: begin
					if(pos_b_X != -1) begin
						state <= 7;
						j <= 0;
						i++;
					end
					else begin
						reOX <= 1; addrOX <= j;
						reOY <= 1; addrOY <= j;
						state <= 27;
					end
				end
				27: begin
					reOX <= 0; reOY <= 0;
					state <= 28;
				end
				28: begin
					aux1 <= outOX;
					aux2 <= outOY;
					state <= 29;
				end
				29: begin
					xi <= pos_a_X + aux1;
					xj <= pos_a_Y + aux2;
					state <= 30;
				end
				30: begin
					aux1 <= xi*n+xj;
					state <= 31;
				end
				31: begin
					j++;
					weGrid <= 0; reGrid <= 1; addrGrid <= aux1;
					state <= 32;
				end
				32: begin
					reGrid <= 0;
					state <= 33;
				end
				33: begin
					aux2 <= outGrid;
					state <= 34;
				end
				34: begin
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						reGrid <= 0; weGrid <= 1; addrGrid <= aux1; dinGrid <= b;
						pos_b_X <= xi;
						pos_b_Y <= xj;
						rePX <= 0; wePX <= 1; addrPX <= b; dinPX <= xi;
						rePY <= 0; wePY <= 1; addrPY <= b; dinPY <= xj;
						j <= 0;
						i++;
						state <= 7;
					end
					else if(pos_b_X == -1) begin
						state <= 26;
					end
					if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= 48;
					end
				end
				35: begin
					if(i == n_edge) begin
					 	state <= 48;
					end
					else begin
						reEA <= 1; addrEA <= i;
						reEB <= 1; addrEB <= i;
						state <= 36;
					end
				end
				36: begin
					reEA <= 0; reEB <= 0;
					state <= 37;
				end
				37: begin
					wePX <= 0; rePX <= 1; addrPX <= a;
					wePY <= 0; rePY <= 1; addrPY <= a;
					state <= 38;
				end
				38: begin
					rePX <= 0; rePY <= 0;
					state <= 39;
				end
				39: begin
					aux1 <= outPX;
					aux2 <= outPY;
					state <= 40;
				end
				40: begin
					wePX <= 0; rePX <= 1; addrPX <= b;
					wePY <= 0; rePY <= 1; addrPY <= b;
					state <= 41;
				end
				41: begin
					rePX <= 0; rePY <= 0;
					state <= 42;
				end
				42: begin
					aux3 <= outPX;
					aux4 <= outPY;
					state <= 43;
				end
				43: begin
					diff_pos_x <= aux1 - aux3;
					state <= 44;
				end
				44: begin
					if(diff_pos_x < 0) begin
						diff_pos_x <= (diff_pos_x ^ (32'b11111111111111111111111111111111)) + 1;
					end
					state <= 45;
				end
				45: begin
					diff_pos_y <= aux2 - aux4;
					state <= 46;
				end
				46: begin
					if(diff_pos_y < 0) begin
						diff_pos_y <= (diff_pos_y ^ (32'b11111111111111111111111111111111)) + 1;
					end
					state <= 47;
				end
				47: begin
					sum += diff_pos_x + diff_pos_y - 1;
					i++;
					state <= 35;
				end
				48: begin
					out <= 1;
					$write("\nEvaluation = %1d\n", sum);
					$finish;
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
	initial begin
    $dumpfile("placement.vcd");
    $dumpvars;
	end
endmodule

module test;
	reg clk;
	reg reset;
	initial begin
		clk = 0;
		reset = 0;
		#1 reset = 1;
		#2 reset = 0;
	end
	always #1 clk = !clk;
	wire out;
	placement p1 (out, clk, reset);
endmodule
