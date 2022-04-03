#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
int dp[MAX][MAX];
int solve(vector<int>&arr,int n,int sum){
    if(sum==0)return 1;
    else if(n==0)return 0;
    if(dp[n-1][sum]!= -1) return dp[n-1][sum];
    if(arr[n-1]>sum)return solve(arr,n-1,sum);
    else return solve(arr,n-1,sum)||solve(arr,n-1,sum-arr[n-1]);
}
int solve1(vector<int>&arr,int n, int sum){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)dp[i][j] == 1;
            else if(i ==0)dp[i][j]==0;
            if(arr[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]||dp[i][j-1];
        }
        
    }
   return dp[n][sum]; 
}
int main(){
    int n,sum=0;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        {cin>>arr[i];sum+=arr[i];}
    memset(dp,-1,sizeof(dp));
    if(sum%2 == 0)
        {cout<<solve(arr,n,sum/2)<<endl;
        cout<<solve1(arr,n,sum/2);
        }
    else
        cout<<"Not possible"<<endl;
    

}