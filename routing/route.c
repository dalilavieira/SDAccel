#include <stdio.h>
#include <stdio.h> 
#include <limits.h> 

#define V 9
#define TAM 3
int PTAM = -1;

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

//TODO: FAZER VERSAO ITERATIVA
void printPath(int parent[], int j) 
{ 
	PTAM += 1;
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
	int parent[V];

	int i,j;
	int m[V][V];

	int edges = 5;
	int a[] = {0, 3, 1, 5, 2};
	int b[] = {1, 0, 2, 2, 8};
	int A, B;
	
	for(i=0; i<V; i++){
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
		PTAM = -1;
		A = a[i];
		B = b[i];
		printf("%d ",A);
		dijkstra(m, A, B, parent);
		printPath(parent, B);
		printf("\n");
	}

}




