#include<bits/stdc++.h>
using namespace std;
//for undirected graph only
bool bfs(vector<int> g[], vector<int> &vis, int s){
    queue<pair<int,int>>q;
    q.push({s,-1});
    while(!q.empty()){
        int c = q.front().first;
        int par = q.front().second;
        q.pop();
        vis[c]=1;
        for(auto i: g[c]){
            if(vis[i]==0){
                q.push({i,c});
            }
            else if(par != i) return true;
        }
    }
    return false;
}
bool cycledetect(vector<int>g[],int v){
    vector<int>vis(v,0);

    // bfs(g,vis,s);// if want to start bfs from particular source
    for (int i = 0; i < v; i++)
    {
        if(vis[i]==0)
            if(bfs(g,vis,i))return true;
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
        // cout<<i<<" ";
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(cycledetect(g, n)) cout<<"cycle detected";
    else cout<<"no cycle";
}