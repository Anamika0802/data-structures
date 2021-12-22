#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
void next_permutaion(vector<int>& nums) {
    int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
        for(auto i:nums){
            cout<<i<<" ";
        }
}
int main(){
    int n,an;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin>>a[i];
    next_permutaion(a);
}