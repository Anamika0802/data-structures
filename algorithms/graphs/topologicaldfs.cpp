#include<bits/stdc++.h>
using namespace std;
void topoutil(vector<int> g[], vector<int> &vis, int s, stack<int> &st){
    vis[s] = 1;
    for(auto i : g[s]){
        if(vis[i]==0){
            topoutil(g,vis, i,st);
        }
    }
    st.push(s);
}
void topo(vector<int> g[],int n){
    vector<int>vis(n,0);
    stack<int>s;
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            topoutil(g,vis,i,s);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    int n,e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<int>g[n];
    cout<<"enter edges:";
    for(int i=0;i<e;i++){
        // cout<<i<<" ";
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//directed graph
    }
    topo(g,n);
}