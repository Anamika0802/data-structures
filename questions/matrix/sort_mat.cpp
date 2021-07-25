#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> a ;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                a.push_back(Mat[i][j]);
        }
        sort(a.begin(),a.end());
        int k=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                Mat[i][j]=a[k++];
        }
        return Mat;
    }
int main(){
    int n;
    vector<vector<int>>a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<int>rows;
        for (int j = 0; j < n; j++)
        {
            int el;
            cin>>el;
            rows.push_back(el);
        }
        a.push_back(rows);
    }
   vector<vector<int>>ans =sortedMatrix(n,a);
   for(auto i:ans){
       for(auto j :i){
           cout<<j<<" ";
       }
       cout<<endl;
   }
}