// #include <bits/stdc++.h>
// using namespace std;
// class DSU {
// 	int* parent;
// 	int* rank;

// public:
// 	DSU(int n)
// 	{
// 		parent = new int[n];
// 		rank = new int[n];

// 		for (int i = 0; i < n; i++) {
// 			parent[i] = -1;
// 			rank[i] = 1;
// 		}
// 	}

// 	// Find function
// 	int find(int i)
// 	{
// 		if (parent[i] == -1)
// 			return i;

// 		return parent[i] = find(parent[i]);
// 	}
// 	// union function
// 	void unite(int x, int y)
// 	{
// 		int s1 = find(x);
// 		int s2 = find(y);

// 		if (s1 != s2) {
// 			if (rank[s1] < rank[s2]) {
// 				parent[s1] = s2;
// 				rank[s2] += rank[s1];
// 			}
// 			else {
// 				parent[s2] = s1;
// 				rank[s1] += rank[s2];
// 			}
// 		}
// 	}
// };

// class Graph {
// 	vector<vector<int> > edgelist;
// 	int V;

// public:
// 	Graph(int V) { this->V = V; }

// 	void addEdge(int x, int y, int w)
// 	{
// 		edgelist.push_back({ w, x, y });
// 	}

// 	void kruskals_mst()
// 	{
// 		sort(edgelist.begin(), edgelist.end());
// 		DSU s(V);
// 		int ans = 0;
// 		cout << "Following are the edges in the "
// 				"constructed MST"
// 			<< endl;
// 		for (auto edge : edgelist) {
// 			int w = edge[0];
// 			int x = edge[1];
// 			int y = edge[2];
// 			if (s.find(x) != s.find(y)) {
// 				s.unite(x, y);
// 				ans += w;
// 				cout << x << " -- " << y << " == " << w
// 					<< endl;
// 			}
// 		}
// 		cout << "Minimum Cost Spanning Tree: " << ans;
// 	}
// };
// int main()
// {
// 	Graph g(4);
// 	g.addEdge(0, 1, 10);
// 	g.addEdge(1, 3, 15);
// 	g.addEdge(2, 3, 4);
// 	g.addEdge(2, 0, 6);
// 	g.addEdge(0, 3, 5);

// 	g.kruskals_mst();
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
// class Dsu{
// 	private:
// 		vector<int>p;
// 		int find(int u){
// 			if(p[u]<0) return u;
// 			return p[u] = find(p[u]);
// 		}
// 		void unite(int u, int v){
// 			int pu = find(u), pv = find(v);
// 			if(pu!= pv){
// 				if(p[pu]< p[pv]){
// 					p[pu]+=p[pv];
// 					p[pv] = pu;
// 				}
// 				else{
// 					p[pv]+=p[pu];
// 					p[pu] = pv;
// 				}
// 			}
// 		}
// 	public:
// 	Dsu(int v){
// 		p.resize(v,-1);
// 	}
// 		void kruskal(vector<pair<int, pair<int,int>>> g){
// 			sort(g.begin(), g.end());
// 			vector<pair<int,int>> mst;
// 			int mincost =0;
// 			for(auto x: g){
// 				int u = x.second.first;
// 				int v = x.second.second;
// 				int w = x.first;
// 				if(find(u)!= find(v)){
// 					unite(u,v);
// 					mst.push_back({u,v});
// 					mincost+=w;
// 				}
// 			}
// 			for(auto edge: mst){
// 				cout<<edge.first<<" "<<edge.second<<endl;
// 			}
// 			cout<<"cost "<<mincost;
// 		}

// };

//find part
int find(vector<int>&p, int i){
	return p[i]<0?i:p[i] = find(p,p[i]);
}
void kruskal(vector<pair<int, pair<int, int>>> &g, int n)
{
	sort(g.begin(), g.end());
	int e = g.size();
	vector<pair<int,int>>mst;
	vector<int>p(n,-1);
	int mincost =0;
	for (int i = 0; i < e; i++)
	{
		//extract edges
		int w = g[i].first, u = g[i].second.first , v = g[i].second.second;
		//union part
		int pu = find(p,u), pv = find(p,v);
		if(pu!=pv){
			mincost+=w;
			p[pu] = pv;
			mst.push_back({u,v});
		}
	}
	for (auto edge : mst)
	{
		cout << edge.first << " " << edge.second << endl;
	}
	cout << "cost " << mincost;
}
int main()
{
	int n, e;
	cout << "enter no of vertex and edges:";
	cin >> n >> e;
	vector<pair<int, pair<int, int>>> g;
	cout << "enter edges:";
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({w, {u, v}});
	}
	// Dsu ob(n);
	// ob.kruskal(g);
	kruskal(g, n);
}