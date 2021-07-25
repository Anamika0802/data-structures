#include<iostream>
#include<set>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m) {
    set<int>ele;
    string ans = "Yes";
    for(int i =0;i<n;i++){
        ele.insert(a1[i]);
    }
    for(int i =0;i<m;i++){
        if(ele.find(a2[i])==ele.end())
            ans = "No";
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Entet the size of the two array: ";
    cin>>n>>m;
    int a1[n],a2[m];
    cout<<"Enter the elements of the two array: ";
    for (int i = 0; i < n; i++){cin>>a1[i];}
    for (int i = 0; i < m; i++){cin>>a2[i];}
    //print(a,n);
    cout<<isSubset(a1,a2,n,m);
}