#include<iostream>
#include<unordered_map>
using namespace std;
void count_pairs(int *arr,int n,int sum){
unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;

    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
    cout<< twice_count / 2;
}
int main(){
    int n,s;
    cout<<"Enter the size of array and sum: ";
    cin>>n>>s;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    count_pairs(a,n,s);
}