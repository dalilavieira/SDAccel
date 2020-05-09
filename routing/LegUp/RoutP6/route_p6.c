#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 121
#define TAM 11

int minDistance(int dist[], int sptSet[]) 
{ 
	
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == 0 && 
				dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void dijkstra(int graph[V][V], int src, int dest, int * parent) 
{ 
	int dist[V]; 
	int sptSet[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[src] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = 0; 
	} 

	dist[src] = 0; 
 
	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minDistance(dist, sptSet); 

		sptSet[u] = 1; 
 
		for (int v = 0; v < V; v++) 
			if (!sptSet[v] && graph[u][v] && 
				dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 

	// print the constructed 
	// distance array 
	//printSolution(dist, V, parent, dest); 
} 

int main(){
	int FLAG = 0;
	int parent[V];

	int i,j;
	int m[V][V];

	int edges = 125;
	//E1
	int e_a[edges];
	int e_b[edges];

	  e_a[0] = 100; e_b[0] = 99;
    	  e_a[1] = 99; e_b[1] = 97;
    	  e_a[2] = 99; e_b[2] = 98;
    	  e_a[3] = 98; e_b[3] = 96;
    	  e_a[4] = 96; e_b[4] = 92;
    	  e_a[5] = 92; e_b[5] = 87;
    	  e_a[6] = 87; e_b[6] = 82;
    	  e_a[7] = 82; e_b[7] = 75;
    	  e_a[8] = 75; e_b[8] = 66;
    	  e_a[9] = 75; e_b[9] = 70;
    	  e_a[10] = 70; e_b[10] = 60;
    	  e_a[11] = 60; e_b[11] = 49;
    	  e_a[12] = 49; e_b[12] = 36;
    	  e_a[13] = 36; e_b[13] = 23;
    	  e_a[14] = 23; e_b[14] = 9;
    	  e_a[15] = 9; e_b[15] = 2;
    	  e_a[16] = 66; e_b[16] = 58;
    	  e_a[17] = 66; e_b[17] = 56;
    	  e_a[18] = 56; e_b[18] = 44;
    	  e_a[19] = 44; e_b[19] = 31;
    	  e_a[20] = 31; e_b[20] = 18;
    	  e_a[21] = 18; e_b[21] = 4;
    	  e_a[22] = 4; e_b[22] = 1;
    	  e_a[23] = 58; e_b[23] = 45;
    	  e_a[24] = 58; e_b[24] = 48;
    	  e_a[25] = 48; e_b[25] = 35;
    	  e_a[26] = 35; e_b[26] = 22;
    	  e_a[27] = 22; e_b[27] = 7;
    	  e_a[28] = 7; e_b[28] = 2;
    	  e_a[29] = 45; e_b[29] = 33;
    	  e_a[30] = 45; e_b[30] = 31;
    	  e_a[31] = 33; e_b[31] = 20;
    	  e_a[32] = 33; e_b[32] = 27;
    	  e_a[33] = 27; e_b[33] = 14;
    	  e_a[34] = 14; e_b[34] = 2;
    	  e_a[35] = 20; e_b[35] = 5;
    	  e_a[36] = 5; e_b[36] = 1;
    	  e_a[37] = 97; e_b[37] = 95;
    	  e_a[38] = 97; e_b[38] = 94;
    	  e_a[39] = 95; e_b[39] = 91;
    	  e_a[40] = 91; e_b[40] = 86;
    	  e_a[41] = 86; e_b[41] = 81;
    	  e_a[42] = 81; e_b[42] = 74;
    	  e_a[43] = 74; e_b[43] = 65;
    	  e_a[44] = 65; e_b[44] = 55;
    	  e_a[45] = 55; e_b[45] = 43;
    	  e_a[46] = 43; e_b[46] = 30;
    	  e_a[47] = 30; e_b[47] = 17;
    	  e_a[48] = 17; e_b[48] = 3;
    	  e_a[49] = 3; e_b[49] = 0;
    	  e_a[50] = 94; e_b[50] = 93;
    	  e_a[51] = 94; e_b[51] = 90;
    	  e_a[52] = 93; e_b[52] = 88;
    	  e_a[53] = 88; e_b[53] = 83;
    	  e_a[54] = 83; e_b[54] = 76;
    	  e_a[55] = 83; e_b[55] = 79;
    	  e_a[56] = 79; e_b[56] = 71;
    	  e_a[57] = 71; e_b[57] = 62;
    	  e_a[58] = 62; e_b[58] = 51;
    	  e_a[59] = 51; e_b[59] = 38;
    	  e_a[60] = 38; e_b[60] = 27;
    	  e_a[61] = 38; e_b[61] = 25;
    	  e_a[62] = 25; e_b[62] = 12;
    	  e_a[63] = 12; e_b[63] = 2;
    	  e_a[64] = 76; e_b[64] = 69;
    	  e_a[65] = 76; e_b[65] = 67;
    	  e_a[66] = 67; e_b[66] = 56;
    	  e_a[67] = 69; e_b[67] = 57;
    	  e_a[68] = 69; e_b[68] = 61;
    	  e_a[69] = 61; e_b[69] = 50;
    	  e_a[70] = 50; e_b[70] = 37;
    	  e_a[71] = 37; e_b[71] = 27;
    	  e_a[72] = 37; e_b[72] = 24;
    	  e_a[73] = 24; e_b[73] = 10;
    	  e_a[74] = 10; e_b[74] = 2;
    	  e_a[75] = 57; e_b[75] = 44;
    	  e_a[76] = 57; e_b[76] = 46;
    	  e_a[77] = 46; e_b[77] = 34;
    	  e_a[78] = 46; e_b[78] = 31;
    	  e_a[79] = 34; e_b[79] = 21;
    	  e_a[80] = 21; e_b[80] = 8;
    	  e_a[81] = 21; e_b[81] = 6;
    	  e_a[82] = 8; e_b[82] = 2;
    	  e_a[83] = 6; e_b[83] = 1;
    	  e_a[84] = 90; e_b[84] = 89;
    	  e_a[85] = 90; e_b[85] = 86;
    	  e_a[86] = 89; e_b[86] = 85;
    	  e_a[87] = 89; e_b[87] = 84;
    	  e_a[88] = 85; e_b[88] = 80;
    	  e_a[89] = 80; e_b[89] = 73;
    	  e_a[90] = 73; e_b[90] = 64;
    	  e_a[91] = 64; e_b[91] = 54;
    	  e_a[92] = 54; e_b[92] = 40;
    	  e_a[93] = 54; e_b[93] = 41;
    	  e_a[94] = 40; e_b[94] = 27;
    	  e_a[95] = 41; e_b[95] = 28;
    	  e_a[96] = 28; e_b[96] = 14;
    	  e_a[97] = 28; e_b[97] = 16;
    	  e_a[98] = 16; e_b[98] = 2;
    	  e_a[99] = 84; e_b[99] = 77;
    	  e_a[100] = 84; e_b[100] = 78;
    	  e_a[101] = 77; e_b[101] = 67;
    	  e_a[102] = 78; e_b[102] = 68;
    	  e_a[103] = 78; e_b[103] = 72;
    	  e_a[104] = 72; e_b[104] = 63;
    	  e_a[105] = 63; e_b[105] = 53;
    	  e_a[106] = 53; e_b[106] = 42;
    	  e_a[107] = 53; e_b[107] = 40;
    	  e_a[108] = 42; e_b[108] = 29;
    	  e_a[109] = 29; e_b[109] = 15;
    	  e_a[110] = 15; e_b[110] = 2;
    	  e_a[111] = 68; e_b[111] = 59;
    	  e_a[112] = 68; e_b[112] = 56;
    	  e_a[113] = 59; e_b[113] = 52;
    	  e_a[114] = 59; e_b[114] = 47;
    	  e_a[115] = 47; e_b[115] = 32;
    	  e_a[116] = 32; e_b[116] = 19;
    	  e_a[117] = 19; e_b[117] = 4;
    	  e_a[118] = 19; e_b[118] = 11;
    	  e_a[119] = 11; e_b[119] = 2;
    	  e_a[120] = 52; e_b[120] = 40;
    	  e_a[121] = 52; e_b[121] = 39;
    	  e_a[122] = 39; e_b[122] = 26;
    	  e_a[123] = 26; e_b[123] = 13;
    	  e_a[124] = 13; e_b[124] = 2;

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] =   {69,   90,   94,   97,   99,   87,   92,   82,   70,   23,   36,   76,   83,   93,   95,  100,   98,   96,
75,   66,   60,   49,   79,   88,   86,   91,  255,  255,   48,   58,    2,    9,  255,   71,   62,   81,   67,  255,   22,   35,   45,
56,  255,  255,   51,   65,   74,  255,  255,    7,   33,   31,   44,  255,  255,   38,   55,   25,   12,   14,   27,   20,   18,  255,
255,  255,   30,   43,  255,  255,  255,    5,    1,    4,  255,  255,  255,   17,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,
3,    0,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,  255,
255,  255,  255,  255,  255,  255,  255,  255};


	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
			//	printf("%d\n", i);
			}
		}
	}
	printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
			//	printf("%d\n", i);
			}
		}
	}	


	for(i=0; i<V; i++){
		indice_e[i] = 0;
		indice_s[i] = 0;
		for(j=0; j<V; j++){
			m[i][j] = 0;
			//printf("%d",m);
		}
	}

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(i<TAM-1 & j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = 1; 
				m[i*TAM+(j+1)][i*TAM+j] = 1; 
				m[i*TAM+j][(i+1)*TAM+j] = 1; 
				m[(i+1)*TAM+j][i*TAM+j] = 1; 
			}else if(i<TAM-1){
				m[i*TAM+j][(i+1)*TAM+j] = 1; 
				m[(i+1)*TAM+j][i*TAM+j] = 1; 
			}else if(j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = 1; 
				m[i*TAM+(j+1)][i*TAM+j] = 1; 
			}
		}
	}

	/*for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	/*dijkstra(m, 0, 5, parent); 
	printPath(parent, 5); 
	printf("\n");
        printf("%d\n",PTAM);*/

	for(i=0; i<edges; i++){
		A = a[i];
		B = b[i];
		//printf("%d ",A);
		dijkstra(m, A, B, parent);
		//printPath(parent, B);
		//printf("\n");
		
		j = 0;
		while(1){
			if(j ==0 ){
				destino = B;
			}else{
				destino = origem;
			}

			origem = parent[destino];
			if(origem == -1)
				break;

			//printf("origem=%d dest=%d\n",origem,destino);

			if(indice_s[origem]<4 & indice_e[destino]<4){
				entradas[destino][indice_e[destino]] = origem;
				saidas[origem][indice_s[origem]] = destino;
				indice_e[destino] += 1;
				indice_s[origem] +=1;
			}else{
				//printf("DEU RUIM\n");
				FLAG = 1;
				//exit(1);
				break;
			}	
			j++;		
		}
		if(FLAG == 1)
			break;
		//printf("\n");
	}

//	for(i=0; i<V; i++){
//		printf("entradas do PE%d: ",i);
//		for(j=0; j<indice_e[i]; j++){
//			printf("%d ", entradas[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//	for(i=0; i<V; i++){
//		printf("saidas do PE%d: ",i);
//		for(j=0; j<indice_s[i]; j++){
//			printf("%d ", saidas[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");

}
