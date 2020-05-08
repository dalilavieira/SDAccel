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

	int edges = 37;
	//E1
	int e_a[edges];
	int e_b[edges];
	e_a[0] = 30; e_b[0] = 31;
        e_a[1] = 28; e_b[1] = 30;
 
	e_a[0] = 26; e_b[0] =  25;
	e_a[0] = 25; e_b[0] =  24;
	e_a[0] = 25; e_b[0] =  23;
	e_a[0] = 23; e_b[0] =  21;
	e_a[0] = 23; e_b[0] =  20;
	e_a[0] = 20; e_b[0] =  18;
	e_a[0] = 20; e_b[0] =  15;
	e_a[0] = 15; e_b[0] =  13;
	e_a[0] = 15; e_b[0] =  9;
	e_a[0] = 9; e_b[0] =  3;
	e_a[0] = 9; e_b[0] =  5;
	e_a[0] = 3; e_b[0] =  0;
	e_a[0] = 5; e_b[0] =  1;
	e_a[0] = 13; e_b[0] =  7;
	e_a[0] = 7; e_b[0] =  2;
	e_a[0] = 18; e_b[0] =  11;
	e_a[0] = 11; e_b[0] =  5;
	e_a[0] = 21; e_b[0] =  16;
	e_a[0] = 21; e_b[0] =  17;
	e_a[0] = 17; e_b[0] =  10;
	e_a[0] = 17; e_b[0] =  13;
	e_a[0] = 10; e_b[0] =  4;
	e_a[0] = 4; e_b[0] =  0;
	e_a[0] = 16; e_b[0] =  10;
	e_a[0] = 24; e_b[0] =  22;
	e_a[0] = 22; e_b[0] =  19;
	e_a[0] = 19; e_b[0] =  14;
	e_a[0] = 19; e_b[0] =  12;
	e_a[0] = 12; e_b[0] =  6;
	e_a[0] = 6; e_b[0] =  2;
	e_a[0] = 14; e_b[0] =  8;
	e_a[0] = 8; e_b[0] = 2;


	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {255,   7,   4,  15,  23,  21,  255,   5,  12,  17,  26,  31,
  		255,   8,   9,  16,  29,  30,   1,   0,  10,  22,  27,  28,
  		255,   2,  18,  13,  24,  25,   3,   6,  11,  14,  19,  20};


	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				printf("%d\n", i);
			}
		}
	}
	printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				printf("%d\n", i);
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

	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/*dijkstra(m, 0, 5, parent); 
	printPath(parent, 5); 
	printf("\n");
        printf("%d\n",PTAM);*/

	for(i=0; i<edges; i++){
		A = a[i];
		B = b[i];
		printf("%d ",A);
		dijkstra(m, A, B, parent);
		//printPath(parent, B);
		printf("\n");
		
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

			printf("origem=%d dest=%d\n",origem,destino);

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
		printf("\n");
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




