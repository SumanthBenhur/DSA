#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> arr[], int a, int b){
    arr[a].push_back(b);
    arr[b].push_back(a);
}

int main(){
    int v = 4;
    vector<int> graph[v];

    addEdge(graph, 0,1);
    addEdge(graph, 3,2);
    addEdge(graph, 1,2);
    addEdge(graph, 2,0);
    return 0;

}