#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_node, n_edge, n, size_offset; //parâmetros?
  n_node = 11;
  n_edge = 11;
  n = 4;
  size_offset = 28;
  int state, i, j, pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, a, b, xi, xj;
  int sum=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
  int offset_x[size_offset], offset_y[size_offset];
  state = 0;
  while(state != 5){
    switch(state){
      case 0://Inicializações
        e_a[0] = 0; e_b[0] = 3;
        e_a[1] = 1; e_b[1] = 4;
        e_a[2] = 2; e_b[2] = 5;
        e_a[3] = 3; e_b[3] = 6;
        e_a[4] = 4; e_b[4] = 7;
        e_a[5] = 5; e_b[5] = 3;
        e_a[6] = 5; e_b[6] = 4;
        e_a[7] = 6; e_b[7] = 8;
        e_a[8] = 7; e_b[8] = 8;
        e_a[9] = 8; e_b[9] = 9;
        e_a[10] = 9; e_b[10] = 10;

        offset_x[0] = 0; offset_y[0] = 1;
        offset_x[1] = 1; offset_y[1] = 0;
        offset_x[2] = 0; offset_y[2] = -1;
        offset_x[3] = -1; offset_y[3] = 0;
        offset_x[4] = -1; offset_y[4] = 1;
        offset_x[5] = 1; offset_y[5] = 1;
        offset_x[6] = 1; offset_y[6] = -1;
        offset_x[7] = -1; offset_y[7] = -1;
        offset_x[8] = 0; offset_y[8] = 2;
        offset_x[9] = 2; offset_y[9] = 0;
        offset_x[10] = 0; offset_y[10] = -2;
        offset_x[11] = -2; offset_y[11] = 0;
        offset_x[12] = -1; offset_y[12] = 2;
        offset_x[13] = 1; offset_y[13] = 2;
        offset_x[14] = 1; offset_y[14] = -2;
        offset_x[15] = -1; offset_y[15] = -2;
        offset_x[16] = -2; offset_y[16] = 1;
        offset_x[17] = 2; offset_y[17] = 1;
        offset_x[18] = 2; offset_y[18] = -1;
        offset_x[19] = -2; offset_y[19] = -1;
        offset_x[20] = 0; offset_y[20] = 4;
        offset_x[21] = 4; offset_y[21] = 0;
        offset_x[22] = 0; offset_y[22] = -4;
        offset_x[23] = -4; offset_y[23] = 0;
        offset_x[24] = 1; offset_y[24] = 3;
        offset_x[25] = 1; offset_y[25] = -3;
        offset_x[26] = -1; offset_y[26] = -3;
        offset_x[27] = -1; offset_y[27] = 3;

        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
            grid[i][j] = -1;
          }
        }
        for(i=0; i<n_node; i++){
          pos_X[i] = -1;
          pos_Y[i] = -1;
        }
        a = e_a[0];
        pos_X[a] = 0;
        pos_Y[a] = 0;
        grid[pos_X[a]][pos_Y[a]] = a;
        i=0;
        j=0;
        state = 1;
        break;
      case 1://Leitura das memórias
        /*Aqui acho que será dividido em mais
        estados devido aos acessos às memórias!*/
        if(i == n_edge){
          state = 4;
          i=0;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        pos_a_X = pos_X[a];
        pos_a_Y = pos_Y[a];
        pos_b_X = pos_X[b];
        pos_b_Y = pos_Y[b];
        //state = 2;
        if(i==0){
          state = 3;
        }
        else{
          state = 2;
        }
        break;
      case 2://Posição X de a
        if(pos_a_X != -1){
          state = 3;
          j=0;
          break;
        }
        pos_X[a] = pos_X[i-1] + offset_x[j];//Em verilog pode haver conflito eu acho!
        pos_Y[a] = pos_Y[i-1] + offset_y[j];//Em verilog pode haver conflito eu acho!
        xi = pos_X[a];
        xj = pos_Y[a];
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = a;
          pos_a_X = xi;
          pos_a_Y = xj;
        }
        else if(j > size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_a_X == -1){
          state = 2;
        }
        else{
          state = 3;
          j=0;
        }
        break;
      case 3://Posição X de b
        if(pos_b_X != -1){
          state = 1;
          j=0;
          i++;
          break;
        }
        xi = pos_a_X + offset_x[j];
        xj = pos_a_Y + offset_y[j];
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = b;
          pos_b_X = xi;
          pos_b_Y = xj;
          pos_X[b] = xi;
          pos_Y[b] = xj;
          state = 1;
          j=0;
          i++;
          break;
        }
        else if(j > size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_b_X == -1){
          state = 3;
        }
        else{
          state = 1;
          j=0;
          i++;
        }
        break;
      case 4://Evaluation
        if(i == n_edge){
          state = 5;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        diff_pos_x = pos_X[a]-pos_X[b];
        if(diff_pos_x < 0){
          diff_pos_x *= -1;
        }
        diff_pos_y = pos_Y[a]-pos_Y[b];
        if(diff_pos_y < 0){
          diff_pos_y *= -1;
        }
        sum += diff_pos_x + diff_pos_y - 1;
        sum_1hop += (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;
        i++;
        break;
    }
  }
  //Exibindo o grid:
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%3d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\nEvaluation = %d\nEvaluation 1-hop = %d\n", sum, sum_1hop);
  return 1;
}
