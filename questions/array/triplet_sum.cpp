#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
bool find3Numbers(int A[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size - 2; i++) 
    {
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                cout<<endl;
                return true;
            }
            s.insert(A[j]);
        }
    }
    return false;
}
// bool find3Numbers(int A[], int arr_size, int sum){
// int l, r;
//     sort(A, A + arr_size);
//     for (int i = 0; i < arr_size - 2; i++) {

//         l = i + 1; // index of the first element in the
//         r = arr_size - 1; // index of the last element
//         while (l < r) {
//             if (A[i] + A[l] + A[r] == sum) {
//                 printf("Triplet is %d, %d, %d", A[i],
//                        A[l], A[r]);
//                 return true;
//             }
//             else if (A[i] + A[l] + A[r] < sum)
//                 l++;
//             else // A[i] + A[l] + A[r] > sum
//                 r--;
//         }
//     }
//     return false;
// }
int main(){
    int n,s;
    cout<<"Entet the size of array and sum: ";
    cin>>n>>s;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    //print(a,n);
    cout<<find3Numbers(a,n,s);
}