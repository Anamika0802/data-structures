#include<bits/stdc++.h>
using namespace std;
//sort an array or stack
void insert(stack<int> &a, int temp){
    if(a.size()==0)
        {a.push(temp);return;}
    int v = a.top();
    a.pop();
    insert(a,temp);
    a.push(v);
}
void reversest(stack<int> &s){
    if(s.empty()){return;}
    int temp = s.top();
    s.pop();
    reversest(s);
    insert(s,temp);
    // s.push(temp);

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
    reversest(s);
    for (int i = 0; i < n; i++)
    {
        int a = s.top();
        s.pop();
        cout<<a<<" ";
    }
}