#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isValid(int i,int j, int m, int n){
    return i>=0 && i<m && j>=0 && j<n;
}
void bfs(vector<vector<int>> &g,vector<vector<int>> &visited, int i,int j ){
    int m = g.size(),n = g[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    //int r[] = {-1,-1,-1,0,0,1,1,1};
    //int c[] = {-1,0,1,-1,1,-1,0,1};
    int r[] = {-1,0,0,1};
    int c[] = {0,-1,1,0};
    while (!q.empty())
    {
        int oldi = q.front().first, oldj = q.front().second;
        q.pop();
        visited[oldi][oldj]=1;
        for (int k = 0; k < 8; k++)
        {
            int newi =oldi +r[k], newj = oldj + c[k];
            if(isValid(newi, newj,m,n)&& g[newi][newj]==1 && visited[newi][newj] ==0){
            visited[newi][newj]= 1;
            q.push(make_pair(newi, newj));
            }
        }
        
    }
    
}
void dfs(vector<vector<int>> &g,vector<vector<int>> &visited, int i,int j ){
    int m = g.size(),n = g[0].size();
    visited[i][j]= 1;
    //int r[] = {-1,-1,-1,0,0,1,1,1};
    //int c[] = {-1,0,1,-1,1,-1,0,1};
    int r[] = {-1,0,0,1};
    int c[] = {0,-1,1,0};
    for (int  k = 0; k < 4; k++)
    {
        int newi = i+ r[k], newj = j+ c[k];
        if(isValid(newi,newj,m,n)&& g[newi][newj] == 1 && visited[newi][newj]==0)
        dfs(g,visited,newi,newj);
    }  
}
int connectedComponents(vector<vector<int>> &g){
    int count =0;
    int m = g.size(), n= g[0].size();
    vector<vector<int>> visited(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i].push_back(0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(g[i][j]==1 && visited[i][j]==0){
                count++;
                //dfs(g,visited,i,j);
                bfs(g,visited,i,j);
            }
return count;
}
int main(){
int m,n,k;
cin>>m>>n;
vector<vector<int>> g(m);
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++){
        cin>>k;
        g[i].push_back(k);
    }
   cout<< connectedComponents(g);
}