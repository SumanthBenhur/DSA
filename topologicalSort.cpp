#include <bits/stdc++.h>

using namespace std;

class Solution{
	public:
	
	void dfs(int V, vector<int> adj[], int visited[], int src, vector<int> &s){
	    
	    visited[src] = 1;
	    for(auto ele : adj[src]){
	        if(!visited[ele]){
	            dfs(V, adj, visited, ele,s);
	        }
	        
	    }
	    s.push_back(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int>s;
	    int visited[V+1]{0};
	    for(int i=0; i<V; i++){
	        dfs(V, adj, visited, i, s);
	    }
	    
	    int i=0, j=s.size()-1;
	    while(i<j){
	        swap(s[i], s[j]);
	        i++;
	        j--;
	    }
	    return s;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

       for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return  0;
}  // } Driver Code End
