/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define MAX 5
vector<string> sol;

void solve(int m[MAX][MAX], int visited[MAX][MAX], int x, int y, string path, int n){
    if(x==n-1 && y==n-1){
        sol.push_back(path);
        return;
    }
    
    if(m[x][y]==0 || visited[x][y]==1) 
        return;
    visited[x][y]=1;
    if(x>0) //up
    solve(m, visited, x-1, y, path+"U",n);
    if(x<n-1)//down
    solve(m, visited, x+1, y, path+"D",n);
    if(y>0)//left
    solve(m, visited, x, y-1, path+"L",n);
    if(y<n-1)//right
    solve(m, visited, x, y+1, path+"R",n);
    visited[x][y]=0;
}


vector<string> findPath(int m[MAX][MAX], int n) {
    // Your code goes here
    
    int visited[MAX][MAX]{0};
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return sol;
    solve(m, visited, 0, 0, "",n);
    
    return sol;
}



int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int m[MAX][MAX];
        
for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
         cin>>m[i][j];
       }
       
   }
   
   vector<string> result = findPath(m,n);
   if(result.size()==0) cout<<"-1";
   
   else
   for(auto ele : result) cout<<ele<<" ";
   cout<<endl;
    }

    return 0;
}

