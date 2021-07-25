#include <bits/stdc++.h>
#include <string>
using namespace std;
//  void permute(string a, int l, int r)
// {
//     // Base case
//     if (l == r)
//         cout<<a<<endl;
//     else
//     {
//         // Permutations made
//         for (int i = l; i <= r; i++)
//         {
 
//             // Swapping done
//             swap(a[l], a[i]);
 
//             // Recursion called
//             permute(a, l+1, r);
 
//             //backtrack
//             swap(a[l], a[i]);
//         }
//     }
// }
void permute(string s , string answer)
{
    if(s.length() == 0)
    {
        cout<<answer<<"  ";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch);
    }
 
}
 
int main()
{
    string s;
    string answer="";
 
    cout<<"Enter the string : ";
    cin>>s;
 
    cout<<"\nAll possible strings are : ";
    permute(s , answer);
    return 0;
}