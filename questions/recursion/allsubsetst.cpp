#include<bits/stdc++.h>
using namespace std;
// power set, subset,subsequences 
// for unique use set
void subset(string in,string op){
    if(in.size()==0){
        cout<<op<<endl;
        return;
    }
    string op1,op2;
    op1= op2 = op;
    op2.push_back(in[0]);
    in = in.substr(1);
    subset(in,op1);
    subset(in,op2);
}
int main(){
    string s;
    cin>>s;
    string op="";
    subset(s,op);
}