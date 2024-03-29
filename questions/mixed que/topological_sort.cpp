/* 5-->2,2-->3,3-->1,5-->0,4-->0,4-->1
 topo sort vet before its childs 5,4,2,3,1,0 or 4,5,3,3,1,0
 dfs = 5,2,3,1,0,4 */
 #include<bits/stdc++.h>
 using namespace std;
 class Graph{
     int V;
     list<int>* adj;
     Graph(int V){
         this.V =V;
         adj = new list<int>[V];
     }
     void add_edge(int v,int w){
         adj[v].push_back(w);
     }
    void topologicalSortUtil(int v, bool visited[],stack<int>& Stack)
    {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, Stack);
        Stack.push(v);
    }
    void topologicalSort()
    {
        stack<int> Stack;
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, Stack);
        while (Stack.empty() == false) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

 }
 int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given "
			"graph \n";
	g.topologicalSort();

	return 0;
}