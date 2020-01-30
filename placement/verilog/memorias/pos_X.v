module pos_X(clk, reset, read, write, i, dataRead, dataWrite);
  parameter n_node = 14;
  input clk, reset, read, write;
  input [32-1:0] i, dataWrite;
  output reg [32-1:0] dataRead;
  reg [32-1:0] pos_X [n_node-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("posData.txt", pos_X);
    end
    else if(read & ~reset & ~write) begin
      dataRead = pos_X[i];
    end
    else if(write & ~reset & ~read) begin
      pos_X[i] = dataWrite;
    end
  end
endmodule
