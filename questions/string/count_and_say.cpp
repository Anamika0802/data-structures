#include<iostream>
#include<string>
using namespace std;
string say(string s){
        //cout<<s<<" : ";
        int c=1;
        char prev = s[0];
        string temp;
        for(int i=1;i<s.length();i++){
            if(s[i]==prev)
                c++;
            else{
                
                temp += to_string(c)+prev;
                c=1;
                prev = s[i];
            }
        }
        //cout<<temp+to_string(c)+prev<<endl;
        return temp+to_string(c)+prev;
    }
string countAndSay(int n) {
        string res ="1";
        if(n==1)
            return "1";
        for(int i=1;i<n;i++){
            res = say(res);
        }
        return res;
    }
    
    int main(){
        int n;
        cin>>n;
        cout<<countAndSay(n);
    }