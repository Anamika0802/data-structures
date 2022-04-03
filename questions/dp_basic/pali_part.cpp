#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
bool ispali(string s,int i, int j){
    while(i<j){
        if(s[i]!= s[j])
            return false;
        i++;j--;
    }
    return true;
}
int pali_part(string s,int i, int j){
    if(i>=j)return 0;
    if(ispali(s,i,j)) return 0;
    int mi = INT_MAX;
    if(dp[i][j]!= -1)return dp[i][j];
    for (int k = i; k < j; k++)
    {
        int left,right;
        // int ans = pali_part(s,i,k)+pali_part(s,k+1,j)+ 1;
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else 
            {left = pali_part(s,i,k);dp[i][k] = left;}
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else 
            {right = pali_part(s,k+1,j);dp[k+1][j] = right;}
        int ans = left +right +1;
        mi = min(mi,ans);
    }
    return dp[i][j]=mi;
}
int main(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<pali_part(s,0,s.length()-1);
}