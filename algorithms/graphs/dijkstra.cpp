#include<bits/stdc++.h>
using namespace std;
//shortest path algo
#define INF 1e7
typedef pair<int,int> ipair;
void dijstra(vector<pair<int,int> >g[], int s, int V){
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    vector<int> dist(V,INF );
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto i : g[u]){
            int v = i.first;
            int w = i.second;
            if(dist[v]> dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }

    cout<<"v to d"<<endl;
    for (int i = 0; i <V; i++)
    {
       cout<<i<<"   "<<dist[i]<<endl;
    }
    
}
int main(){
    int n,e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<pair<int,int>>g[n];
    cout<<"enter edges:";
    for(int i=0;i<e;i++){
        // cout<<i<<" ";
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijstra(g,0,n);
}