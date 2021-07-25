#include<iostream>
#include<set>
using namespace std;
int longestSubsequence(int *a,int n){
    set<int>s;
    int c=1,m=1;
    for (int i = 0; i < n; i++) {s.insert(a[i]);}
    for(auto i:s){
        if(s.find(i+1)!= s.end())
            c++;
        else{
            m = max(m,c);
            c=1;
        }
    }
   return m; 
}
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    cout<<longestSubsequence(a,n);
}