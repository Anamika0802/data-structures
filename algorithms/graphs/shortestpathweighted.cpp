#include<bits/stdc++.h>
using namespace std;
void findtoposort(vector<pair<int,int>> g[], vector<int> &vis, int s, stack<int> &st){
    vis[s] = 1;
    for(auto i : g[s]){
        if(vis[i.first]==0){
            findtoposort(g,vis, i.first,st);
        }
    }
    st.push(s);
}
void shortestpath(vector<pair<int,int>>g[], int s, int n){
    vector<int>vis(n,0);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        if(vis[i]==0)findtoposort(g,vis,i, st);
    }
    vector<int>dist(n, INT_MAX);
    dist[s] =0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dist[node]!= INT_MAX){
            for(auto i: g[node]){
                if(dist[node]+ i.second< dist[i.first])
                    dist[i.first] = dist[node] + i.second;
            }
        }
    }

    cout<<"distaces(nodes) from src "<<s<<" to other nodes"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" = ";
        if(dist[i]== INT_MAX)cout<<"inf";
        else cout<<dist[i];
        cout<<endl;
    }   
}
int main(){
    int n,e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<pair<int,int>>g[n];
    cout<<"enter edges:";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});//directed graph
    }
    
    shortestpath(g,0,n);
}