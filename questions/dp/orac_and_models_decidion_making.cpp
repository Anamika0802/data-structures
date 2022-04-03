#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>a){
    int n = a.size(),ans=1;
    vector<int>dp(n,1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j*j < i; j++)
        {
            if(i%j ==0){
                if(i/j==i && a[i]>a[j])
                    dp[i] = max(dp[i],dp[j]+1);
                else{
                    if(a[i]>a[j])
                        dp[i] = max(dp[i],dp[j]+1);
                    if(a[i]>a[i/j])
                        dp[i] = max(dp[i],dp[i/j]+1);
                }
            }
        }
        ans = max(dp[i],ans);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin>>el;
        a.push_back(el);
    }
    cout<<solve(a);
}