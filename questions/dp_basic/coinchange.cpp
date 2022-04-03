#include<bits/stdc++.h>
using namespace std;
//memorisation OR  bottom up
const int MAX=10000;
int dp[MAX][MAX];
int solve(vector<int>&val,int n,int sum){
    if(sum==0)return 1;
    else if(n==0)return 0;
    if(dp[n-1][sum] != -1) return dp[n-1][sum]; 
    if(val[n-1]>sum)return dp[n-1][sum] = solve(val,n-1,sum);
    else return dp[n-1][sum] =solve(val,n-1,sum)+solve(val,n,sum-val[n-1]);
}
//tabulation OR top down
int solve1(vector<int>&val,int n,int sum){
    // int dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)dp[i][j] = 1;
            else if(i==0)dp[i][j]= 0;
            else if(val[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]+ dp[i][j- val[i-1]];
        }
        
    }
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n;
    // vector<int>val(n,0);
    vector<int>val(n,0);
    // for(int i=0;i<n;i++)
    //     cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cin>>sum;
    memset(dp,-1,sizeof(dp));

    cout<<solve(val,n,sum)<<endl;
    cout<<solve1(val,n,sum);


}