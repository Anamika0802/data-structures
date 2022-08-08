#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
vector<pair<int, int>> toremove;
int dir[9] = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
bool dfs(vector<vector<int>> &grid, int sr, int sc, vector<pair<int, int>> &path, int dr, int dc, vector<vector<bool>> &visi)
{
    if (sr < 0 or sc < 0 or sr == grid.size() or sc == grid[0].size() or visi[sr][sc] or grid[sr][sc])
        return false;
    path.push_back({sr, sc});
    visi[sr][sc] = true;
    if (sr == dr and sc == dc)
    {
        ans = path;
        return true;
    }
    for (int i = 0; i < 8; i++)
    {
        int nr = sr + dir[i], nc = sc + dir[i + 1];
        if (dfs(grid, nr, nc, path, dr, dc, visi))
            return true;
    }
    visi[sr][sc] = false;
    path.pop_back();
    return false;
}
void bonus(vector<vector<int>> &grid, int n, int m, int sr, int sc, int dr, int dc)
{
    queue<vector<pair<int, int>>> q;
    vector<vector<bool>> visi(n, vector<bool>(m, 0));
    visi[sr][sc] = true;
    vector<pair<int, int>> s;
    s.push_back({sr, sc});
    q.emplace(s);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto path = q.front();
            q.pop();
            int r = path.back().first, c = path.back().second;
            if (r == dr and c == dc)
            {
                for (auto &p : path)
                {
                    if (grid[p.first][p.second])
                        toremove.push_back(p);
                }
                return;
            }
            for (int i = 0; i < 8; i++)
            {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr < 0 or nc < 0 or nr == n or nc == n or visi[nr][nc])
                    continue;
                visi[nr][nc] = true;
                path.push_back({nr, nc});
                q.emplace(path);
            }
        }
    }
}
void bfs(vector<vector<int>> &grid, int n, int m, int sr, int sc, int dr, int dc)
{
    queue<vector<pair<int, int>>> q;
    vector<vector<bool>> visi(n, vector<bool>(m, 0));
    visi[sr][sc] = true;
    vector<pair<int, int>> s;
    s.push_back({sr, sc});
    q.emplace(s);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto path = q.front();
            q.pop();
            int r = path.back().first, c = path.back().second;
            if (r == dr and c == dc)
            {
                ans = path;
                return;
            }
            for (int i = 0; i < 8; i++)
            {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr < 0 or nc < 0 or nr == n or nc == n or visi[nr][nc] or grid[nr][nc])
                    continue;
                visi[nr][nc] = true;
                path.push_back({nr, nc});
                q.emplace(path);
            }
        }
    }
    cout << "Unable to reach delivery point" << endl;
    cout << "to be removed obsticles" << endl;
    bonus(grid, n, m, sr, sc, dr, dc);
    for (auto &p : toremove)
        cout << "(" << p.first << "," << p.second << "), ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    int sr, sc;
    cin >> sr >> sc;
    int dr, dc;
    cin >> dr >> dc;
    // vector<pair<int, int>> path;
    // vector<vector<bool>> visi(n, vector<bool>(m, 0));
    bfs(mat, n, m, sr, sc, dr, dc);
    // dfs(mat,sr,sc,path,dr,dc,visi);
    for (auto &p : ans)
    {
        cout << "(" << p.first << "," << p.second << "), ";
    }
}