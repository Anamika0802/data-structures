#include<bits/stdc++.h>
using namespace std;
//shortest path algo
#define INF 1e7
//negative cycle
void bellman(vector<vector<int>>g, int s, int V, int e){
    vector<int> dist(V,INF );
    dist[s] =0;
    for(int i=0;i< V-1;i++){
        for(int j = 0;j<e;j++){
            int u =g[j][0];
            int v = g[j][1];
            int w = g[j][2];
            if(dist[u] != INF and  dist[u]+ w< dist[v])
                dist[v] = dist[u]+w;
        }
    }
    for(int j = 0;j<e;j++){
        int u =g[j][0];
        int v = g[j][1];
        int w = g[j][2];
        if(dist[u] != INF and  dist[u]+ w< dist[v])
           {cout<<"Negative cycle";break;}
    }

    cout<<"v ---> d"<<endl;
    for (int i = 0; i <V; i++)
    {
       cout<<i<<"   "<<dist[i]<<endl;
    }
    
}
int main(){
    int n,e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<vector<int>>g;
    cout<<"enter edges:";
    for(int i=0;i<e;i++){
        vector<int>t(3,0);
        cin>>t[0]>>t[1]>>t[2];
        g.push_back(t);
    }
    bellman(g,0,n, e);
}