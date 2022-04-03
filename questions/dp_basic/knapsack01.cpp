#include<bits/stdc++.h>
using namespace std;
//memorisation OR  bottom up
const int MAX=10000;
int dp[MAX][MAX];
int solve(vector<int>&wt,vector<int>&val,int n,int cap){
    if(n==0||cap==0)return 0;
    if(dp[n-1][cap] != -1) return dp[n-1][cap]; 
    if(wt[n-1]>cap)return dp[n-1][cap] = solve(wt,val,n-1,cap);
    else return dp[n-1][cap] =max(solve(wt,val,n-1,cap),val[n-1]+solve(wt,val,n-1,cap-wt[n-1]));
}
//tabulation OR top down
int solve1(vector<int>&wt,vector<int>&val,int n,int cap){
    // int dp[n+1][cap+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < cap+1; j++)
        {
            if(i==0 || j==0)dp[i][j] = 0;
            else if(wt[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j- wt[i-1]]);
        }
        
    }
    return dp[n][cap];
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
    memset(dp,-1,sizeof(dp));

    cout<<solve(wt,val,n,capacity)<<endl;
    cout<<solve1(wt,val,n,capacity);


}