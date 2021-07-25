#include<iostream>
#include<vector>
using namespace std;
void threeWayPartition(vector<int>& arr,int lowVal, int highVal)
{   
      int start = 0, end = arr.size()-1;
    for (int i=0; i<=end;)
    {
        if (arr[i] < lowVal)
            swap(arr[i++], arr[start++]);
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
 
        else
            i++;
    }
}
void print(vector<int>a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int low,high,n;
    cin>>n>>low,high;
    vector<int>a;
    for ( int i = 0; i < n; i++)
    {
        int  el;
        cin>>el;
        a.push_back(el);
    }
    print(a,n);
    threeWayPartition(a,low,high);
    print(a,n);
}
