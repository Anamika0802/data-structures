#include<bits/stdc++.h>
using namespace std;
bool bipartite(vector<int> g[], vector<int> &colour, int s){
    queue<int>q;
    q.push(s);
    colour[s] = 1;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(auto i: g[c]){
            if(colour[i]==-1){
                colour[i] = 1-colour[c];
                q.push(i);
            }
            else if(colour[i] == colour[c]) return false;
        }
    }
    return true;
}
bool checkbipartite(vector<int>g[],int v){
    vector<int>colour(v,-1);
    for (int i = 0; i < v; i++)
    {
        if(colour[i]==-1)
            if(!bipartite(g,colour,i)) return false;
    }
    return true;
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
    
    if(checkbipartite(g,n))cout<<"YES";
    else cout<<"NO";
}