#include<iostream>
#include<climits>
#include<unordered_set>
using namespace std;
 
int maxProduct(int *arr, int n) {
	    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct_here = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct_here = max(maxProduct_here, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct_here;
	}
// long long maxProduct(int *arr, int n) {
// 	    long long minVal = arr[0];
//     long long maxVal = arr[0];

//     long long maxProduct_here = arr[0];

//     for (int i = 1; i < n; i++) {

//         // When multiplied by -ve number,
//         // maxVal becomes minVal
//         // and minVal becomes maxVal.
//         if (arr[i] < 0)
//             swap(maxVal, minVal);

//         // maxVal and minVal stores the
//         // product of subarray ending at arr[i].
//         maxVal = arr[i]>maxVal * arr[i]?arr[i]:arr[i]*maxVal;
//         minVal = arr[i]<minVal * arr[i]?arr[i]:arr[i]*minVal;

//         // Max Product of array.
//         maxProduct_here = max(maxProduct_here, maxVal);
//     }

//     // Return maximum product found in array.
//     return maxProduct_here;
// 	}
 
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
    //print(a,n);
    cout<<maxProduct(a,n);
}