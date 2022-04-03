#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int maxhistarea(int height[],int n){
    vector<int>left(n),right(n);
    stack<int>s;
    for (int i = 0; i < n; i++)
    {
        if(s.empty())
        { left[i] = 0; s.push(i);}
        else{
            while(!s.empty() && height[s.top()]>=height[i])
                s.pop();
            left[i] = s.empty()?0:s.top()+1;
            s.push(i);
        }
    }
    while(!s.empty())
        s.pop();
    for (int i = n-1; i >=0; i--)
    {
        if(s.empty())
        { right[i] = n-1; s.push(i);}
        else{
            while(!s.empty() && height[s.top()]>=height[i])
                s.pop();
            right[i] = s.empty()?n-1:s.top()-1;
            s.push(i);
        }
    }
    int maxarea =0;
    for (int i = 0; i < n; i++)
    {
        maxarea = max(maxarea,height[i]*(right[i]-left[i]+1));
    }
    
    return maxarea;
}
int maxarearect(int a[100][100],int n){
    int maxarea = maxhistarea(a[0],n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] += a[i-1][j];
        maxarea = max(maxarea,maxhistarea(a[i],n));
    }
    return maxarea;
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<maxarearect(a,n);
}