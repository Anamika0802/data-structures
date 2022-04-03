#include<iostream>
using namespace std;
//recursion
int decode(int i,string s){
    int n = s.length();
    if(i==n)
        return 1;
    if(s[i]=='0')
        return 0;
    int res =0;
    res= decode(i+1,s);
    if(i<=n-2 &&(s[i]=='1'||s[i]=='2'&&s[i+1]<='6'))
        res+= decode(i+2,s);
    return res;
}
//bottom up
// int decode(string s){
//     int n = s.length();
//     int* dp = new int[n+1]();
//     if(s[0]-'0'!=0){
//         dp[0]=1;
//         dp[1]=1;}
//     for (int i = 2; i <=n; i++)
//     {
//         if(s[i-1]-'0'!=0)
//             dp[i]= dp[i-1];
//         if(((s[i-2]-'0')*10 +(s[i-1]-'0')<=26) && ((s[i-2]-'0')*10 +(s[i-1]-'0')>=10))
//             dp[i]+=dp[i-2];
//     }
//     return dp[n];
// }
int main(){
    string s;
    cin>>s;
    cout<<decode(0,s);
    // cout<<decode(s);
}