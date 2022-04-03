#include<iostream>
#include<math.h>
#define N 50
using namespace std;
int jump_search(int a[N], int n,int s){
int j = sqrt(n);
int i=0;
while (i<n)
{
    if(a[i]==s)
    return i+1;
    if(s>a[i])
    i+=j;
    else
    {
        i-=j;
        for (int k = i; k < j; k++)
        {
            if(a[i]==s)
            return i+1;
        }
        
    }
    
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