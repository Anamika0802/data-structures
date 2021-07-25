#include<iostream>
#include<map>
using namespace std;
void ndk_counts(int *a,int n, int k){
    map<int,int>count;
    if(k<2)
        return;
    // for (int i = 0; i < n; i++)
    //     count[n]=0;
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for(auto i :count){
        if(i.second>n/k)
            cout<< i.first<<" ";
    }
}
int main(){
    int n,k;
    cout<<"Entet the size of array and k: ";
    cin>>n>>k;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    ndk_counts(a,n,k);
}