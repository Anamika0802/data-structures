#include<iostream>
#include<algorithm>
using namespace std;
void minimise_height(int *a,int n,int k){
    int mi ,ma;
    sort(a,a+n);
    int res = a[n-1]-a[0];
    for (int i = 0; i < n; i++)
    {
        ma = max(a[n-1]-k,a[i]+k);
        mi = min(a[0]+k,a[i]-k);
        res = min(res,ma-mi);
    }
    cout<<"Minimise_diff "<<res<<endl;
    
}
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n,k;
    cout<<"Entet the size of array: ";
    cin>>k>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    print(a,n);
    minimise_height(a,n,k);
    print(a,n);
}