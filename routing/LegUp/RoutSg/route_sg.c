#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 36
#define TAM 6

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

	int edges = 42;
	//E1
	int e_a[edges];
	int e_b[edges];

	  e_a[0] = 35; e_b[0] = 34;
    	  e_a[1] = 34; e_b[1] = 33;
	  e_a[2] = 33; e_b[2] = 31;
    	  e_a[3] = 33; e_b[3] = 32;
    	  e_a[4] = 31; e_b[4] = 28;
    	  e_a[5] = 31; e_b[5] = 30;
    	  e_a[6] = 28; e_b[6] = 25;
    	  e_a[7] = 25; e_b[7] = 22;
    	  e_a[8] = 25; e_b[8] = 20;
    	  e_a[9] = 22; e_b[9] = 19;
    	  e_a[10] = 22; e_b[10] = 17;
    	  e_a[11] = 17; e_b[11] = 11;
    	  e_a[12] = 11; e_b[12] = 4;
    	  e_a[13] = 11; e_b[13] = 7;
    	  e_a[14] = 7; e_b[14] = 1;
    	  e_a[15] = 4; e_b[15] = 0;
    	  e_a[16] = 19; e_b[16] = 14;
    	  e_a[17] = 14; e_b[17] = 8;
    	  e_a[18] = 8; e_b[18] = 1;
    	  e_a[19] = 20; e_b[19] = 15;
    	  e_a[20] = 15; e_b[20] = 13;
    	  e_a[21] = 15; e_b[21] = 9;
    	  e_a[22] = 9; e_b[22] = 2;
    	  e_a[23] = 2; e_b[23] = 0;
    	  e_a[24] = 13; e_b[24] = 6;
    	  e_a[25] = 6; e_b[25] = 0;
    	  e_a[26] = 30; e_b[26] = 27;
    	  e_a[27] = 27; e_b[27] = 24;
    	  e_a[28] = 24; e_b[28] = 19;
    	  e_a[29] = 32; e_b[29] = 29;
    	  e_a[30] = 29; e_b[30] = 26;
    	  e_a[31] = 26; e_b[31] = 21;
    	  e_a[32] = 26; e_b[32] = 23;
    	  e_a[33] = 21; e_b[33] = 16;
    	  e_a[34] = 16; e_b[34] = 12;
    	  e_a[35] = 16; e_b[35] = 10;
    	  e_a[36] = 10; e_b[36] = 3;
    	  e_a[37] = 3; e_b[37] = 0;
    	  e_a[38] = 12; e_b[38] = 5;
    	  e_a[39] = 5; e_b[39] = 0;
    	  e_a[40] = 23; e_b[40] = 18;
    	  e_a[41] = 18; e_b[41] = 13;

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {  12,    5,    1,    7,   23,   24,   16,   21,    4,   11,   26,   27,   10,   18,    0,
		17,   29,   30,    3,   14,   19,   22,   32,   31,    6,    8,
		9,   25,   33,   28,   13,    2,   15,   20,   35,   34 };


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
