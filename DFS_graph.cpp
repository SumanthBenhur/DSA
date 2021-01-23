#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], int v, int src){
    bool visited[v+1];
    for(int i=0; i<=v; i++) visited[i]=false;
    DFSrecur(graph, src, visited);
}

void DFSrecur(vector<int> graph[], int src, bool visited[]){
    visited[src] = true;
    cout<<"src"<<" ";
    for(auto ele : graph[src]){
        if(visited[ele]==false)
            DFSrecur(graph, ele, visited);
    }
}