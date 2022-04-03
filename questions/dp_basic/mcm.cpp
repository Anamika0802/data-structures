#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
int mcm(vector<int>&arr,int i, int j){
    if(i>=j)return 0;
    if(dp[i][j]!= -1)return dp[i][j];
    int mi = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int ans = mcm(arr,i,k)+mcm(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        mi = min(mi,ans);
    }
    return dp[i][j]= mi;
}
int mcm1(vector<int>&arr,int n){
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n-l+1; i++)
        {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int ans = dp[i][k]+dp[k+1][j] +arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j],ans);
            }
        }
        
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<mcm(arr,1,n-1)<<endl;
    memset(dp,-1,sizeof(dp));

    cout<<mcm1(arr,n);
}