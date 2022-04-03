#include<iostream>
#define N 50
using namespace std;
int binary_search(int a[N], int n,int s){
int f = 0, l = n-1;
while (f<=l)
{
    int mid =(f+l)/2;
    if(s==a[mid])
    return mid+1;
    if(a[mid]<s)
    f= mid+1;
    else
    l = mid-1;
}
return -1;
}
int main(){
int n;
cout<<"enter number of elements";
cin>>n;
int a[N];
cout<<"enter "<<n<<" sorted elements ";
for (int i = 0; i < n; i++)
    cin>>a[i];
cout<<"enter element to be searched ";
int s;
cin>>s;
 cout<<"Index of searched number "<<linear_search(a,n,s);
}