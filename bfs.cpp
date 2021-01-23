#include<bits/stdc++.h>
using namespace std;


void BFS(vector<int> graph[], int src, int vertices){
    queue<int> q;
    bool visited[vertices+1];
    for(int i=0; i<vertices; i++){
        visited[i]=false;
    }

    q.push(src);
    visited[src] = true;
    while(q.empty()==false){
        int front = q.front();
        q.pop();
        cout<<"front"<<" ";
        for(auto ele : graph[front]){
            if(!visited[ele]){
                q.push(ele);
                visited[ele] = true;
            }
        }
    }
    
}

// for disconnected graphs

void BFSdisc(vector<int> graph[], bool visited[], int v, int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(q.empty()==false){
        int front = q.front();
        q.pop();
        cout<<"front"<<" ";
        for(auto ele : graph[front]){
            if(!visited[ele]){
                q.push(ele);
                visited[ele] = true;
            }
        }
    }
}

void discDFS(vector <int> graph[], int v){
    bool visited[v+1];
    for(int i=0; i<v; i++) visited[i]=false;

    for(int i=0; i<v; i++){
        if(visited[i]==false){
            BFSdisc(graph, visited, v, i);
        }
    }
}