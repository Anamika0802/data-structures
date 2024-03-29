#include<iostream>
using namespace std;
int trappingWater(int arr[], int n){
    int result = 0;
    int left_max = 0, right_max = 0;
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                left_max = arr[lo];
            else
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}
// int findWater(int arr[], int n)
// {
//     // left[i] contains height of tallest bar to the
//     // left of i'th bar including itself
//     int left[n];

//     // Right [i] contains height of tallest bar to
//     // the right of ith bar including itself
//     int right[n];

//     // Initialize result
//     int water = 0;

//     // Fill left array
//     left[0] = arr[0];
//     for (int i = 1; i < n; i++)
//         left[i] = max(left[i - 1], arr[i]);

//     // Fill right array
//     right[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//         right[i] = max(right[i + 1], arr[i]);

//     // Calculate the accumulated water element by element
//     // consider the amount of water on i'th bar, the
//     // amount of water accumulated on this particular
//     // bar will be equal to min(left[i], right[i]) - arr[i] .
//     for (int i = 0; i < n; i++)
//         water += min(left[i], right[i]) - arr[i];

//     return water;
// }
int main(){
    int n;
    cout<<"Entet the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    cout<<trappingWater(a,n);
}