#include<bits/stdc++.h>
using namespace std;
//memorisation
const int MAX = 1000;
int dp[MAX][MAX];
int ans=0;
int lcss(string s1,string s2,int n,int m){
    if(n==0||m==0)return 0;
    if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
    if(s1[n-1]==s2[m-1]){ dp[n-1][m-1]=1+lcss(s1,s2,n-1,m-1);
    ans = max(ans,dp[n-1][m-1]);}
    else dp[n-1][m-1]=0;
    lcss(s1,s2,n-1,m);
    lcss(s1,s2,n,m-1);
    return dp[n-1][m-1];
}
//tabulation
int lcss1(string s1,string s2,int n,int m){
    int ma =0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0||j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1]){dp[i][j] = 1+dp[i-1][j-1];ma = max(ma,dp[i][j]);}
            else dp[i][j] = 0;
        }
        
    }
    return ma;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    lcss(s1,s2,s1.length(),s2.length());
    cout<<ans<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<lcss1(s1,s2,s1.length(),s2.length())<<endl;
}