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

	int edges = 32;
	//E1
	int e_a[edges];
	int e_b[edges];
 
	e_a[0] = 26; e_b[0] =  25;
	e_a[1] = 25; e_b[1] =  24;
	e_a[2] = 25; e_b[2] =  23;
	e_a[3] = 23; e_b[3] =  21;
	e_a[4] = 23; e_b[4] =  20;
	e_a[5] = 20; e_b[5] =  18;
	e_a[6] = 20; e_b[6] =  15;
	e_a[7] = 15; e_b[7] =  13;
	e_a[8] = 15; e_b[8] =  9;
	e_a[9] = 9; e_b[9] =  3;
	e_a[10] = 9; e_b[10] =  5;
	e_a[11] = 3; e_b[11] =  0;
	e_a[12] = 5; e_b[12] =  1;
	e_a[13] = 13; e_b[13] =  7;
	e_a[14] = 7; e_b[14] =  2;
	e_a[15] = 18; e_b[15] =  11;
	e_a[16] = 11; e_b[16] =  5;
	e_a[17] = 21; e_b[17] =  16;
	e_a[18] = 21; e_b[18] =  17;
	e_a[19] = 17; e_b[19] =  10;
	e_a[20] = 17; e_b[20] =  13;
	e_a[21] = 10; e_b[21] =  4;
	e_a[22] = 4; e_b[22] =  0;
	e_a[23] = 16; e_b[23] =  10;
	e_a[24] = 24; e_b[24] =  22;
	e_a[25] = 22; e_b[25] =  19;
	e_a[26] = 19; e_b[26] =  14;
	e_a[27] = 19; e_b[27] =  12;
	e_a[28] = 12; e_b[28] =  6;
	e_a[29] = 6; e_b[29] =  2;
	e_a[30] = 14; e_b[30] =  8;
	e_a[31] = 8; e_b[31] = 2;


	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {   21,   23,    7,   20,   15,   13,   26,   25,   24,   18,    9,    5,   16,   17,    
		2,   11,    1,    3,  255,   10,    4,   22,    8,    0,  255,  255,   
		12,   19,   14,  255,  255,  255,    6,  255,  255,  255}; 


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
				printf("DEU RUIM\n");
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

	for(i=0; i<V; i++){
		printf("entradas do PE%d: ",i);
		for(j=0; j<indice_e[i]; j++){
			printf("%d ", entradas[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
	printf("\n");

	for(i=0; i<V; i++){
		printf("saidas do PE%d: ",i);
		for(j=0; j<indice_s[i]; j++){
			printf("%d ", saidas[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}




