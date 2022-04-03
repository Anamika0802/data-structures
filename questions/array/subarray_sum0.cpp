#include<iostream>
#include<unordered_set>
using namespace std;
 
bool sum_0(int arr[], int size)
{
    int sum=0;//sum= k
    unordered_set<int>sumSet;
 
    for (int i = 0; i < size; i++)
    {
       sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0
            || sumSet.find(sum)
            != sumSet.end())
            return true;
 
        sumSet.insert(sum);

    }
    return false;
}
 
void print(int *a,int n){
    for (int i = 0; i < n; i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    print(a,n);
    cout<<sum_0(a,n);
}