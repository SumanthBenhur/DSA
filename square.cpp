#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int findSquare(int n){
    if(n==0)
        return 0;
    else if(n<0)
        n = -n;
    int x = n>>1;
    if(n&1 == 0)
        return (findSquare(x)<<2);
    else return ((findSquare(x)<<2) +( x<<2)+1);
}

int main(){

    int n;
    cin>>n;
    cout<<findSquare(n)<<endl;
    return 0;
}
