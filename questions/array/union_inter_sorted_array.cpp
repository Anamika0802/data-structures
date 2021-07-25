#include<iostream>
using namespace std;
void union_intersection(int *a,int *b,int n1,int n2){
    int i=0,j=0;
    cout<<"Union: ";
    while (i<n1 && j<n2)
    {
        if(a[i]<b[j]){
           cout<<a[i++]<<" ";
        }
        else if (b[j]<a[i])
        {
           cout<<b[j++]<<" ";
        }
        else{
            cout<<b[j++]<<" ";
            i++;
        }
    }
    while(j<n2){
        cout<<b[j++]<<" ";
    }
    while(i<n1){
        cout<<a[i++]<<" ";
    }
    cout<<endl<<"Intersection: ";
    i=0,j=0;
    while (i<n1||j<n2)
    {
        if(a[i]==b[j]){
            cout<<a[i++]<<" ";
            j++;
            }
        else if(a[i]<b[j])i++;
        else j++;
    }
    
}
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
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
    union_intersection(a,b,n1,n2);
}