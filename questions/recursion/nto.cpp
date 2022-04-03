#include<iostream>
using namespace std;
//1 to n
void print(int n){
    if(n==1){cout<<n<<endl;return;}
    print(n-1);
    cout<<n<<endl;
}
// n to 1
void printrev(int n){
    if(n==1){cout<<n<<endl;return;}
    cout<<n<<endl;
    printrev(n-1);
}
int main(){
    int n;
    cin>>n;
    print(n);
    printrev(n);
}