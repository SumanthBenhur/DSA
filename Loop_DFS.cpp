#include<bits/stdc++.h>
using namespace std;

bool findLoop(vector<int>graph[], int n, int visited[], int recursive_stack[], int curr){
    if(visited[curr]==0){
        
        visited[curr] = recursive_stack[curr] = 1;
        for(auto ele : graph[curr]){
            if(visited[ele]==0 && findLoop(graph, n, visited, recursive_stack, ele))
                return true;
            else if(recursive_stack[ele]==1) return true;
        }
        
    }
        recursive_stack[curr] = 0;
        return false;
}

bool solve(vector<int> graph[], int n){
    
    int visited[n]{0};
    int recursive_stack[n]{0};
    for(int i=0; i<n; i++){
        if(findLoop(graph, n, visited, recursive_stack, i))
            return true;
    }
    return false;
}

int main(){

    int n;
    cin>>n;

    int edges;
    cin>>edges;

    vector<int> graf [n+1];

    for(int i=0; i<edges; i++){
        int a, b;
        cin>>a>>b;
        //graf[b].push_back(a);
        graf[a].push_back(b);
    }

    // code for BFS
    
    if(solve(graf, n)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    return 0;
}