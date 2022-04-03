#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
   auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
      
  priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>p(cmp);
  for(int i=0;i<n;i++)
    p.push({i,0});
  for(int i=1;i<k;i++){
      auto e =p.top();
      p.pop();
      if(e.second+1<n)p.push({e.first,e.second+1});
  }
  return mat[p.top().first][p.top().second];
}
int main(){
    int n;
    cin>>n;
    int mat[MAX][MAX];
    for(int i=0;i<n;i++)
        for (int j = 0; j < n; j++)
        {
            cin>>mat[i][j];
        }
    int k;
    cin>>k;
    cout<<kthSmallest(mat,n,k);  
}