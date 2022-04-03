#include<bits/stdc++.h>
using namespace std;
void genno(int n,vector<string>&v,string op,int o,int z){
    if(n==0){
        v.push_back(op);
        return ;
    }
    if(o>z){
        string out = op;
        out.push_back('0');
        genno(n-1,v,out,o,z+1);
    }
    string ot = op;
    ot.push_back('1');
    genno(n-1,v,ot,o+1,z);
}
int main(){
    int n;
    cin>>n;
    vector<string>v;
    genno(n,v,"",0,0);
    for(auto i:v)
        cout<<i<<endl;
}