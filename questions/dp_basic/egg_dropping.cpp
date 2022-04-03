#include<bits/stdc++.h>
using namespace std;
int const MAX = 50;
int dp[MAX][MAX];
int attempts(int f,int e){
    if(e==1) return f;
    if(f<=1) return f;
    int mi= INT_MAX;
    if(dp[f][e]!=-1) return dp[f][e];
    for (int i = 1; i <= f; i++)
    {
        int ans = 1+max(attempts(f-i,e) , attempts(i-1,e-1));
        mi = min(mi, ans);
    }
    return dp[f][e]=mi;
}
int main(){
    int f,e;
    cin>>f>>e;
    memset(dp,-1,sizeof(dp));
    cout<<attempts(f,e);
}