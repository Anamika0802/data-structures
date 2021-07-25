#include<iostream>
#include<string>
using namespace std;
int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++){
        int c=0;
        string s = to_string(a[i]);
        int n= s.length();
        //cout<<s<<endl;
        for (int j = 0; j < n/2; j++)
        {
            if(s[j]!=s[n-j-1])
                return 0;
        }    
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    cout<<"Palin Aarray :"<<PalinArray(a,n);
}