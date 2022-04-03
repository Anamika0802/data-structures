#include<bits/stdc++.h>
using namespace std;
//directed graph
bool dfsdir(int s, vector<int> g[], vector<int>&vis, vector<int>&dfsvis){
    vis[s] = 1;
    dfsvis[s] =1;
    for(auto i : g[s]){
        if(vis[i]==0){
            if(dfsdir(i,g,vis, dfsvis))return true;
        }
        else if(dfsvis[i])return true;
    }
    dfsvis[s] = 0;
    return false;
}
bool cycledetectiondir(vector<int> g[],int n){
    vector<int>vis(n,0);
    vector<int>dfsvis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(dfsdir(i, g,vis,dfsvis)) return true;
        }
    }
    return false;
}
// undirected graph
vector<int>vis;
bool dfs(vector<int> g[], int s, int par){
    vis[s] = 1;
    // cout<<s<<"-->";
    for(auto i : g[s]){
        // cout<<i<<" "<<vis[i]<<endl;
        if(vis[i]==0){
            if(dfs(g, i, s))return true;
        }
        else if(i != par){
            // cout<<i<<" "<<par;
            return true;}
    }
    return false;
}
bool cycledetection(vector<int> g[], int n){
    vis.resize(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(dfs(g,i,-1)) return true;}
    }
    return false;
}
int main(){
    int n,e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<int>g[n];
    cout<<"enter edges:";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(cycledetection(g, n))cout<<"cycle detected";
    else cout<<"no cycle";
}