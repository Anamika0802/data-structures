#include<bits/stdc++.h>
using namespace std;
//shortest path algo
#define INF 1e7
typedef pair<int,int> ipair;
void dijstra(vector<pair<int,int> >g[], int s, int V){
    //make a pq and a dist vector
    priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
    vector<int>dist(V,INF);
    //psuh src in pq
    pq.push({s,0});
    dist[s] = 0;
    while(!pq.empty()){
        //pop from pq;
        auto u = pq.top().first;
        pq.pop();
        for(auto nei: g[u]){
            int v = nei.first;
            int w = nei.second;
            //relax edges
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({v,dist[v]});
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