#include<iostream>
using namespace std;
void cyclically_once(int *a,int n){
    int t = a[n-1];
    for (int i = n-1; i >=0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=t;
}
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    print(a,n);
    cyclically_once(a,n);
    print(a,n);
}