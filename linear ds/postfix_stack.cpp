#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isoperand(char i){
    if(i>='0' && i<='9') return true;
    return false;
}
bool isoperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')return true;
    return false;
}
int performOperation(char operation,int op1, int op2){
    if(operation == '+') return op1+op2;
    else if(operation == '-') return op1-op2;
    else if(operation == '*') return op1*op2;
    else if(operation == '/') return op1/op2;
    else if(operation == '^') return op1^op2;
    else cout<<"Unexpected Error!\n";
    return -1;
}
int evaluate(string ex){
    stack<int> s;
    for (int i = 0; i < ex.length(); i++)
    {
       if (isoperator(ex[i]))
       {
           int op2= s.top(); s.pop();
           int op1 = s.top(); s.pop();
           int result = performOperation(ex[i],op1,op2);
           s.push(result);
       }
       else if(isoperand(ex[i])){
           int op = 0;
           while (i<ex.length() && isoperand(ex[i]))
           {
               op = (op*10) +(ex[i]-'0');
               i++;
           }
           i--;
           s.push(op);
       }
    }
    return s.top();    
}
int main(){
    string ex;
    cout<<"Enter Experation";
    getline(cin,ex);
    int result = evaluate(ex);
    cout<<result;
}