#include<bits/stdc++.h>
using namespace std;
//kahn's algo
void bfs(vector<int> g[],int n){
    queue<int>q;
    vector<int>indgree(n,0);
    for(int i =0;i<n;i++){
        for(auto j :g[i]){
            indgree[j]++;
        }
    }
    for(int i=0;i<n;i++)
        if(indgree[i]==0)q.push(i);
    vector<int>topo;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        topo.push_back(c);
        for(auto i: g[c]){
            indgree[i]--;
            if(indgree[i]==0)q.push(i);
        }
    }
    for(auto i:topo){
        cout<<i<<" ";
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
    
    bfs(g,n);
}