module e_a(clk, reset, read, i, data);
  parameter n_edge = 15;
  input clk, reset, read;
  input [32-1:0] i;
  output reg [32-1:0] data;
  reg [32-1:0] e_a [n_edge-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("eaData.txt", e_a);
    end
    else if(read & ~reset) begin
      data <= e_a[i];
    end
  end
endmodule
