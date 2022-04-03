#include<iostream>
#define N 50
using namespace std;
int linear_search(int a[N], int n,int s){
for (int i = 0; i < n; i++)
{
    if(a[i]== s)
    return i+1;
}
return -1;
}
int main(){
int n;
cout<<"enter number of elements";
cin>>n;
int a[N];
cout<<"enter "<<n<<" elements ";
for (int i = 0; i < n; i++)
    cin>>a[i];
cout<<"enter element to be searched ";
int s;
cin>>s;
 cout<<"Index of searched number "<<linear_search(a,n,s);
}