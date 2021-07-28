#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 10
#define n 5
#define print(a,n) for(int i=1;i<n;i++)cout<<a[i]<<" ";
vector<int> s(MAX_SIZE);
//time = o(N)
void constructTree(int* a){
    for (int i = 0; i <n; i++)
        s[n+i]=a[i];
    for (int i = n-1; i >0; i--)
        s[i]= s[i*2]+s[i*2+1];//s[i<<1] +s[i<<1 |1]; 
}
//time = o(log(N))
void updateTree(int p,int val){
    s[p+n]= val;
    p+=n;
    for(int i = p;i>1;i>>=1)
        s[i>>1]= s[i>>1]+val;//s[i]+s[i^1];
}
//time = o(log(N)) error
// int getMid(int s, int e) { return s + (e -s)/2; }
// int query(int si, int sl, int sr, int l, int r)
// {
// 	if (l <= sl && r >= sr)
// 		return s[si];
// 	if (sr < l || sl > r)
// 		return 0;
// 	int mid = (sl+sr)/2;
// 	return query(2*si,sl,mid,l,r) +
// 		query(2*si+1,mid+1,sr,l,r);
// }

//for zero based indexing
int query(int l,int r){
    r++;
    int res =0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)res+=s[l++];
        if(r&1)res+=s[--r];
    }
    return res;
}
int main(){
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    constructTree(a);
    print(s,MAX_SIZE);
    // cout<<endl;
    // cout<<query(1,0,n-1,0,3);
    cout<<endl;
    cout<<query(1,3);
    // cout<<endl;
    // cout<<query(0,3);
    // cout<<endl;
    // cout<<query(1,2);
    // cout<<endl;
    //updateTree(1 ,7);
    //print(s,MAX_SIZE);
    //cout<<endl;
}