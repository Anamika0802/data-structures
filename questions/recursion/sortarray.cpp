#include<bits/stdc++.h>
using namespace std;
//sort an array or stack
void insert(vector<int> &a, int temp){
    if(a.size()==0 || a[a.size()-1]<=temp)
        {a.push_back(temp);return;}
    int v = a[a.size()-1];
    a.pop_back();
    insert(a,temp);
    a.push_back(v);
}
void sortarr(vector<int> &a,int n){
    if(n==0)return ;
    int temp = a[n-1];
    a.pop_back();
    sortarr(a,n-1);
    insert(a,temp);

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sortarr(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}