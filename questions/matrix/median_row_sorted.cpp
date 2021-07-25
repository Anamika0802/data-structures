#include<bits/stdc++.h>
using namespace std;
int binaryMedian(vector<vector<int>> m, int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
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
   cout<<binaryMedian(a,r,c);
}