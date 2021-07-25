#include<iostream>
using namespace std;
int minimum_jumps(int *a,int n){
   if(n<=1)
        return 0;
        if(a[0]==0)
        return -1;
        int maxreach = a[0];
        int step = a[0];
        int jump =1;
        for(int i=1;i<n;i++){
            if(i==n-1)return jump;
            maxreach = max(maxreach, a[i]+i);
            step--;
            if(step ==0){
                jump++;
                if(i>=maxreach)return -1;
                step = maxreach -i;
            }
        }
        return -1;
}
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    cout<<minimum_jumps(a,n);
    //print(a,n);
}