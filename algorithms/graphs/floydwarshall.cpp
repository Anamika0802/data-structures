#include<bits/stdc++.h>
using namespace std;
//shortest path algo
#define INF 1e7
//negative cycle
void floyd(vector<vector<int>>g,int V){
    
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(g[i][j]> g[i][k]+ g[k][j])
                    g[i][j]= g[i][k]+ g[k][j];
            }
            
        }
        
    }
    

    cout<<"shortest paths"<<endl;
    for (int i = 0; i <V; i++)
    {
       for (int j = 0; j < V; j++)
       {
           cout<<g[i][j]<< " ";
       }
       cout<<endl;
    }
    
}
int main(){
    int n,e;
    cout<<"enter no of vertex:";
    cin>>n;
    vector<vector<int>>g(n,vector<int>(n,0));
    cout<<"enter edges:";
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cin>>g[i][j];
        }
        
    }
    floyd(g,n);
}