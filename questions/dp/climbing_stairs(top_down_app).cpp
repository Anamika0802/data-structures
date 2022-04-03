#include<iostream>
#include<vector>
using namespace std;
//recursion O(n)
// int dp[n];
// dp[0]=1;dp[1]=1;
// int count_possib(int n){
//     if(dp[n]!=0)
//         return dp[n];
//     count_possib(n-1)+count_possib(n-2);
//     return dp[n];
// }
//iterative O(n)
int count_possib(int n){
    int dp[n];
    dp[0]=1;dp[1]=1;
    for (int i = 0; i <= n; i++)
    {
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    // vector<int> a;
    // for (int i = 0; i < n; i++)
    // {
    //     int el;
    //     cin>>el;
    //     a.push_back(el);
    // }
    cout<<count_possib(n);
}