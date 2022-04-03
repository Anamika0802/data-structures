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
void printlcs(string s1,string s2,int n,int m){
    string res ="";
    while(n>0 && m>0){
        if(s1[n-1]==s2[m-1]){
            res.push_back(s1[n-1]);
            n--;m--;
        }
        else if(dp[n-1][m]>dp[n][m-1]){res.push_back(s1[n-1]);n--;}
        else {res.push_back(s2[m-1]);m--;}
    }
    while(n>0){res.push_back(s1[n-1]);n--;}
    while(m>0){res.push_back(s2[m-1]);m--;}
    reverse(res.begin(),res.end());
    cout<<res;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    int n = s1.length(), m = s2.length();
    // cout<<lcs(s1,s2,s1.length(),s2.length())<<endl;
    /*supersequence is string which contain both s1 and s2 so it is s1+s2
     if take max length but for min s1+s2 - lcs b/c lcs appearce two times */
    memset(dp,-1,sizeof(dp));
    int len =lcs1(s1,s2,n,m);
    cout<<(n+m)-len<<endl;
    printlcs(s1,s2,n,m);
}