#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int edges;
    cin>>edges;

    vector<int> graf [n+1];

    for(int i=0; i<edges; i++){
        int a, b;
        cin>>a>>b;
        graf[b].push_back(a);
        graf[a].push_back(b);
    }

    // code for BFS
    
    queue<int> q;
    
    int visited[n]{0};
    
    q.push(2);
    visited[2]=1;
    while(q.empty()==false){
        int temp = q.front();
        q.pop();
        
        
        for(auto ele: graf[temp]){
            if(visited[ele]==0){
                q.push(ele);
                visited[ele]=1;
            }
        }
        
        
            cout<<temp<<" ";
        
    }
    
    return 0;
}