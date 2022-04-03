#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], vector<int> &vis, int s){
    cout<<s<<" ";
    vis[s] = 1;
    for(auto i : g[s]){
        if(vis[i]==0){
            dfs(g,vis, i);
        }
    }
}
void dfsm(vector<int> g[]){
    int n = g->size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            dfs(g,vis,i);
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
    dfsm(g);
}