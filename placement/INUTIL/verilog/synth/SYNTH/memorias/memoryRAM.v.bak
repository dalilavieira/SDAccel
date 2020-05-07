module memoryRAM #(
  parameter init_file = "mem_file.txt",
  parameter data_depth = 4
  )(clk, read, write, addr, dataRead, dataWrite);
  input clk, read, write;
  input signed [32-1:0] addr, dataWrite;
  output reg signed [32-1:0] dataRead;
  reg signed [32-1:0] memRAM [(2**data_depth)-1:0];
  reg [32-1:0] i, j;
  always @ (posedge clk) begin
    dataRead <= 0;
    if(read) begin
      dataRead <= memRAM[addr];
    end
    if(write) begin
      memRAM[addr] <= dataWrite;
    end
    /*$display();
    for(i=0; i<4; i++) begin
			for(j=0; j<4; j++) begin
				$write("%4d", $signed(memRAM[i*4+j]));
			end
		  $display();
    end*/
  end
  initial begin
    dataRead = 0;
    $readmemh(init_file, memRAM, 0, (2**data_depth)-1);
  end
endmodule
