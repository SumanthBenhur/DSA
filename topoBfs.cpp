#include <bits/stdc++.h>

using namespace std;

void solve( vector<int>adj[], int n){
    int inOrder[n]{0};
    int processed[n]{0};
    int processTime[n]{0};
    for(int i=0; i<n; i++){
        for(auto ele : adj[i]){
            inOrder[ele]++;
        }
    }
    
    queue<int> q;
    
    for(int i=0; i<n; i++){
        if(inOrder[i]==0){
            q.push(i);
            processTime[i]=1;
        }
    }
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        for(auto ele: adj[temp]){
            inOrder[ele]--;
            
            if(inOrder[ele]==0){
                processTime[ele] = processTime[temp]+1;
            }
            q.push(ele);
        }
    }
    
    for(auto ele: processTime) cout<<ele<<" ";
}

int main()
{
    int n, edges;
    cin>>n>>edges;
    vector<int> adj[n];
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        
    }
    
    solve(adj, n);
    

    return 0;
}
