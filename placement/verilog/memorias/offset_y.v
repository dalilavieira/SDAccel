module offset_y(clk, reset, read, i, data);
  parameter size_offset = 28;
  input clk, reset, read;
  input [32-1:0] i;
  output reg [32-1:0] data;
  reg [32-1:0] offset_y [size_offset-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("offsetYData.txt", offset_y);
    end
    else if(read & ~reset) begin
      data = offset_y[i];
    end
  end
endmodule
