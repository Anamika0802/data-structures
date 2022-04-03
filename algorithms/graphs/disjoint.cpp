#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int find(int u){
	if(p[u]<0) return u;
	return p[u] = find(p[u]);
}
void unite(int u, int v){
	int pu = find(u), pv = find(v);
	if(pu!= pv){
		if(p[pu]< p[pv]){
			p[pu]+=p[pv];
			p[pv] = pu;
		}
	    else{
			p[pv]+=p[pu];
			p[pu] = pv;
		}
        return true;
	}
    cout<<"edge creates a cycle"<<endl;
    return false;
}
int main(){
    int n, e;
    cout<<"enter no of vertex and edges:";
    cin>>n>>e;
    vector<int>g[n];
    p.resize(n,-1);
    cout<<"enter edges:";
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        if(unionset(u,v)){
            g[u].push_back(v);
        }
    }
    
}