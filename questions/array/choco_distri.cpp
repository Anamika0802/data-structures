#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    long long diff=INT_MAX;
    for(long long i =0;i<=n-m;i++){
        diff = min(diff,a[i+m-1]-a[i]);
    }
    return diff;
}  
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long>a;
    for (long long i = 0; i < n; i++)
    {
        long long  el;
        cin>>el;
        a.push_back(el);
    }
    cout<<findMinDiff(a,n,m);
}