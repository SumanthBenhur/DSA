#include<bits/stdc++.h>
using namespace std;

#define V 9 

int findVertex(int dist[], int processed[]){
    
    int min_dist = INT_MAX, index;
    for(int i=0; i<V; i++){
        if(dist[i]<min_dist && processed[i]==0){
            min_dist = dist[i];
            index = i;
        }
        
    }
    
    return index;
}

void printSolution(int dist[]){
    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
}


void dijkstra(int graph[V][V], int src) {
    
    int dist[V]{0}, processed[V]{0};
    for(int i=1; i<V; i++) dist[i]=INT_MAX;
    
    for(int i=0; i<V-1; i++){
        
        int u = findVertex(dist, processed);
        
        processed[u]=1;
        for(int v = 0; v<V; v++){
            if(graph[u][v] && !processed[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v] ){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printSolution(dist); 
}

int main() 
{ 
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(graph, 0); 

	return 0; 
} 