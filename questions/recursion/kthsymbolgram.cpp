#include<bits/stdc++.h>
using namespace std;
int kthGrammar(int n, int k) {
        if(n==1 || k==1)return 0;
        int mid = (1<<(n-1))/2;
        if(k<=mid) return kthGrammar(n-1,k);
        else return !kthGrammar(n-1,k-mid);
    }
int main(){
    /*0
      0 1
      0 1 1 0
      0 1 1 0 1 0 0 1
      */
     int n,k;
     cin>>n>>k;
     cout<<find(n,k);
}