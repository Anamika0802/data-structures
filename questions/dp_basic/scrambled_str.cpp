#include<bits/stdc++.h>
using namespace std;
int const MAX = 1000;
map<string,bool>dp;
bool isscramble(string s1,string s2){
    if(s1.compare(s2) == 0)return true;
    if(s1.length()<=1 || s2.length()<=1) return false;
    int n = s1.length();
    bool flag = false;
    string temp = s1;
    temp.append(" "+s2);
    if(dp.find(temp)!=dp.end()) return dp[temp];
    for (int i = 1; i < n; i++)
    {
        if( (isscramble(s1.substr(0,i),s2.substr(n-i,i)) && isscramble(s1.substr(i,n-i),s2.substr(0,n-i))) ||
        (isscramble(s1.substr(0,i),s2.substr(0,i)) && isscramble(s1.substr(i,n-i),s2.substr(i,n-i)))){
            flag  = true;
            break;
        }
    }
    return dp[temp] = flag;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    dp.clear();
    if(isscramble(s1,s2))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}