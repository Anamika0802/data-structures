#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void merge_intervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        for(auto item :merged){
            cout<<"["<<item[0]<<","<<item[1]<<"]"<<" ";
        }
}   
int main(){
    int n,t;
    cin>>n;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        vector<int>an;
        for (int j = 0; j < 2; j++)
        {
            cin>>t;
            an.push_back(t);
        }
        
        a.push_back(an);
    }
    merge_intervals(a);
}