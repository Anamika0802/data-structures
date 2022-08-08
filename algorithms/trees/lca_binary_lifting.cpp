#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> up;
vector<int> depth;
int LOG;
//binary lifting
void treeAncestor(int n, vector<int> &parent)
{
    LOG = 0; // number of ancestors that are possible
    while ((1 << LOG) <= n)
    {
        LOG++;
    }
    up.resize(n, vector<int>(LOG));
    depth.resize(n, 0);
    parent[0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        up[i][0] = parent[i]; //initialising first anc
    }
    for (int j = 1; j < LOG; j++)
    { //for each ancestor
        //sequence of for loop is impo b/c we require the ancestors of big or small
        //nodes to initialise a node's all ancestors
        for (int i = 0; i < n; i++)
        { // initialise the jth ancestor of each node
            if (i != 0)
                depth[i] = depth[parent[i]] + 1;
            up[i][j] = up[up[i][j - 1]][j - 1];
            //up[me][1] = up[up[me][0]][0]
            //2nd anc of me is the first anc of my par
        }
    }
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    for (int l = LOG - 1; l >= 0; l--) // kth anc
    {
        if ((k >> l) & 1)
        {
            u = up[u][l];
        }
    }
    if(u==v) return u;
    for (int l = LOG - 1; l >= 0; l--){
        if(up[u][l] != up[v][l]){ 
            // this will move us as close as possible to the lca 
            //(u and v become the children of the lca at the end of loop)
            u = up[u][l];
            v = up[v][l];
        }
    }
    return up[u][0];
}
int main()
{
    int n;
    cin >> n;
    vector<int> par(n, 0);
    for (int i = 0; i < n; i++)
    {
        int children;
        cin >> children;
        for (int j = 0; j < children; j++)
        {
            int c;
            cin >> c;
            par[c] = i;
        }
    }
    treeAncestor(n, par);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}