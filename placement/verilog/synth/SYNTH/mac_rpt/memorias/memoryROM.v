module memoryROM #(
  parameter init_file = "mem_file.txt",
  parameter data_depth = 5
  )
  (clk, read, addr, data);
  input clk, read;
  input signed [32-1:0] addr;
  output reg signed [32-1:0] data;
 // parameter [5:1] data_depth = 5;
  reg signed [32-1:0] memROM [(2**data_depth)-1:0];
  always @ (posedge clk) begin
    if(read) begin
      data <= memROM[addr];
    end
  end
  initial begin
    data = 0;
    $readmemh(init_file, memROM, 0, (2**data_depth)-1);
  end
endmodule
