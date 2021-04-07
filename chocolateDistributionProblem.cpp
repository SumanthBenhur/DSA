long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());
    long long i=0;
    long long ans = a[m-1]-a[0];
    while(i+m-1 < n){
        ans = min(ans, a[i+m-1]-a[i]);
        i++;
    }
    return ans;
}