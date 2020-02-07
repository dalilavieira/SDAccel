module memoryRAM #(
  parameter init_file = "mem_file.txt",
  parameter data_depth = 14
  )(clk, read, write, addr, dataRead, dataWrite);
  input clk, read, write;
  input [32-1:0] addr, dataWrite;
  output reg [32-1:0] dataRead;
  reg signed [32-1:0] memRAM [data_depth-1:0];
  always @ (posedge clk) begin
    dataRead <= 0;
    if(read) begin
      dataRead <= memRAM[addr];
    end
    if(write) begin
      memRAM[addr] <= dataWrite;
    end
  end
  initial begin
    dataRead = 0;
    $readmemh(init_file, memRAM);
  end
endmodule
