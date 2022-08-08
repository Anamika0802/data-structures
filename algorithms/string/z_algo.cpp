#include<bits/stdc++.h>
using namespace std;
void z_algo(string s, int m){
    int n = s.length();
    vector<int>z(n,0);
    int l =0, r = 0;
    for(int i =1;i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(s[z[i]]== s[i+ z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
    for(int i = 0;i<n;i++){
        if(z[i]== m) cout<< i-m-1<<" ";
    }
}
int main(){
    string text, pat;
    cin>>pat>>text;
    z_algo(pat+"$"+ text, pat.length());
}