#include<bits/stdc++.h>
using namespace std;
void delmid(stack<int> &s,int k){
    if(k==1){s.pop();return;}
    int temp = s.top();
    s.pop();
    delmid(s,k-1);
    // insert(s,temp);
    s.push(temp);

}
int main(){
    int n;
    cin>>n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }
    delmid(s,(n+1)/2);
    for (int i = 0; i < n; i++)
    {
        int a = s.top();
        s.pop();
        cout<<a<<" ";
    }
}