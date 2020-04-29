#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_node, n_edge, n, size_offset; //parâmetros?
  n_node = 59;
  n_edge = 71;
  n = 8;
  size_offset = 62;
  int state, i, j, pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, a, b, xi, xj;
  int sum=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
 // int offset_x[size_offset], offset_y[size_offset];
  state = 0;
  while(state != 5){
    switch(state){
      case 0://Inicializações
        e_a[0] = 54; e_b[0] = 56;
        e_a[1] = 58; e_b[1] = 54;
        e_a[2] = 51, e_b[2] = 54;
        e_a[3] = 52; e_b[3] = 51;
   
        e_a[4] = 48; e_b[4] = 51;
        e_a[5] = 43; e_b[5] = 48;
        e_a[6] = 42; e_b[6] = 48;
        e_a[7] = 30; e_b[7] = 42;

        e_a[8] = 41; e_b[8] = 30;
        e_a[9] = 13; e_b[9] = 30;
        e_a[10] = 47; e_b[10] = 41;
        e_a[11] = 28; e_b[11] = 41;

        e_a[12] = 37; e_b[12] = 28;
        e_a[13] = 11; e_b[13] = 28;
        e_a[14] = 25; e_b[14] = 37;
        e_a[15] = 25; e_b[15] = 38;

        e_a[16] = 23; e_b[16] = 38;
        e_a[17] = 2; e_b[17] = 23;
        e_a[18] = 2; e_b[18] = 20;
        e_a[19] = 3; e_b[19] = 20;

        e_a[20] = 38; e_b[20] = 29;
        e_a[21] = 12; e_b[21] = 29;
        e_a[22] = 29; e_b[22] = 34;
        e_a[23] = 17; e_b[23] = 34;

        e_a[24] = 0; e_b[24] = 17;
        e_a[25] = 0; e_b[25] = 15;
        e_a[26] = 0; e_b[26] = 16;
        e_a[27] = 27; e_b[27] = 16;

        e_a[28] = 22; e_b[28] =27;
        e_a[29] = 10; e_b[29] = 27;
        e_a[30] = 6; e_b[30] = 22;
        e_a[31] = 16; e_b[31] = 33;

        e_a[32] = 40; e_b[32] = 33;
        e_a[33] = 39; e_b[33] = 40;
        e_a[34] = 33; e_b[34] = 31;
        e_a[35] = 14; e_b[35] = 31;

        e_a[36] = 15; e_b[36] = 32;
        e_a[37] = 32; e_b[37] = 44;
        e_a[38] = 44; e_b[38] = 49;
        e_a[39] = 45; e_b[39] = 49;

        e_a[40] = 57; e_b[40] = 58;
        e_a[41] = 55; e_b[41] = 57;
        e_a[42] = 53; e_b[42] = 55;
        e_a[43] = 50; e_b[43] = 53;

        e_a[44] = 46; e_b[44] = 50;
        e_a[45] = 36; e_b[45] = 46;
        e_a[46] = 19; e_b[46] = 36;
        e_a[47] = 1; e_b[47] = 19;

        e_a[48] = 1; e_b[48] = 18;
        e_a[49] = 8; e_b[49] = 18;
        e_a[50] = 18; e_b[50] = 35;
        e_a[51] = 24; e_b[51] = 35;

        e_a[52] = 7; e_b[52] = 24;
        e_a[53] = 2; e_b[53] = 21;
        e_a[54] = 2; e_b[54] = 22;
        e_a[55] = 2; e_b[55] = 24;

        e_a[56] = 2; e_b[56] = 25;
        e_a[57] = 4; e_b[57] = 23;
        e_a[58] = 5; e_b[58] = 21;
        e_a[59] = 9; e_b[59] = 26;

        e_a[60] = 20; e_b[60] = 37;
        e_a[61] = 21; e_b[61] = 26;
        e_a[62] = 25; e_b[62] = 39;
        e_a[63] = 26; e_b[63] = 40;

        e_a[64] = 31; e_b[64] = 43;
        e_a[65] = 32; e_b[65] = 45;
        e_a[66] = 34; e_b[66] = 44;
        e_a[67] = 35; e_b[67] = 17;

        e_a[68] = 39; e_b[68] = 47;
        e_a[69] = 45; e_b[69] = 43;
        e_a[70] = 49; e_b[70] = 52;


        int offset_x[] = {0, 0, 1, 0,-1,-1, 1, 1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5, 0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3, -3, -1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5, 0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5, 0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};

        int offset_y[] = {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0, 0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0, 0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0, 0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
        

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
