module grid(clk, reset, read, write, i, dataRead, dataWrite);
  parameter n = 4;
  input clk, reset, read, write;
  input [32-1:0] i, dataWrite;
  output reg [32-1:0] dataRead;
  reg [32-1:0] grid [n*n-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("gridData.txt", grid);
    end
    else if(read & ~reset & ~write) begin
      dataRead = grid[i];
    end
    else if(write & ~reset & ~read) begin
      grid[i] = dataWrite;
    end
  end
endmodule
