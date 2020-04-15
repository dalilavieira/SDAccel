#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_node, n_edge, n, size_offset; //parâmetros?
  n_node = 62;
  n_edge = 76;
  n = 8;
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
        e_a[0] = 0; e_b[0] = 24;
        e_a[1] = 1; e_b[1] = 25;
        e_a[2] = 2; e_b[2] = 26;
        e_a[3] = 3; e_b[3] = 27;
        e_a[4] = 4; e_b[4] = 28;
        e_a[5] = 5; e_b[5] = 29;
        e_a[6] = 6; e_b[6] = 30;
        e_a[7] = 7; e_b[7] = 31;
        e_a[8] = 8; e_b[8] = 24;
        e_a[9] = 8; e_b[9] = 28;
        e_a[10] = 8; e_b[10] = 32;
        e_a[11] = 8; e_b[11] = 33;
        e_a[12] = 9; e_b[12] = 25;
        e_a[13] = 9; e_b[13] = 29;
        e_a[14] = 9; e_b[14] = 34;
        e_a[15] = 9; e_b[15] = 35;
        e_a[16] = 10; e_b[16] = 26;
        e_a[17] = 10; e_b[17] = 30;
        e_a[18] = 10; e_b[18] = 36;
        e_a[19] = 10; e_b[19] = 37;
        e_a[20] = 11; e_b[20] = 27;
        e_a[21] = 11; e_b[21] = 31;
        e_a[22] = 11; e_b[22] = 38;
        e_a[23] = 11; e_b[23] = 39;
        e_a[24] = 12; e_b[24] = 32;
        e_a[25] = 13; e_b[25] = 34;
        e_a[26] = 14; e_b[26] = 36;
        e_a[27] = 15; e_b[27] = 38;
        e_a[28] = 16; e_b[28] = 33;
        e_a[29] = 17; e_b[29] = 35;
        e_a[30] = 18; e_b[30] = 37;
        e_a[31] = 19; e_b[31] = 39;
        e_a[32] = 20; e_b[32] = 40;
        e_a[33] = 21; e_b[33] = 40;
        e_a[34] = 22; e_b[34] = 41;
        e_a[35] = 23; e_b[35] = 41;
        e_a[36] = 24; e_b[36] = 42;
        e_a[37] = 25; e_b[37] = 42;
        e_a[38] = 26; e_b[38] = 43;
        e_a[39] = 27; e_b[39] = 43;
        e_a[40] = 28; e_b[40] = 44;
        e_a[41] = 29; e_b[41] = 44;
        e_a[42] = 30; e_b[42] = 45;
        e_a[43] = 31; e_b[43] = 45;
        e_a[44] = 32; e_b[44] = 46;
        e_a[45] = 33; e_b[45] = 47;
        e_a[46] = 34; e_b[46] = 46;
        e_a[47] = 35; e_b[47] = 47;
        e_a[48] = 36; e_b[48] = 48;
        e_a[49] = 37; e_b[49] = 49;
        e_a[50] = 38; e_b[50] = 48;
        e_a[51] = 39; e_b[51] = 49;
        e_a[52] = 40; e_b[52] = 50;
        e_a[53] = 42; e_b[53] = 51;
        e_a[54] = 43; e_b[54] = 51;
        e_a[55] = 44; e_b[55] = 52;
        e_a[56] = 45; e_b[56] = 52;
        e_a[57] = 46; e_b[57] = 53;
        e_a[58] = 47; e_b[58] = 54;
        e_a[59] = 48; e_b[59] = 53;
        e_a[60] = 49; e_b[60] = 54;
        e_a[61] = 50; e_b[61] = 55;
        e_a[62] = 51; e_b[62] = 40;
        e_a[63] = 51; e_b[63] = 56;
        e_a[64] = 52; e_b[64] = 56;
        e_a[65] = 53; e_b[65] = 57;
        e_a[66] = 54; e_b[66] = 57;
        e_a[67] = 54; e_b[67] = 58;
        e_a[68] = 56; e_b[68] = 59;
        e_a[69] = 56; e_b[69] = 60;
        e_a[70] = 57; e_b[70] = 59;
        e_a[71] = 57; e_b[71] = 60;
        e_a[72] = 58; e_b[72] = 50;
        e_a[73] = 59; e_b[73] = 55;
        e_a[74] = 59; e_b[74] = 61;
        e_a[75] = 60; e_b[75] = 61;

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
