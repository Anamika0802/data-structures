/* Using the given expression of the parenthesis to find out weather the expression is balced or not acoording to the opening and closing of parenthesis */
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//Function to check weather the character opening or closing are of same type
bool pairs(char o,char c){
    if(o=='(' && c==')')return true;
    else if(o=='{' && c=='}')return true;
    else if(o=='[' && c==']')return true;
    return false;
}
bool balanced(string ex){
    stack<char> s;
    for (int i = 0; i < ex.length(); i++)
    {
        if(ex[i]=='(' || ex[i]=='{' || ex[i]=='[')
        s.push(ex[i]);
        else if(ex[i]==')' ||ex[i]=='}' || ex[i]==']'){
            if(s.empty() || !pairs(s.top(),ex[i]))
            return false;
            else 
            s.pop();
        }
    }
    return s.empty() ? true:false;
}
int main(){
  string ex;
  cout<<"Enter An Expression";
  cin>>ex;
  if(balanced(ex))
  cout<<"Balanced";
  else
  cout<<"Not Balanced";  
}