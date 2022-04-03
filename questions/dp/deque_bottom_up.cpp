#include<iostream>
#include<vector>
using namespace std;
//recurssion
// long long int solve(long long int** dp, long long int* arr, long long int l, long long int r)
// {
// 	if(l > r)
// 		return  0;
// 	if(l == r)
// 		return arr[l];
// 	if(dp[l][r]!=-1)
// 		return dp[l][r];
// 	long long int ans = arr[l] - solve(dp,arr,l+1,r);
// 	ans = max(ans,arr[r]-solve(dp,arr,l,r-1));
// 	dp[l][r] = ans;
// 	return ans;
 
// }
//bottom up
int minimiseDiff(vector<int> &a){
    int n=a.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
        dp[i][i]=a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            dp[j][j+i] = max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
        }
        
    }
   return dp[0][n-1]; 
}
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    cout<<minimiseDiff(a);
}