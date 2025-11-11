#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999

int find(int parent[], int i) {
	if(parent[i] != i)
		parent[i] = find(parent, parent[i]);
	return parent[i];
// Write your code here...

}


void union1(int parent[], int rank[], int i, int j) {
	int rootI = find(parent,i);
	int rootJ = find(parent,j);
	if(rank[rootI] < rank[rootJ]){
		parent[rootI] = rootJ;
	} else if (rank[rootJ] > rank[rootJ]){
		parent[rootJ] = rootI;
	} else{
		parent[rootJ] = rootI;
		rank[rootI]++;
	}
	// Write your code here...
}


void kruskalMST(int **cost, int V) {

	// Write your code here...
	int parent[V],rank[V];
	int edges[V*V][3];
	int edgeCount = 0;
	
	for(int i = 0; i<V;i++){
		parent[i] = i;
		rank[i] = 0;
	}
	for(int i = 0; i < V; i++){
		parent[i] = i;
		rank[i] = 0;
	}
	for(int i = 0; i < V; i++){
		for(int j = i + 1; j < V; j++){
			if(cost[i][j] != INF){
edges[edgeCount][0] = i;
edges[edgeCount][1] = j;
edges[edgeCount][2] = cost[i][j];
				edgeCount++;
			}
		}
	}
	for(int i = 0; i < edgeCount - 1; i++){
		for(int j = 0; j < edgeCount - i - 1;j++){
			if(edges[j][2] > edges[j + 1][2]){
				int temp0 = edges[j][0],temp1 = edges[j][1],temp2 = edges[j][2];
edges[j][0] = edges[j + 1][0];
edges[j][1] = edges[j + 1][1];
				edges[j][2] = edges[j + 1][2];
edges[j + 1][0] = temp0;
edges[j + 1][1] = temp1;
				edges[j + 1][2] = temp2;
			}
		}
	}
int minCost = 0;
	int edgeUsed = 0;
	for(int i = 0; i < edgeCount && edgeUsed < V - 1; i++){
int u = edges[i][0];
int v = edges[i][1];
		int w = edges[i][2];
		if(find(parent, u) !=find(parent,v)){
			union1(parent,rank,u,v);
			printf("Edge %d:(%d, %d) cost:%d\n",edgeUsed,u,v,w);
			minCost += w;
			edgeUsed++;
			
		}
	}
	printf("Minimum cost= %d\n",minCost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
