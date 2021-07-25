#include<iostream>
#include<algorithm>
using namespace std;
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
void merge(int *a,int *b,int n1,int n2){
    //union is going to be stored in first array and intersection in second array
    int i=0,j=0,k = n1-1;
    while (i<=k && j<n2)
    {
        if(a[i]<b[j]){
           i++;
        }
        else 
        {
            swap(b[j++],a[k--]);
        }
    }
    sort(a,a+n1);
    sort(b,b+n2);
}

int main(){
    int n1,n2;
    cout<<"Entet the size of two arrays: ";
    cin>>n1>>n2;
    int a[n1],b[n2];
    cout<<"Enter the elements of the two arrays: ";
    for (int i = 0; i < n1; i++){cin>>a[i];}
    for (int i = 0; i < n2; i++){cin>>b[i];}
    print(a,n1);
    print(b,n2);
    merge(a,b,n1,n2);
    cout<<"new"<<endl;
    print(a,n1);
    print(b,n2);
}