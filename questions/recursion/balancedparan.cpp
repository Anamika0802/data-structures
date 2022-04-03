#include<bits/stdc++.h>
using namespace std;
void genpar(int o,int c,string s, vector<string> &v){
    if(o==0 && c==0){
        v.push_back(s);
        return;
    }
    if(o>0){
        string out =s;
        out.push_back('(');
        genpar(o-1,c,out,v);       
    }
    if(c>o){
        string out = s;
        out.push_back(')');
        genpar(o,c-1,out,v);
    }
}
int main(){
    int o,c;
    cin>>o>>c;
    o--;
    vector<string>op;
    genpar(o,c,"(",op);
    for(auto s:op)
        cout<<s<<endl;
}