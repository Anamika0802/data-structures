#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr,int n,int sum){
    if(sum==0)return 1;
    else if(n==0)return 0;
    if(arr[n-1]>sum)return solve(arr,n-1,sum);
    else return solve(arr,n-1,sum)+solve(arr,n-1,sum-arr[n-1]);
}
int main(){
    int n,sum;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>sum;
    cout<<solve(arr,n,sum);

}