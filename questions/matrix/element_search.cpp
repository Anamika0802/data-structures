#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        for(int i=0;i<m;i++){
            int n = matrix[i].size();
            if(target>=matrix[i][0]&& target <= matrix[i][n-1]){
                for(int j=0;j<n;j++){
                    if(target == matrix[i][j])
                        return true;
                }
            }
        }
        return false;
}
int main(){
    int r,c,target;
    vector<vector<int>>a;
    cin>>r>>c;
    cin>>target;
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
   cout<<searchMatrix(a,target); 
}