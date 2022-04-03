#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], int s,vector<bool> &vis,vector<int> &disc,vector<int> &low,vector<int> &parent){
    static int time =0;
    vis[s] = true;
    disc[s] = low[s] = ++time;
    for(auto i : g[s]){
        if(!vis[i]){
            parent[i] = s;
            dfs(g,i, vis, disc, low, parent);
            low[s] = min(low[s], low[i]);
            if(low[i]>disc[s])
                cout<<s<<" "<<i<<endl;
        }
        else if(i!=parent[s]){
            low[s] = min(low[s], disc[i]);
        }
    }
}
void dfsm(vector<int> g[],int n){
    vector<bool>vis(n,false);
    vector<int>dist(n,0);
    vector<int>low(n,0);
    vector<int>parent(n,-1);

    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(g,i, vis, dist, low, parent);
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
    dfsm(g,n);
}