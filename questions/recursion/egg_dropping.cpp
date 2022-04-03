#include<bits/stdc++.h>
using namespace std;
int attempts(int f,int e){
    if(e==1) return f;
    if(f<=1) return f;
    int mi= INT_MAX;
    for (int i = 1; i <= f; i++)
    {
        int ans = 1+max(attempts(f-i,e) , attempts(i-1,e-1));
        mi = min(mi, ans);
    }
    return mi;
}
int main(){
    int f,e;
    cin>>f>>e;
    cout<<attempts(f,e);
}