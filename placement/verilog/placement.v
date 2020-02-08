`include "memorias/memoryROM.v"
`include "memorias/memoryRAM.v"

module placement(out, clk, reset);
	input clk, reset;
	output reg out;
	parameter n0 = 4, n = n0*n0, n_edge = 15, n_node = 14, size_offset = 28;
	//Controles:
	reg reEA, reEB, reOX, reOY, rePX, rePY, reGrid;
	reg signed [32-1:0] addrEA, addrEB, addrOX, addrOY, addrPX, addrPY, addrGrid;
	wire signed [32-1:0] doutEA, doutEB, doutOX, doutOY, doutPX, doutPY, doutGrid;
	reg wePX, wePY, weGrid;
	reg signed [32-1:0] dinPX, dinPY, dinGrid;
	//Registradores:
	reg [16-1:0] state;
	reg [32-1:0] i, j, aux1, aux2, aux3, aux4;
	reg signed [32-1:0] pos_a_X, pos_a_Y, pos_b_X, pos_b_Y;
	reg signed [32-1:0] a, b;
	reg signed [32-1:0] xi, xj;
	reg signed [32-1:0] sum;
	reg signed [32-1:0] diff_pos_x, diff_pos_y;

	always @(posedge clk) begin
		if(reset) begin
			reEA <= 0; addrEA <= 0;
			reEB <= 0; addrEB <= 0;
			reOX <= 0; addrOX <= 0;
			reOY <= 0; addrOY <= 0;
			rePX <= 0; wePX <= 0; addrPX <= 0; dinPX <= 0;
			rePY <= 0; wePY <= 0; addrPY <= 0; dinPY <= 0;
			reGrid <= 0; weGrid <= 0; addrGrid <= 0; dinGrid <= 0;
			state <= 0;
			sum <= 0;
		end
		else begin
			case (state)
				0: begin //Inicializações
					$write("s 0\n");
					reEA <= 1; addrEA <= 0; a <= doutEA; //a = e_a[0]
					wePX <= 1; addrPX <= a; dinPX <= 0; //pos_X[a] = 0
					wePY <= 1; addrPY <= a; dinPY <= 0; //pos_Y[a] = 0
					state <= 1;
				end
				1: begin //Inicializações
					$write("s 1\n");
					rePX <= 1; addrPX <= 0; aux1 <= doutPX; //aux1 = pos_X[0] 
					rePY <= 1; addrPY <= 0; aux2 <= doutPY; //aux2 = pos_Y[0]
					i <= 0;
					j <= 0;
					state <= 11;
				end
				11: begin //Intro ao estado 2
					$write("s 11\n");
					aux3 = aux1*n+aux2; //pos_X[0] * n + pos_Y[0]
					weGrid <= 1; addrGrid <= aux3; dinGrid <= a; //grid[pos_X[0] * n + pos_Y[0]] = a
					state <= 2;
				end
				2: begin //Leitura das memórias
					$write("s 2\n");
					if(i == n_edge) begin
						i <= 0;
						state <= 8;
					end
					else begin
						reEA <= 1; addrEA <= i; a <= doutEA; //a = e_a[i]
						reEB <= 1; addrEB <= i; b <= doutEB; //b = e_b[i]
						state <= 3;
					end
				end
				3: begin //Leitura das memórias
					$write("s 3\n");
					rePX <= 1; addrPX <= a; pos_a_X <= doutPX; //pos_a_X <= pos_X[a]
					rePY <= 1; addrPY <= a; pos_a_Y <= doutPY; //pos_a_Y <= pos_Y[a]
					rePX <= 1; addrPX <= b; pos_b_X <= doutPX; //pos_b_X = pos_X[b]
					rePY <= 1; addrPY <= b; pos_b_Y <= doutPY; //pos_b_Y = pos_Y[b]
					if(i==0) begin
						state <= 7;
					end
					else begin
						state <= 4;
					end
				end
				4: begin //Posição X de a
					$write("s4\n");
					if(pos_a_X != -1) begin
	          				state <= 7;
					 	j <= 0;
					end
					else begin
						rePX <= 1; addrPX <= i-1; aux1 <= doutPX; //aux1 = pos_X[i-1]
						reOX <= 1; addrOX <= j; aux2 <= doutOX; //aux2 = offset_x[j]
						rePY <= 1; addrPY <= i-1; aux3 <= doutPY; //aux3 = pos_Y[i-1]
						reOY <= 1; addrOY <= j; aux4 <= doutOY; //aux4 = offset_y[j]
						aux1 = aux1 + aux2; //pos_X[i-1] + offset_x[j]   //OBS: talvez precise de outro estado
						aux3 = aux3 + aux4; //pos_Y[i-1] + offset_y[j]
						state <= 5;
					end
				end
				5: begin //Posição x de a
					$write("s 5\n");
					wePX <= 1; addrPX <= a; dinPX <= aux1; //pos_X[a] = pos_X[i-1] + offset_x[j]
					wePY <= 1; addrPY <= a; dinPY <= aux3; //pos_Y[a] = pos_Y[i-1] + offset_y[j]
					state <= 12;
				end
				12: begin //Intro ao estado 6
					$write("s 12\n");
					rePX <= 1; addrPX <= a; xi <= doutPX; //xi = pos_X[a]
					rePY <= 1; addrPY <= a; xj <= doutPY; //xj = pos_Y[a]
					j++;
					aux1 = xi*n+xj;  //OBS: talvez pudesse ser criado outro estado, garantir que xi e xj foram atualizados antes
					reGrid <= 1; addrGrid <= aux1; aux2 <= doutGrid; //aux2 = grid[xi*n+j]
					state <= 6;
				end
				6: begin //Posição x de a
					$write("s 6\n");
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= a; //grid[xi*n+j] = a
						pos_a_X <= xi;
						pos_a_Y <= xj;
					end
					else if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= 10;
					end
					else begin
						state <= 4;
					end
				end
				7://Posição X de b
				begin
					$write("s 7\n");
					if(pos_b_X != -1) begin
						state <= 11;
						j <= 0;
						i++;
					end
					else begin
						reOX <= 1; addrOX <= j; aux1 <= doutOX; //aux1 = offset_x[j]
						reOY <= 1; addrOY <= j; aux2 <= doutOY; //aux2 = offset_y[j]
						state <= 13;
					end
				end
				13: begin
					state <= 14;
					xi <= pos_a_X + aux1;
					xj <= pos_a_Y + aux2;
					aux1 = xi*n+xj; //talvez precise de um estado pra isso
				end
				14: begin 
					$write("s 13\n");
					j++;
					reGrid <= 1; addrGrid <= aux1; aux2 <= doutGrid; //aux2 = grid[xi*n+j]
					if(aux2 == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) begin
						weGrid <= 1; addrGrid <= aux1; dinGrid <= b; //grid[xi*n+j] = b
						pos_b_X <= xi;
						pos_b_Y <= xj;
						wePX <= 1; addrPX <= b; dinPX <= xi; //pos_X[b] = xi
						wePY <= 1; addrPY <= b; dinPY <= xj; //pos_Y[b] = xj
						state <= 11;
						j <= 0;
						i++;
					end
					else if(pos_b_X == -1) begin
						state = 7;
					end
					else if(j > size_offset) begin
						$display("No solution\n");
						out <= 0;
						state <= 10;
					end
				end
				8://Evaluation
				begin
					$write("s 8\n");
					if(i == n_edge) begin
					 	state <= 10;
					end
					else begin
						reEA <= 1; addrEA <= i; a <= doutEA; //a = e_a[i]
						reEB <= 1; addrEB <= i; b <= doutEB; //b = e_b[i]
						state <= 15;
					end
				end
				15: begin
					$write("s 15\n");
					rePX <= 1; addrPX <= a; aux1 <= doutPX; //aux1 = pos_X[a]
					rePY <= 1; addrPY <= a; aux2 <= doutPY; //aux2 = pos_Y[a]
					rePX <= 1; addrPX <= b; aux3 <= doutPX; //aux3 = pos_X[b]
					rePY <= 1; addrPY <= b; aux4 <= doutPY; //aux4 = pos_Y[b]
					state <= 9;
				end
				9: begin //Evaluation
					$write("s 9\n");
					diff_pos_x = aux1-aux3;
					if(diff_pos_x < 0) begin
						diff_pos_x *= -1;
					end
					diff_pos_y = aux2-aux4;
					if(diff_pos_y < 0) begin
						diff_pos_y *= -1;
					end
					sum = diff_pos_x + diff_pos_y - 1;
					i++;
					state <= 8;
				end
				10: //display existe apenas na simulação
				begin
					$write("\nEvaluation = %1d\n", sum);
					out <= 1;
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
endmodule

module test;
	reg clk;
	reg reset;
	initial begin
    $dumpfile("placement.vcd");
    $dumpvars(0, test);
		clk = 0;
		reset = 0;
		#1 reset = 1;
		#2 reset = 0;
	end
	always #1 clk = !clk;
	wire out;
	placement p1 (out, clk, reset);
endmodule
