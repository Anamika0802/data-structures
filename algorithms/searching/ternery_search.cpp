#include<iostream>
#define N 50
using namespace std;
int ternary_search(int ar[N],int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(ar,l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(ar,mid2+1,r,x);
        else
            return ternary_search(ar,mid1+1,mid2-1,x);

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
 cout<<"Index of searched number "<<ternary_search(a,0,n,s);
}