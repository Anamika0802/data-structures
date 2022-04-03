#include<bits/stdc++.h>
using namespace std;
void findtoposort(vector<int> g[], vector<bool> &vis, int s, stack<int> &st){
    vis[s] = true;
    for(auto i : g[s]){
        if(vis[i]==false){
            findtoposort(g,vis, i,st);
        }
    }
    st.push(s);
}
void dfs(vector<int> g[], vector<bool> &vis, int s){
    cout<<s<<" ";
    vis[s] = true;
    for(auto i : g[s]){
        if(!vis[i]){
            dfs(g,vis, i);
        }
    }
}
void printSCC(vector<int> g[], int n){
    stack<int>st;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i])
            findtoposort(g, vis,i,st);
    }
    
    vector<int>gr[n];
    for (int i = 0; i < n; i++)
    {
        for(auto j: g[i]){
            gr[j].push_back(i);
        }
    }

    vis.clear();
    vis.resize(n,false);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(!vis[v]){
            dfs(gr,vis, v);
            cout<<endl;
        }
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
    printSCC(g, n);
}