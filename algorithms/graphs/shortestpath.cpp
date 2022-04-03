#include<bits/stdc++.h>
using namespace std;
//undirected graph with unit or same weight
void bfs(vector<int> g[],int n, int s){
    vector<int>dist(n,INT_MAX);
    queue<int>q;
    dist[s] =0;
    q.push(s);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(auto i: g[c]){
            if(dist[c]+1<dist[i]){
                dist[i] = dist[c]+1;
                q.push(i);
            }
        }
    }
    cout<<"distaces(nodes) from src "<<s<<" other nodes"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" -----> "<<dist[i]<<endl;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    bfs(g,n,0);
}