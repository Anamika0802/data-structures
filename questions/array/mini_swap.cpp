#include<iostream>
using namespace std;
int minSwap(int *arr, int n, int k) {
    int j,sw=0,prev;
    int count = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] <= k)
			++count;
	int bad = 0;
	for (int i = 0; i < count; ++i)
		if (arr[i] > k)
			++bad;
	int ans = bad;
	for (int i = 0, j = count; j < n; ++i, ++j) {
		
		// Decrement count of previous window
		if (arr[i] > k)
			--bad;
		
		// Increment count of current window
		if (arr[j] > k)
			++bad;
		
		// Update ans if count of 'bad'
		// is less in current window
		ans = min(ans, bad);
	}
	return ans;
}

int main(){
    int n,k;
    cout<<"Entet the size of array and k: ";
    cin>>n>>k;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++){cin>>a[i];}
    cout<<"Minimum swap :"<<minSwap(a,n,k);
}