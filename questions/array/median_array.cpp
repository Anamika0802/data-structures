#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find_median(vector<int> v)
{
	sort(v.begin(),v.end());
    int n =v.size();
    if(n%2 !=0)
        return v[n/2];
    else
       return (v[n/2-1]+v[n/2])/2;		    
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>a;
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        a.push_back(ele);
        }
    cout<<"Median :"<<find_median(a);
}