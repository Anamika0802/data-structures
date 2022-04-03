#include<bits/stdc++.h>
using namespace std;
//memorisation OR  bottom up
const int MAX=10000;
int dp[MAX][MAX];
int solve(vector<int>&len,vector<int>&val,int n,int length){
    if(n==0||length==0)return 0;
    if(dp[n-1][length] != -1) return dp[n-1][length]; 
    if(len[n-1]>length)return dp[n-1][length] = solve(len,val,n-1,length);
    else return dp[n-1][length] =max(solve(len,val,n-1,length),val[n-1]+solve(len,val,n,length-len[n-1]));
}
//tabulation OR top down
int solve1(vector<int>&len,vector<int>&val,int n,int length){
    // int dp[n+1][length+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < length+1; j++)
        {
            if(i==0 || j==0)dp[i][j] = 0;
            else if(len[i-1]>j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i][j- len[i-1]]);
        }
        
    }
    return dp[n][length];
}
int main(){
    int n,length;
    cin>>n;
    vector<int>len(n,0);
    vector<int>val(n,0);
    // for(int i=0;i<n;i++)
    //     cin>>len[i];
    for(int i=0;i<n;i++)
        len[i] = i+1;
    for(int i=0;i<n;i++)
        cin>>val[i];
    // cin>>length;
    length = n;
    memset(dp,-1,sizeof(dp));

    cout<<solve(len,val,n,length)<<endl;
    cout<<solve1(len,val,n,length);


}