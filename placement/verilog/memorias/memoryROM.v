module memoryROM #(
  parameter init_file = "mem_file.txt",
  parameter data_depth = 15
  )(clk, read, addr, data);
  input clk, read;
  input [32-1:0] addr;
  output reg [32-1:0] data;
  reg  [32-1:0] memROM [data_depth-1:0];
  always @ (posedge clk) begin
    if(read) begin
      data <= memROM[addr];
    end
  end
  initial begin
    data = 0;
    $readmemh(init_file, memROM);
  end
endmodule
