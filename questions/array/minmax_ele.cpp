#include<iostream>
using namespace std;
void minmax(int *a,int n){
    int min =a[0],max=a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i]>max)
            max=a[i];

        else if(a[i]<min)
            min=a[i];    
    }
    cout<<"MIN: "<<min<<" MAX: "<<max;   
}
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)cin>>a[i];
    minmax(a,n);
}