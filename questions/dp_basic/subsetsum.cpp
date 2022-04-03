#include<bits/stdc++.h>
using namespace std;
const int MAX=10000;
bool dp[MAX][MAX];
bool solve(vector<int>&arr,int n,int sum){
    if(sum==0)return true;
    else if(n==0)return false;
    if(dp[n-1][sum]!= false) return dp[n-1][sum];
    if(arr[n-1]>sum)return dp[n-1][sum]= solve(arr,n-1,sum);
    else return dp[n-1][sum] =solve(arr,n-1,sum)||solve(arr,n-1,sum-arr[n-1]);
}
//tabulation OR top down
int solve1(vector<int>&arr,int n,int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)dp[i][j] = 1;
            else if(i==0)dp[i][j] = 0;
            else if(arr[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j- arr[i-1]];
        }
        
    }
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>sum;
    memset(dp,false,sizeof(dp));
    cout<<solve(arr,n,sum)<<endl;
    cout<<solve1(arr,n,sum);

}