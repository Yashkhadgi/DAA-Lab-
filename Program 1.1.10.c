#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

//write your code here..
	void algorithm(int V, int dist[][MAX_N]){
	int i, j,k;
	for(k=0; k<V; k++){
		for(i=0; i<V; i++){
			for(j=0; j<V; j++){
				if(dist[i][k] !=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j]<dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			if(dist[i][j]==INF){
				printf("%5s","INF");
			}
			else{
				printf("%5d",dist[i][j]);
			}
		}
		printf("\n");
	}
}

#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

//write your code here..
	void algorithm(int V, int dist[][MAX_N]){
	int i, j,k;
	for(k=0; k<V; k++){
		for(i=0; i<V; i++){
			for(j=0; j<V; j++){
				if(dist[i][k] !=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j]<dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			if(dist[i][j]==INF){
				printf("%5s","INF");
			}
			else{
				printf("%5d",dist[i][j]);
			}
		}
		printf("\n");
	}
}
