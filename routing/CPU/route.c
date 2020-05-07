#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 9
#define TAM 3

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
/*
//TODO: FAZER VERSAO ITERATIVA
void printPath(int parent[], int j) 
{ 
//	PTAM += 1;
	// Base Case : If j is source 
	if (parent[j] == - 1) 
		return; 

	printPath(parent, parent[j]); 

	printf("%d ", j); 
} 

int printSolution(int dist[], int n, int parent[], int dest) 
{ 
	int src = 1; 
	printf("Vertex\t Distance\tPath"); 
	//for (int i = 1; i < V; i++) 
	//{ 
		printf("\n%d -> %d \t\t %d\t\t%d ", src, dest, dist[dest], src); 
		//printPath(parent, dest); 
	///} 
} 
*/

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

	int edges = 5;
	//E1
	//int e_a[] = {1, 2, 4, 3, 5};
	//int e_b[] = {4, 4, 5, 5, 6};
	//E2
	int e_a[] = {1, 2, 3, 4, 5};
	int e_b[] = {6, 6, 6, 6, 6};
	//E3
        //int e_a[] = {1, 2, 3, 4};
	//int e_b[] = {5, 5, 5, 5};
	//E4
	//int e_a[] = {1, 2, 3, 4, 6, 5, 8, 7};
	//int e_b[] = {4, 4, 4, 5, 5, 7, 5, 9};
	//E5
	//int e_a[] = {1, 2, 4, 5, 3, 6, 8, 7};
	//int e_b	[] = {3, 3, 6, 6, 7, 7, 7, 9};
	//E6
	//int e_a[] = {1,2,4,5,7,8,3,6,6,9,10,11,15,16,14,12};
	//int e_b[] = {3,3,6,6,9,9,10,10,11,11,12,12,14,14,13,13};
	//E7
	//int e_a[] = {1,2,3,5,6,7,11,12,13,4,8,15,10,14,9};
	//int e_b[] = {4,4,4,8,8,8,10,10,10,9,9,14,14,16,14};

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	//PRIMEIRO EXEMPLO
	/*int a[] = {0, 3, 1, 5, 2};
	int b[] = {1, 1, 2, 2, 8};*/
	
	//matriz resultado do placement
	//E1
	//int grid[] = {1, 4, 5, 2, 255, 3, 255, 255, 6};
	//E2
	int grid[] = {1, 2, 3, 255, 6, 4, 255, 5, 255};
	//E3
	//int grid[] = {1, 2, 3,255, 5, 4, 255, 255, 255};
	//E4
	//int grid[] = {1, 4, 5, 2, 3, 6, 9, 8, 7};
	//E5
	//int grid[] = {1, 3, 7, 2, 4, 6, 9, 5, 8};
	//E6
	//int grid[] = {1,2,4,5,10,3,6,7,12,15,11,9,13,14,16,8};
	//E7
	//int grid[] = {2,3,5,6,1,4,8,7,11,13,9,16,12,10,14,15};

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




