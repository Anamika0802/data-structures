#include<bits/stdc++.h>
using namespace std;
//same for case change,and letter case ex:a1b2..
void permu_space(string in,string op){
    if(in.size()==0){
        cout<<op<<endl;
        return ;
    }
    string op1,op2;
    op1 = op2 = op;
    op2.push_back(' ');
    op2.push_back(in[0]);
    op1.push_back(in[0]);
    in = in.substr(1);
    permu_space(in,op1);
    permu_space(in,op2);
}
int main(){
    string s;
    cin>>s;
    string op;
    op.push_back(s[0]);
    permu_space(s.substr(1),op);
}