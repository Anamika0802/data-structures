#include<iostream>
#include<algorithm>
using namespace std;
void minmax(int *a,int n,int k){
    sort(a,a+n);
    cout<<"Max: "<<a[k]<<" Min: "<<a[n-k-1];
}
int main(){
    int n,k;
    cout<<"Entet the size of array and k: ";
    cin>>n>>k;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    minmax(a,n,k);
}