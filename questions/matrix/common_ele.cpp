#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 
void common_ele(vector<vector<int>> &a,int r,int c)
{
    unordered_map<int,int>mp;
    for(int i =0;i<c;i++)
        mp[a[0][i]]=1;
    for(int i =1;i<r;i++){
        for(int j =0;j<c;j++){
            if(mp[a[i][j]]==i){
                mp[a[i][j]] = i+1;
                if(i == r-1 && mp[a[i][j]]==r)
                     cout<<a[i][j]<<" ";
            }
        }
    }
}
int main(){
    int r,c;
    vector<vector<int>>a;
    cin>>r>>c;
    for (int i = 0; i < r; i++)
    {
        vector<int>rows;
        for (int j = 0; j < c; j++)
        {
            int el;
            cin>>el;
            rows.push_back(el);
        }
        a.push_back(rows);
    }
   common_ele(a,r,c); 
}