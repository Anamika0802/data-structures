#include<bits/stdc++.h>
using namespace std;
//shortest path algo
#define INF 1e7
typedef pair<int,int> ipair;
void prims(vector<pair<int,int> >g[], int s, int V){
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    vector<int> key(V,INF );
    vector<int>parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, s});
    key[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]== true)continue;
         inMST[u] = true;

        for(auto i : g[u]){
            int v = i.first;
            int w = i.second;
            if(inMST[v] == false and key[v]> w){
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout<<"MST EDGES"<<endl;
    for (int i = 0; i <V; i++)
    {
       cout<<parent[i]<<"   "<<i<<endl;
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
    prims(g,0,n);
}