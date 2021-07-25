#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
int main(){
    vector<char>a;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin>>c;
        a.push_back(c);
    }
    reverseString(a);
}