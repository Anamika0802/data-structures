#include<iostream>
using namespace std;
int split_count(string s){
    int n = s.length();
    int c=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0')
            c++;
        else
            c--;
        if(c==0){
            ans++;
        }  
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<split_count(s);
}