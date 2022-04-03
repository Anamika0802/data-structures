#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int>&arr,int i, int j){
    if(i>=j)return 0;
    int ma = INT_MIN;
    for (int k = i; k < j; k++)
    {
        int ans = mcm(arr,i,k)+mcm(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        ma = max(ma,ans);
    }
    return ma;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<mcm(arr,1,n-1);
}