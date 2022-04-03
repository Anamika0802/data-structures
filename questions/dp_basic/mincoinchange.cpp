#include<bits/stdc++.h>
using namespace std;
//memorisation OR  bottom up
const int MAX=10000;
int dp[MAX][MAX];
int solve(vector<int>&val,int n,int sum){
    if(n==0)return INT_MAX-1;
    else if(sum==0)return 0;
    else if(n==1){
        if(sum%val[n-1]==0)return dp[n-1][sum] = sum/val[n-1];
        else return dp[n-1][sum] = INT_MAX -1;
    } 
    if(dp[n-1][sum] != -1) return dp[n-1][sum]; 
    if(val[n-1]>sum)return dp[n-1][sum] = solve(val,n-1,sum);
    else return dp[n-1][sum] =min(solve(val,n-1,sum),1+solve(val,n,sum-val[n-1]));
}
//tabulation OR top down
int solve1(vector<int>&val,int n,int sum){
    // int dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)dp[i][j]=INT_MAX-1;
            else if(j==0)dp[i][j]= 0;
            else if(i==1){
            if(j%val[i-1]==0) dp[i-1][j] = j/val[i-1];
            else dp[i-1][sum] = INT_MAX -1;
            } 
            else if(val[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j],1+dp[i][j- val[i-1]]);
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