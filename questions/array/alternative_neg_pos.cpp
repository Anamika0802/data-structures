#include<iostream>
using namespace std;
void alter (int a[], int n)
{
    int p=0; 
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            int t = a[i];
            if(i<p){
                a[i]= a[p];
                i++;
                // a[p]=t;
            }
            for (int j = i; j >p; j--)
                a[j]= a[j-1];
            a[p]= t;
            p+=2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
}
int main(){
    int n;
    cout<<"Entet the size of arrays: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the arrays: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    alter(a,n);
}