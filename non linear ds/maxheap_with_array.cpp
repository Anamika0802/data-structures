#include<iostream>
using namespace std;
static int MAX_SIZE=10;
#define print(a) for(int i=0;i<MAX_SIZE;i++)cout<<a[i]<<" ";
//time =O(long(N))
void max_heapify(int a[],int i){
    int l = 2*i+1,r= 2*i+2,largest=i;
    if((l<MAX_SIZE) && (a[l]>a[i]))
        largest = l;
    if((r<MAX_SIZE) && (a[r]>a[largest]))
        largest = r;
    if(largest !=i){
        swap(a[i],a[largest]);
        max_heapify(a,largest);
    }
}
//time =O(N)
void build_heap(int *a){for(int i=MAX_SIZE/2-1;i>=0;i--)max_heapify(a,i);}
//time = O(log(N)),space = O(log(N)) or POP
int heap_extract_max(int *a){
    if(MAX_SIZE<1)cout<<"Underflow";
    int max = a[0];
    a[0] = a[MAX_SIZE -1];
    MAX_SIZE-=1;
    max_heapify(a,0);
    return max;
}
//time = O(Nlog(N)),space = O(log(N))
void heapSort(int *a){
    build_heap(a);
    //print(a);
    int max = MAX_SIZE;
    for(int i=MAX_SIZE-1;i>0;i--){
        //cout<<a[i]<<" ";
        swap(a[0],a[i]);
        MAX_SIZE--;
        max_heapify(a,0);
    }
    MAX_SIZE = max;
}
// time = O(log(N)),space = O(1)
void heap_increase_key(int *a,int i,int key){
    if(key<a[i])cout<<"Invalid Action";
    a[i]= key;
    //percolate up
    while (i>0 && a[i/2]<a[i])
    {
        swap(a[i],a[i/2]);
        i= i/2;
    }
}
//time = O(log(N)),space = O(log(N))
void heap_decrease_key(int *a,int i,int key){
    if(key>a[i])cout<<"Invalid Action";
    a[i]= key;
    //percolate down
    max_heapify(a,i);
}
//time = O(log(N)),space = O(1) or PUSH 
void heap_insert_key(int *a,int val){
    MAX_SIZE+=1;
    a[MAX_SIZE-1] = val;
    int i = MAX_SIZE -1;
    //percolate up
    while (i>0 && a[i/2]<a[i])//i/2 is the index of the parent node
    {
        swap(a[i],a[i/2]);
        i= i/2;
    }
}
int main(){
    int a[10];
    //cin>>n;
    for(int i=0;i<MAX_SIZE;i++)cin>>a[i];
    //build_heap(a);
    heapSort(a);
    print(a);
    cout<<endl;

    // heap_decrease_key(a,1,3);
    // heapSort(a);
    // print(a);
    // cout<<endl;
    // heap_increase_key(a,9,46);
    // heapSort(a);
    // print(a);
    // cout<<endl;
    // heap_insert_key(a,11);
    // heapSort(a);
    // print(a);
    // cout<<endl;
    // cout<<heap_extract_max(a)<<endl;
    // print(a);
    // cout<<endl;

}