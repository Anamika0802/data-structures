#include<iostream>
using namespace std;
string longestPalin (string str) {
    int maxLength = 1;
    int start = 0;
    int len = str.length();
    int low, high;
    for (int i = 1; i < len; ++i) {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    string res;
    for (int i = start; i < start + maxLength; ++i)
        res+= str[i];

    return res;
    }
int main(){
    string s;
    cin>>s;
    cout<<longestPalin(s);
}