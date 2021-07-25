#include<iostream>
#include<vector>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>>a,int r, int c)
{ 
    int m= r,n =c;
     int i, k = 0, l = 0,j=0;
     vector<int> ans;

    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            ans.push_back(a[k][i]);
        }
        k++;

        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            ans.push_back(a[i][n - 1]);
        }
        n--;

        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                ans.push_back(a[m - 1][i]);
            }
            m--;
        }

        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                ans.push_back(a[i][l]);
            }
            l++;
        }
    }
    return ans;
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
   vector<int>ans =spirallyTraverse(a,r,c); 
   for(auto i:ans){
       cout<<i<<" ";
   }
}