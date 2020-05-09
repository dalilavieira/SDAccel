#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 81
#define TAM 9

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

	int edges = 83;
	//E1
	int e_a[edges];
	int e_b[edges];

	e_a[0] = 67; e_b[0] = 66;
    	  e_a[1] = 66; e_b[1] = 64;
          e_a[2] = 66; e_b[2] = 65;
    	  e_a[3] = 65; e_b[3] = 63;
    	  e_a[4] = 63; e_b[4] = 60;
    	  e_a[5] = 60; e_b[5] = 56;
    	  e_a[6] = 56; e_b[6] = 52;
    	  e_a[7] = 52; e_b[7] = 47;
    	  e_a[8] = 47; e_b[8] = 40;
    	  e_a[9] = 40; e_b[9] = 31;
    	  e_a[10] = 31; e_b[10] = 20;
    	  e_a[11] = 20; e_b[11] = 13;
    	  e_a[12] = 20; e_b[12] = 8;
    	  e_a[13] = 8; e_b[13] = 2;
    	  e_a[14] = 13; e_b[14] = 2;
    	  e_a[15] = 64; e_b[15] = 61;
    	  e_a[16] = 64; e_b[16] = 62;
    	  e_a[17] = 62; e_b[17] = 58;
    	  e_a[18] = 58; e_b[18] = 54;
    	  e_a[19] = 54; e_b[19] = 49;
    	  e_a[20] = 49; e_b[20] = 42;
    	  e_a[21] = 42; e_b[21] = 34;
    	  e_a[22] = 34; e_b[22] = 25;
    	  e_a[23] = 25; e_b[23] = 14;
    	  e_a[24] = 14; e_b[24] = 3;
    	  e_a[25] = 3; e_b[25] = 0;
    	  e_a[26] = 61; e_b[26] = 57;
    	  e_a[27] = 61; e_b[27] = 59;
    	  e_a[28] = 59; e_b[28] = 55;
    	  e_a[29] = 55; e_b[29] = 51;
    	  e_a[30] = 51; e_b[30] = 45;
    	  e_a[31] = 45; e_b[31] = 38;
    	  e_a[32] = 38; e_b[32] = 29;
    	  e_a[33] = 29; e_b[33] = 18;
    	  e_a[34] = 29; e_b[34] = 19;
    	  e_a[35] = 19; e_b[35] = 8;
    	  e_a[36] = 18; e_b[36] = 6;
    	  e_a[37] = 6; e_b[37] = 1;
    	  e_a[38] = 57; e_b[38] = 53;
    	  e_a[39] = 57; e_b[39] = 54;
    	  e_a[40] = 53; e_b[40] = 48;
    	  e_a[41] = 53; e_b[41] = 50;
    	  e_a[42] = 50; e_b[42] = 46;
    	  e_a[43] = 50; e_b[43] = 43;
    	  e_a[44] = 46; e_b[44] = 39;
    	  e_a[45] = 39; e_b[45] = 30;
    	  e_a[46] = 30; e_b[46] = 19;
    	  e_a[47] = 30; e_b[47] = 23;
    	  e_a[48] = 23; e_b[48] = 11;
    	  e_a[49] = 11; e_b[49] = 2;
    	  e_a[50] = 43; e_b[50] = 35;
    	  e_a[51] = 43; e_b[51] = 36;
    	  e_a[52] = 36; e_b[52] = 27;
    	  e_a[53] = 27; e_b[53] = 15;
    	  e_a[54] = 15; e_b[54] = 4;
    	  e_a[55] = 4; e_b[55] = 1;
    	  e_a[56] = 35; e_b[56] = 32;
    	  e_a[57] = 35; e_b[57] = 26;
    	  e_a[58] = 32; e_b[58] = 21;
    	  e_a[59] = 21; e_b[59] = 9;
    	  e_a[60] = 9; e_b[60] = 2;
    	  e_a[61] = 26; e_b[61] = 17;
    	  e_a[62] = 26; e_b[62] = 15;
    	  e_a[63] = 17; e_b[63] = 5;
    	  e_a[64] = 5; e_b[64] = 1;
    	  e_a[65] = 48; e_b[65] = 44;
    	  e_a[66] = 48; e_b[66] = 42;
    	  e_a[67] = 44; e_b[67] = 37;
    	  e_a[68] = 44; e_b[68] = 41;
    	  e_a[69] = 41; e_b[69] = 33;
    	  e_a[70] = 33; e_b[70] = 24;
    	  e_a[71] = 24; e_b[71] = 12;
    	  e_a[72] = 12; e_b[72] = 2;
    	  e_a[73] = 37; e_b[73] = 28;
    	  e_a[74] = 37; e_b[74] = 27;
    	  e_a[75] = 28; e_b[75] = 16;
    	  e_a[76] = 28; e_b[76] = 22;
    	  e_a[77] = 22; e_b[77] = 10;
    	  e_a[78] = 10; e_b[78] = 2;
    	  e_a[79] = 16; e_b[79] = 7;
    	  e_a[80] = 16; e_b[80] = 4;
    	  e_a[81] = 7; e_b[81] = 2;
    	  e_a[82] = 7; e_b[82] = 1;

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = { 255,    5,    9,   21,   19,   45,   18,   29,   67,  255,   17,    4,   32,
6,   51,   38,   65,   66,  255,   26,   15,   35,    1,   55,   59,   63,   64,  255,  255,   27,   43,   46,   50,
56,   60,   61,  255,  255,   36,   39,   48,   53,   52,   57,   62,  255,  255,   23,   30,   44,   40,
47,   54,   58,  255,  255,   11,   37,   10,   31,   42,   49,   34,  255,    7,   33,   41,   13,   20,    8,
2,   25,  255,   12,   24,   28,   16,   22,    0,    3,   14 };

	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				//printf("%d\n", i);
			}
		}
	}
	//printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				//printf("%d\n", i);
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
	printf("\n");
	dijkstra(m, 0, 5, parent);
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
