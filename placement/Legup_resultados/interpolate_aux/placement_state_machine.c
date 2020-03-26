#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_node, n_edge, n, size_offset; //parâmetros?
  n_node = 108;
  n_edge = 104;
  n = 11;
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
        e_a[0] = 0; e_b[0] = 48;
        e_a[1] = 1; e_b[1] = 49;
        e_a[2] = 2; e_b[2] = 50;
        e_a[3] = 3; e_b[3] = 51;
        e_a[4] = 4; e_b[4] = 52;
        e_a[5] = 5; e_b[5] = 53;
        e_a[6] = 6; e_b[6] = 54;
        e_a[7] = 7; e_b[7] = 55;
        e_a[8] = 8; e_b[8] = 56;
        e_a[9] = 9; e_b[9] = 57;
        e_a[10] = 10; e_b[10] = 58;
        e_a[11] = 11; e_b[11] = 59;
        e_a[12] = 12; e_b[12] = 60;
        e_a[13] = 13; e_b[13] = 61;
        e_a[14] = 14; e_b[14] = 58;
        e_a[15] = 15; e_b[15] = 62;
        e_a[16] = 16; e_b[16] = 61;
        e_a[17] = 17; e_b[17] = 63;
        e_a[18] = 18; e_b[18] = 64;
        e_a[19] = 19; e_b[19] = 65;
        e_a[20] = 20; e_b[20] = 65;
        e_a[21] = 21; e_b[21] = 66;
        e_a[22] = 22; e_b[22] = 67;
        e_a[23] = 23; e_b[23] = 48;
        e_a[24] = 24; e_b[24] = 50;
        e_a[25] = 25; e_b[25] = 55;
        e_a[26] = 26; e_b[26] = 68;
        e_a[27] = 27; e_b[27] = 69;
        e_a[28] = 28; e_b[28] = 70;
        e_a[29] = 29; e_b[29] = 71;
        e_a[30] = 30; e_b[30] = 72;
        e_a[31] = 31; e_b[31] = 63;
        e_a[32] = 32; e_b[32] = 73;
        e_a[33] = 33; e_b[33] = 59;
        e_a[34] = 34; e_b[34] = 73;
        e_a[35] = 35; e_b[35] = 74;
        e_a[36] = 36; e_b[36] = 51;
        e_a[37] = 37; e_b[37] = 71;
        e_a[38] = 38; e_b[38] = 57;
        e_a[39] = 39; e_b[39] = 75;
        e_a[40] = 40; e_b[40] = 52;
        e_a[41] = 41; e_b[41] = 76;
        e_a[42] = 42; e_b[42] = 77;
        e_a[43] = 43; e_b[43] = 78;
        e_a[44] = 44; e_b[44] = 68;
        e_a[45] = 45; e_b[45] = 79;
        e_a[46] = 46; e_b[46] = 67;
        e_a[47] = 47; e_b[47] = 77;
        e_a[48] = 48; e_b[48] = 53;
        e_a[49] = 49; e_b[49] = 80;
        e_a[50] = 50; e_b[50] = 49;
        e_a[51] = 51; e_b[51] = 69;
        e_a[52] = 52; e_b[52] = 79;
        e_a[53] = 53; e_b[53] = 81;
        e_a[54] = 54; e_b[54] = 82;
        e_a[55] = 55; e_b[55] = 78;
        e_a[56] = 56; e_b[56] = 83;
        e_a[57] = 57; e_b[57] = 66;
        e_a[58] = 58; e_b[58] = 76;
        e_a[59] = 59; e_b[59] = 62;
        e_a[60] = 60; e_b[60] = 84;
        e_a[61] = 61; e_b[61] = 75;
        e_a[62] = 62; e_b[62] = 85;
        e_a[63] = 63; e_b[63] = 54;
        e_a[64] = 64; e_b[64] = 86;
        e_a[65] = 65; e_b[65] = 60;
        e_a[66] = 66; e_b[66] = 87;
        e_a[67] = 67; e_b[67] = 74;
        e_a[68] = 68; e_b[68] = 56;
        e_a[69] = 69; e_b[69] = 88;
        e_a[70] = 70; e_b[70] = 89;
        e_a[71] = 71; e_b[71] = 64;
        e_a[72] = 72; e_b[72] = 90;
        e_a[73] = 73; e_b[73] = 70;
        e_a[74] = 74; e_b[74] = 91;
        e_a[75] = 75; e_b[75] = 92;
        e_a[76] = 76; e_b[76] = 93;
        e_a[77] = 77; e_b[77] = 72;
        e_a[78] = 78; e_b[78] = 94;
        e_a[79] = 79; e_b[79] = 95;
        e_a[80] = 80; e_b[80] = 96;
        e_a[81] = 83; e_b[81] = 97;
        e_a[82] = 85; e_b[82] = 98;
        e_a[83] = 86; e_b[83] = 96;
        e_a[84] = 87; e_b[84] = 99;
        e_a[85] = 89; e_b[85] = 100;
        e_a[86] = 90; e_b[86] = 101;
        e_a[87] = 91; e_b[87] = 102;
        e_a[88] = 92; e_b[88] = 99;
        e_a[89] = 93; e_b[89] = 101;
        e_a[90] = 94; e_b[90] = 98;
        e_a[91] = 95; e_b[91] = 103;
        e_a[92] = 96; e_b[92] = 104;
        e_a[93] = 97; e_b[93] = 84;
        e_a[94] = 98; e_b[94] = 105;
        e_a[95] = 99; e_b[95] = 106;
        e_a[96] = 100; e_b[96] = 81;
        e_a[97] = 101; e_b[97] = 107;
        e_a[98] = 102; e_b[98] = 88;
        e_a[99] = 103; e_b[99] = 82;
        e_a[100] = 104; e_b[100] = 103;
        e_a[101] = 105; e_b[101] = 97;
        e_a[102] = 106; e_b[102] = 102;
        e_a[103] = 107; e_b[103] = 100;

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
