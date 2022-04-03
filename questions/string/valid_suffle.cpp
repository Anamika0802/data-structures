#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isValid(string s1,string s2,string res){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(res.begin(),res.end());
    int i=0,j=0,k=0;
    while (k<res.length())
    {
        if(i<s1.length()&& s1[i]==res[k])
            i++;
        else if(j<s2.length()&& s1[j]==res[k])
            j++;
        else
            return false;
        k++;
    }
    return true;
}
int main(){
    string s1,s2,res;
    cin>>s1>>s2>>res;
    cout<<isValid(s1,s2,res);
}