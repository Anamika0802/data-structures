#include<bits/stdc++.h>
using namespace std;
bool ispali(string s,int i, int j){
    while(i<j){
        if(s[i]!= s[j])
            return false;
        i++;j--;
    }
    return true;
}
int pali_part(string s,int i, int j){
    if(i>=j)return 0;
    if(ispali(s,i,j)) return 0;
    int mi = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int ans = pali_part(s,i,k)+pali_part(s,k+1,j)+ 1;
        mi = min(mi,ans);
    }
    return mi;
}
int main(){
    string s;
    cin>>s;
    cout<<pali_part(s,0,s.length()-1);
}