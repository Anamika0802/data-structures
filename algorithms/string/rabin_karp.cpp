#include<bits/stdc++.h>
using namespace std;
void rabinKarp(string text, string pat){
    int m = text.length(), n = pat.length();
    int p=0,t=0,d = 256,q = 101,h = 1;
    for(int i =0;i<n-1;i++)
        h = (h*d)%q;// h = (d^(n-1))%q
    for(int i=0;i<n;i++){
        p = (p*d + int(pat[i]))%q;
        t = (t*d +int(text[i]))%q;
    }
    for(int i =0;i<= m-n;i++){
        if(p==t){
            int j ;
            for( j =0;j<n;j++){
                if(pat[j]!=text[i+j])
                    break;
            }
            if(j==n)cout<<"found "<<i<<" ";
        }
        if(i<m-n){
            t = (d*(t- int(text[i])*h) + int(text[i+n]))%q;
            if(t<0) t = t+q;
        }
    }
}
int main(){
    string text, pat;
    cin>>text>>pat;
    rabinKarp(text,pat);
}