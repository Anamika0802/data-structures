#include<iostream>
using namespace std;
void neg_one_side(int *a,int n){
    int f=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            int t = a[i];
            a[i]=a[f];
            a[f]= t;
            f++;
        }
    }
    
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
    neg_one_side(a,n);
    print(a,n);
}