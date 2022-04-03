#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> g[], vector<int> &vis, int s){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        cout<<c<<" ";
        vis[c]=1;
        for(auto i: g[c]){
            if(vis[i]==0){
                q.push(i);
            }
        }
    }
}
void bfsm(vector<int>g[], int s, int n){
    vector<int>vis(n,0);
    bfs(g,vis,s);// if want to start bfs from particular source
    for (int i = 0; i < v; i++)
    {
        if(vis[i]==0)bfs(g,vis,i);
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
    
    bfsm(g,1,n);
}