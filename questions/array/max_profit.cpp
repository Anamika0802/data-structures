#include<bits/stdc++.h>
using namespace std;
int max_profit(int * price,int n){
    int dp[n];
    memset(dp,0,n);
    int ma = price[0];
    int mi = price[n-1];
    for(int i=n-2;i>=0;i--)
    {
        ma = max(ma,price[i]);
        dp[i]= max(dp[i+1], ma-price[i]);
    }
    for(int i=1;i<n;i++)
    {
        mi = min(mi,price[i]);
        dp[i]= max(dp[i-1], dp[i] +price[i]-mi);
    }
    return dp[n-1];
}
// void max_profit(int *price,int n){
//     int profit =0,minval =price[0],sub=0,maxval=price[0],maxi =0,mini=0;
//     bool first = false,once = false;
//   for (int i = 1; i < n; i++)
//     {
//         if(minval>price[i]){
//             mini = i;
//             minval = price[i];
//         }
//         if(maxval<price[i]){
//             maxi = i;
//             if(maxi>mini)
//                 maxval = price[i];
//         }
//         if(price[i]-price[i-1]>0 && !once){
//            // cout<<maxval<<" "<<minval<<endl;
//             sub = maxval - minval;
//             once = true;}
//         else
//         {
//                 if(!first){
//                 minval = price[i];
//                 mini = i;
//                 first = true;
//                 once = true;
//                 maxval =0;
//                 maxi=i;}

//         }
//     }
//     if(maxi<=mini)
//         maxval = minval;
//     //cout<<sub<<endl<<maxval<<" "<<minval<<" index "<<maxi<<" "<<mini;
//     cout<<sub +maxval -minval;
// }
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    max_profit(a,n);
}