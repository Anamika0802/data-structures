#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&wt,vector<int>&val,int n,int cap){
    if(n==0||cap==0)return 0;
    if(wt[n-1]>cap)return solve(wt,val,n-1,cap);
    else return max(solve(wt,val,n-1,cap),val[n-1]+solve(wt,val,n-1,cap-wt[n-1]));
}
int main(){
    int n,capacity;
    cin>>n;
    vector<int>wt(n,0);
    vector<int>val(n,0);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cin>>capacity;
    cout<<solve(wt,val,n,capacity);

}