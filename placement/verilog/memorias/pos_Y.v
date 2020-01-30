module pos_Y(clk, reset, read, write, i, dataRead, dataWrite);
  parameter n_node = 14;
  input clk, reset, read, write;
  input [32-1:0] i, dataWrite;
  output reg [32-1:0] dataRead;
  reg [32-1:0] pos_Y [n_node-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("posData.txt", pos_Y);
    end
    else if(read & ~reset) begin
      dataRead = pos_Y[i];
    end
    else if(write & ~reset & ~read) begin
      pos_Y[i] = dataWrite;
    end
  end
endmodule
