#include<iostream>
#include<vector>
using namespace std;
//recursion O(m) m = length of longest string
// bool isSub(string s1,string s2,int i,int j){
//     if(i==s1.length())
//         return true;
//     if (j == s2.length())
//         return false;
//     if(s1[i]==s2[j])
//         return isSub(s1,s2,i+1,j+1);
//     return isSub(s1,s2,i,j+1);
// }
//memorisation
bool isSub(string s1,string s2){
    int n =s2.length(),m=s1.length();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true;
    for (int i = 1; i <= m; i++)
        dp[i][0]=false;
    for (int i = 1; i <= n; i++)
        dp[0][i]=true;
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]= dp[i][j-1];
        }
        
    }
    return dp[m][n];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    //cout<<isSub(s1,s2,0,0);
    cout<<isSub(s1,s2);
}