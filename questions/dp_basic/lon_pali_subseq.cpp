#include<bits/stdc++.h>
using namespace std;
//memorisation
const int MAX = 1000;
int dp[MAX][MAX];
int lcs(string s1,string s2,int n,int m){
    if(n==0||m==0)return 0;
    if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
    if(s1[n-1]==s2[m-1]) return dp[n-1][m-1]=1+lcs(s1,s2,n-1,m-1);
    else return dp[n-1][m-1]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
}
//tabulation
int lcs1(string s1,string s2,int n,int m){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0||j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
    return dp[n][m];
}
int main(){
    string s1;
    cin>>s1;
    memset(dp,-1,sizeof(dp));
    int n = s1.length();
    // cout<<lcs(s1,s2,s1.length(),s2.length())<<endl;
    /*for finding longest palindromic subsequence is lcs b/w str and its reverse */
    // memset(dp,-1,sizeof(dp));
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    cout<<lcs1(s1,s2,n,n)<<endl;
}