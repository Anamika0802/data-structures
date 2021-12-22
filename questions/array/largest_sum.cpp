#include<iostream>
#include<climits>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
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
    cout<<"Maximum sum:"<<maxSubArraySum(a,n);
}