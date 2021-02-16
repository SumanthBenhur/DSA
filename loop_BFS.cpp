#include<bits/stdc++.h>
using namespace std;


bool solve(int V, vector<int> adj[], int visited[], int curr){
        int parent[V+1];
        queue <int>q;
        q.push(curr);
        visited[curr]=1;
        while(q.empty()==false){
            int temp = q.front();
            
            q.pop();
            for(auto ele: adj[temp]){
                if(visited[ele]==0){
                    visited[ele]=1;
                    q.push(ele);
                    parent[ele]=temp;
                }
                else{
                   if(parent[temp]!=ele)
                    return true;
                }
            }
        }
        return false;
    }


bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    
	    int visited[V+1]{0};
	    for(int i=0; i<V; i++){
	        if(!visited[i] && solve(V, adj, visited, i))
	            return true;
	    }
	    return false;
	}

int main(){
    int n, edges;
    cin>>n>>edges;

    vector<int> graph [n];

    for(int i=0; i<edges; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
   if(isCycle(n, graph)) cout<<"true"<<endl;
   
  else cout<<"false"<<endl;
   return 0;
}