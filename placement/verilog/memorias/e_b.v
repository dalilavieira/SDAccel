module e_b(clk, reset, read, i, data);
  parameter n_edge = 15;
  input clk, reset, read;
  input [32-1:0] i;
  output reg [32-1:0] data;
  reg [32-1:0] e_b [n_edge-1:0];
  always @ (posedge clk) begin
    if(reset) begin
      $readmemh("ebData.txt", e_b);
    end
    else if(read & ~reset) begin
      data <= e_b[i];
    end
  end
endmodule
