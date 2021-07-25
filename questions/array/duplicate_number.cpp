#include<iostream>
#include<vector>
using namespace std;
void findDuplicate(vector<int>& nums) {
        vector<bool>found(nums.size(),false);//or use sets
        for(auto i:nums){
           // cout<<"<<"<<i<<">>";
            if(found[i]==false)
                found[i]= true;
            else
                cout<<i;
    }
}
int main(){
    int n,an;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin>>an;
        a.push_back(an);
    }
    findDuplicate(a);
}