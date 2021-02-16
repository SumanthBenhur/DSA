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

    for(int i=0; i<=n; i++){
        for(auto ele : graf[i])
            cout<<ele<<" ";
        cout<<endl;
    }

    return 0;
}