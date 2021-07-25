#include<iostream>
#include<algorithm>
using namespace std;
void sort_012(int *a,int n){
    int f=0,m=0,l=n-1;
    while (m<=l)
    {
        if(a[m]==0){
            int t=a[f];
            a[f]=a[m];
            a[m]=t;
            m++;f++;
        }
        else if(a[m]==1){
            m++;
        }
        else
        {
            int t=a[l];
            a[l]=a[m];
            a[m]=t;
            l--;
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
    sort_012(a,n);
    print(a,n);
}