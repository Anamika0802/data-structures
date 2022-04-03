#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<int> g[], vector<int> &colour, int s){
    for(auto i : g[s]){
        if(colour[i]==-1){
            colour[i] = 1- colour[s];
            if(!bipartite(g,colour, i)) return false;
        }
        else if(colour[i]== colour[s])return false;
    }
    cout<<endl;
    return true;
}
bool checkbipartite(vector<int> g[], int n){
    vector<int>colour(n,-1);
    for(int i=0;i<n;i++){
        if(colour[i]==-1){
            colour[i] = 1;
            if(!bipartite(g,colour,i)) return false;
        }
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
        g[u].push_back(v);//directed graph
    }
    if(checkbipartite(g,n))cout<<"YES";
    else cout<<"NO";
}