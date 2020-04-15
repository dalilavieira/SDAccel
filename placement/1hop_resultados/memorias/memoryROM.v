module memoryROM #(
  parameter init_file = "mem_file.txt",
  parameter data_depth = 5
  )(clk, reset, read, addr, data);
  input clk, reset, read;
  input signed [32-1:0] addr;
  output reg signed [32-1:0] data;
  reg signed [32-1:0] memROM [(2**data_depth)-1:0];
  always @ (posedge clk) begin
    if(reset) begin
	data = 0;
        $readmemh(init_file, memROM, 0, (2**data_depth)-1);
    end
    else begin
        if(read) begin
            data <= memROM[addr];
        end
    end
  end
endmodule
