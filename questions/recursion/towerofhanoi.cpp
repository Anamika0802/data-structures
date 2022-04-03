#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,string t,string d,string h){
    if(n==1){
    cout<<"Moving plate "<<n<<" from "<<t<<" to "<<d<<endl;
    return;
    }
    towerOfHanoi(n-1,t,h,d);
    cout<<"Moving plate "<<n<<" from "<<t<<" to "<<d<<endl;
    towerOfHanoi(n-1,h,d,t);
    
}
int main(){
    int n;
    cin>>n;
    towerOfHanoi(n,"tower","destination","helper");
}