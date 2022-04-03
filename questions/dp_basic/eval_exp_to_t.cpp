#include<bits/stdc++.h>
using namespace std;
int const MAX = 1000;
int dp[MAX][MAX];
int solve(string s,int i,int j, bool istrue){
    if(i==j){
        if(istrue)return s[i] == 'T';
        else s[i] == 'F';
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int truecnt =0,falsecnt = 0;
    for (int k = i+1; k <=j; k+=2)
    {
        int lt = solve(s,i,k, true);
        int lf = solve(s,i,k, false);
        int rt = solve(s,k+1,j, true);
        int rf = solve(s,k+1,j, false);
        if(s[k] == '&'){
            truecnt += lt*rt;
            falsecnt +=(lf*rf +lf*rt +lt*rf);
        }
        else if(s[k]=='|'){
            truecnt+= (lt*rt +lt*rf +lf*rt);
            falsecnt += lf*rf;
        }
        else
        {
            truecnt += (lt*rf +lf*rt);
            falsecnt += (lf*rf +lt*rt);
        }
        
    }
    return dp[i][j] =truecnt;
}
int main(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,s.length()-1,false);
}