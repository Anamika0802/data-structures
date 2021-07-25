#include<iostream>
using namespace std;
void reverse_array(int *a,int back){
    int front =0;
    while (front<back)
    {
        int t = a[front];
        a[front]=a[back];
        a[back]= t;
        front++;
        back--;
    }    
}
void print(int *a,int n){
    cout<<"Array:\n";
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";  
        cout<<"\n"; 
}
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)cin>>a[i];
    print(a,n);
    reverse_array(a,n-1);
    print(a,n);
}