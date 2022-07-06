//bubble sort is stable, o(n^2)
#include<iostream>
#define N 50
using namespace std;
void bubble_sort(int a[N],int n){
for (int i = 0; i < n-1; i++)
{
    for (int j = i; j < n-i-1; j++)
    {
        if(a[i]>a[i+1])
        swap(a[i],a[i+1]);
    }
    
}
}
//selection sort is not stable,o(n^2)
void selection_sort (int A[N],int n){
        int minimum;        
        for(int i = 0; i < n-1 ; i++)  {
             minimum = i ;
            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {
                minimum = j ;
                }
             }
          swap ( A[ minimum ], A[ i ]) ; 
        }
   }
//selection sort is not stable, o(n^2)
void insertion_sort(int a[N], int n){
for (int i = 0; i < n; i++)
{
    int temp = a[i];
    int j=i;
    while(j>0 && temp<a[j-1]){
        a[j]= a[j-1];
        j= j-1;
    }
    a[j]= temp;
}
}
//merge sort not stable,divide-and-conquer,o(nlogn)
void merge(int a[N], int start,int mid,int end){
int p = start, q = mid+1;
int arr[end-start+1], k=0;
for (int i = start; i <=end ; i++)
{
    if(p>mid)
    arr[k++]= a[q++];
    else if(q>end)
    arr[k++]= a[p++];
    else if(a[p]<a[q])
    arr[k++]= a[p++];
    else
    arr[k++]= a[q++];
}
for(int i=0;i<k;i++)
a[start++]= arr[i];
}
void merge_sort(int a[N], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}

//quick sort is based on divide-and-conquer,o(nlogn),worst case is o(n^2)
int partition(int a[N],int start,int end){
    int pivot = a[start];
    int i = start+1;
    for (int j = start+1; j <= end; j++)
    {
        if(a[j]<pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[start],a[i-1]);
    return i-1;
}
void quick_sort(int a[N],int start, int end){
    if(start<end){
        int pi = partition(a,start, end);
        quick_sort(a, start,pi-1);
        quick_sort(a,pi+1,end);
    }
}

//counting sort t.c = o(n+k) k is for aux[]
void counting_sort(int A[], int Aux[], int sortedA[], int n) {
    int K = 0;
    for(int i=0; i<n; i++)
        K = max(K, A[i]);
    for(int i=0 ; i<=K; i++) 
        Aux[i] = 0;
    for(int i=0; i<n; i++) 
        Aux[A[i]]++;
    int j = 0;
    for(int i=0; i<=K; i++) {
        int tmp = Aux[i];
        while(tmp--) {
            sortedA[j] = i;
            j++;
        }
    }
}
//radix sort o((n+b)*logb(maxx))where b is the base for representing numbers and maxx is the maximum element of the input array. This is clearly visible as we make n+b iterations logbmaxx times (number of digits in the maximum element) . If maxx< n^c,then the complexity can be written as o(n*logb(n)) .
void countsort(int arr[],int n,int place)
{
    int range =10;
        int i,freq[range]={0};         //range for integers is 10 as digits range from 0-9
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}
void radixsort(int arr[],int n,int maxx)            //maxx is the maximum element in the array
{
        int mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}

//heap sort max_heapify has complexity o(logn) , build_maxheap has complexity o(n) and we run max_heapify n times in heap_sort function, therefore complexity of heap_sort function is o(nlogn).
// void heap_sort(int Arr[ ]){
//     int heap_size = N;
//     build_maxheap(Arr);
//     for(int i = N; i >= 2 ; i-- ){
//         swap|(Arr[ 1 ], Arr[ i ]);
//         heap_size = heap_size - 1;
//         max_heapify(Arr, 1, heap_size);
//    }
// }

//bucket sort takes o(n)
// void bucketSort(float[] a,int n)
// {
//     for(each floating integer 'x' in n)
//     {
//         insert x into bucket[n*x]; 
//     }
//     for(each bucket)
//     {
//         sort(bucket);
//     }
// }
int main(){
int n;
cout<<"Enter number of elements to be sorted ";
cin>>n;
int a[N];
cout<<"Enter "<<n<<" elements to be sorted";
for (int i = 0; i < n; i++)
    cin>>a[i];
bubble_sort(a,n);
cout<<"Sorted elements are: ";
for (int i = 0; i < n; i++)
    cout<<a[i]<<" ";
}