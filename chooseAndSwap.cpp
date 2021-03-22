#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string a){
        int pos[26];
        for(int i=0; i<26; i++) pos[i]=-1;
        
        for(int i=0; i<a.length(); i++){
            if(pos[a[i]-97]==-1){
                pos[a[i]-97]=i;
            }
        }
        
        int ptr = -1;
        char small ;
        char big ;
        for(int i=0; i<a.length(); i++){
            small = a[i]; big = a[i];
            for(int j=0; j<a[i]-97; j++){
                if(pos[j]!=-1 && pos[j]>pos[a[i]-97]){
                    big = ((char)(j+97));
                    break;
                }
            }
            
            if(small!=big) break;
        }
        
        for(int i=0; i<a.length(); i++){
            if(a[i]==small) a[i]=big;
            else if(a[i]==big) a[i]=small;
        }
        
        return a;
    }
    
int main(){
    
    string a;
    cin>>a;
    cout<<chooseandswap(a)<<endl;
    return 0;
}  
