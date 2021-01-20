#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int>b){
    return (b.second>a.second);
}
void maxMeetings(int start[], int end[], int n) {
    // Your code here
    vector<pair<int, int>> vec;
    for(int i = 0; i<n; i++){
        vec.push_back({start[i], end[i]});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    int count = 1, lastEnded = vec[0].second;
    for(int i= 1; i<n; i++){
        if(vec[i].first>lastEnded) {
            count++;
            lastEnded = vec[i].second;
        }
            
    }
    cout<<count;
}

int main(){

    int test;
    cin>>test;

    while(test--){
        int n;
        cin>>n;
        int start[n], end[n];
        for(int i=0; i<n; i++) cin>>start[i];
        for(int i=0; i<n; i++) cin>>end[i];
        maxMeetings(start,end, n);
        cout<<endl;
    }
    return 0;
}