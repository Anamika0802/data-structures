#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], int s,vector<bool> &vis,vector<int> &disc,vector<int> &low,int par,vector<bool> &isAp){
    static int time =0;
    int children =0;
    vis[s] = true;
    disc[s] = low[s] = ++time;
    for(auto i : g[s]){
        if(!vis[i]){
            children++;
            dfs(g,i, vis, disc, low, s, isAp);
            low[s] = min(low[s], low[i]);
            if(par!=-1 and low[i]>=disc[s])
                isAp[s] = true;
        }
        else if(i!=par){
            low[s] = min(low[s], disc[i]);
        }
    }
    if(par ==-1 and children>1)isAp[s] = true;
}
void dfsm(vector<int> g[],int n){
    vector<bool>vis(n,false);
    vector<int>dist(n,0);
    vector<int>low(n,0);
    vector<bool> isAp(n,false);
    int par =-1;
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(g,i, vis, dist, low, par, isAp);
    }
    for (int i = 0; i < n; i++)
    {
        if(isAp[i]== true)cout<<i<<" ";
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