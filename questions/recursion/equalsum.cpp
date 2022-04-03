#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&arr,int n,int sum){
    if(sum==0)return true;
    else if(n==0)return false;
    if(arr[n-1]>sum)return solve(arr,n-1,sum);
    else return solve(arr,n-1,sum)||solve(arr,n-1,sum-arr[n-1]);
}
int main(){
    int n,sum=0;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        {cin>>arr[i];sum+=arr[i];}
    if(sum%2 == 0)
        cout<<solve(arr,n,sum/2);
    else
        cout<<"Not possible"<<endl;
    

}