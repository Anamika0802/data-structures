#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
{
            int i=0,j=0,k=0;
            vector<int>common;
            set<int>s;
            while(i<n1&&j<n2&&k<n3){
                if(a[i]==b[j]&& a[i]==c[k]){
                    s.insert(a[i]);
                    i++;j++;k++;
                }
                else if(a[i]<b[j] || a[i]<c[k])
                    i++;
                else if(a[i]>c[k] ||b[j]>c[k])
                    k++;
                else
                    j++;
            }
            for(auto i :s){
                common.push_back(i);
            }
    return common;
}
int main(){
    int n1,n2,n3;
    cout<<"Entet the size of two arrays: ";
    cin>>n1>>n2>>n3;
    int a[n1],b[n2],c[n3];
    cout<<"Enter the elements of the two arrays: ";
    for (int i = 0; i < n1; i++){cin>>a[i];}
    for (int i = 0; i < n2; i++){cin>>b[i];}
    for (int i = 0; i < n3; i++){cin>>c[i];}
    commonElements(a,b,c,n1,n2,n3);
}