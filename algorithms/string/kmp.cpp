#include<iostream>
using namespace std;
void lpsarray(string pat, int *lps,int m){
    int len=0;
    lps[0]=0;
    int i=1;
    while (i<m)
    {
        if( pat[i]== pat[len]){
            len++;
            lps[i]= len;
            i++;
        }
        else
        {
            if(len!=0)
                len = lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
        
    }
    
}
bool search(string pat, string txt){
int n= txt.length();
int m = pat.length();
int lps[50];//[m];  
lpsarray(pat, lps,m);
int i=0,j=0;
while (i<n)
{
    if(pat[j]==txt[i]){
        j++;
        i++;
    }
    if (j==m)
    return true;
    else if (i<n && pat[j]!=txt[i])
    {
        if (j!=0)
            j= lps[j-1];
        else
            i++;
    }
    
}
return false;
}
int main(){
    string pat, txt;
    cin>>pat>>txt;
    if(search(pat,txt))cout<< pat<<" exits in text "<<txt;
    else cout<< pat<<"does not exits in text "<<txt;
}

// void createLps(vector<int>&lps, string p){
//     int n = lps.size();
//     int i =1, j =0;
//     while(i<n){
//         if(p[i]==p[j]){
//             lps[i] = j+1;
//             i++;j++;
//         }
//         else{
//             if(j!=0)
//                 j = lps[j-1];
//             else
//             {
//                 lps[i] = 0;
//                 i++;
//             }
            
//         }
//     }
// }
// bool kmp(string s, string p){
//     int m = s.length();
//     int n = p.length();
//     vector<int>lps(n,0);
//     createLps(lps,p);
//     int i =0, j= 0;
//     while(i<m and j<n){
//         if(s[i]==p[j]){
//             i++;j++;
//         }
//         if(j==n) return true;
//         else if(i<m and s[i]!=p[j]){
//             if(j!=0){
//                 j = lps[j-1];
//             }
//             else{
//                 j =0; //j is already 0 its just for the intution
//                 i++;
//             }
//         }
//     }
//     return false;
// }