#include<iostream>
#include<vector>
using namespace std;
//recursion exponential
// int c =0;
// void countWays(vector<int>a,int s,int t,int i){
//     if(i == a.size()){
//         if(t==s)
//             c++;
//     }
//     else{
//         countWays(a,s,t-a[i],i+1);
//         countWays(a,s,t+a[i],i+1);
//     }
// }
//states in dp
int countWays(vector<int>a,int s){
    if(s>1000)
        return 0;
    int limitSum = 2001;
    int origin = 1000;
    int n = a.size();
    vector<vector<int>>dp(n+1,vector<int>(limitSum,0));
    dp[0][0+origin] =1;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <=limitSum; j++)
        {
            if(dp[i-1][j]>0){
                dp[i][j+a[i-1]] +=dp[i-1][j];
                dp[i][j-a[i-1]] +=dp[i-1][j];
            }
        }
        
    }
    return dp[n][s+origin];
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin>>el;
        a.push_back(el);
    }
    // countWays(a,0,t,0);
    // cout<<c;
    cout<<countWays(a,t);
}