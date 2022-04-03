#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&val,int i,int k,int &ans){
    if(val.size()==1){ ans = val[0];return;}
    i =(i+k)%val.size();
    val.erase(val.begin()+i);
    solve(val,i,k,ans);
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
        v[i] = i+1;
    int ans;
    solve(v,0,k,ans);
    cout<<ans;
}