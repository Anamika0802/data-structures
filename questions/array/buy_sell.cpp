#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void buy_sell(vector<int> &a){
    int buy = a[0];
    int max_price = 0;
    for(auto i:a){
        max_price = max(max_price,i-buy);
        if(buy>i)
        buy = i; // buy = min(buy,i);
    }
    cout<<max_price;
}
int main(){
    int n,an;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin>>an;
        a.push_back(an);
    }
    buy_sell(a);
}