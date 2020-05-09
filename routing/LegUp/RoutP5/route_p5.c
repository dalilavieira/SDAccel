#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 49
#define TAM 7

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

	int edges = 60;
	//E1
	int e_a[edges];
	int e_b[edges];

	e_a[0] = 45; e_b[0] = 43;
	e_a[1] = 43; e_b[1] =  46;
	e_a[2] = 43; e_b[2] =  40;
	e_a[3] = 40; e_b[3] =  37;
	e_a[4] = 40; e_b[4] =  36;
	e_a[5] = 37; e_b[5] =  42;
	e_a[6] = 37; e_b[6] =  33;
	e_a[7] = 42; e_b[7] =  39;
	e_a[8] = 39; e_b[8] =  35;
	e_a[9] = 35; e_b[9] =  31;
	e_a[10] = 35; e_b[10] =  28;
	e_a[11] = 28; e_b[11] =  19;
	e_a[12] = 19; e_b[12] =  8;
	e_a[13] = 19; e_b[13] =  13;
	e_a[14] = 8; e_b[14] =  2;
	e_a[15] = 13; e_b[15] =  2;
	e_a[16] = 31; e_b[16] =  23;
	e_a[17] = 23; e_b[17] =  13;
	e_a[18] = 33; e_b[18] =  26;
	e_a[19] = 33; e_b[19] =  25;
	e_a[20] = 26; e_b[20] =  15;
	e_a[21] = 15; e_b[21] =  4;
	e_a[22] = 15; e_b[22] =  29;
	e_a[23] = 4; e_b[23] =  21;
	e_a[24] = 4; e_b[24] =  0;
	e_a[25] = 21; e_b[25] =  10;
	e_a[26] = 10; e_b[26] =  2;
	e_a[27] = 29; e_b[27] =  23;
	e_a[28] = 29; e_b[28] =  20;
	e_a[29] = 20; e_b[29] =  9;
	e_a[30] = 9; e_b[30] =  2;
	e_a[31] = 25; e_b[31] =  14;
	e_a[32] = 14; e_b[32] =  3;
	e_a[33] = 3; e_b[33] =  0;
	e_a[34] = 36; e_b[34] = 32;
	e_a[35] = 32; e_b[35] = 25;
	e_a[36] = 32; e_b[36] =  24;
	e_a[37] = 24; e_b[37] =  16;
	e_a[38] = 24; e_b[38] =  14;
	e_a[39] = 24; e_b[39] =  34;
	e_a[40] = 16; e_b[40] =  30;
	e_a[41] = 16; e_b[41] =  5;
	e_a[42] = 5; e_b[42] =  0;
	e_a[43] = 5; e_b[43] =  17;
	e_a[44] = 17; e_b[44] =  6;
	e_a[45] = 17; e_b[45] =  12;
	e_a[46] = 6; e_b[46] =  1;
	e_a[47] = 12; e_b[47] =  2;
	e_a[48] = 30; e_b[48] =  22;
	e_a[49] = 22; e_b[49] =  13;
	e_a[50] = 22; e_b[50] =  11;
	e_a[51] = 11; e_b[51] =  2;
	e_a[52] = 34; e_b[52] =  27;
	e_a[53] = 27; e_b[53] =  18;
	e_a[54] = 18; e_b[54] =  7;
	e_a[55] = 7; e_b[55] =  1;
	e_a[56] = 46; e_b[56] =  44;
	e_a[57] = 44; e_b[57] =  41;
	e_a[58] = 41; e_b[58] =  38;
	e_a[59] = 38; e_b[59] =  34;


	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = { 255,    1,    6,   23,   31,   28,  255,   11,   12,   17,    7,   35,   19,    8,   22,   30,    5,
	3,   39,   13,    2,   27,   16,   18,   14,   42,   33,   25,   34,   24,   32,   10,   37,   36,   26,   38,
	9,   20,   21,   40,   29,   15,   41,   44,    0,   46,   43,   45,    4};

	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				//printf("%d\n", i);
			}
		}
	}
	printf("\n");
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
