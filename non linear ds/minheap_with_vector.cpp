#include<iostream>
#include<vector>
using namespace std;
static int MAX_SIZE=10;
#define print(a) for(int i=0;i<MAX_SIZE;i++)cout<<a[i]<<" ";
//time =O(long(N))
void min_heapify(vector<int>&a,int i){
    int l = 2*i+1,r= 2*i+2,smallest=i;
    if((l<MAX_SIZE) && (a[l]<a[i]))
        smallest = l;
    if((r<MAX_SIZE) && (a[r]<a[smallest]))
        smallest = r;
    if(smallest !=i){
        swap(a[i],a[smallest]);
        min_heapify(a,smallest);
    }
}
//time =O(N)
void build_heap(vector<int>&a){for(int i=MAX_SIZE/2-1;i>=0;i--)min_heapify(a,i);}
//time = O(log(N)),space = O(log(N)) or POP
int heap_extract_min(vector<int>a){
    if(MAX_SIZE<1)cout<<"Underflow";
    int max = a[0];
    a[0] = a[MAX_SIZE -1];
    MAX_SIZE-=1;
    min_heapify(a,0);
    return max;
}
//time = O(Nlog(N)),space = O(log(N))
void heapSort(vector<int>&a){
    build_heap(a);
    //print(a);
    int max = MAX_SIZE;
    for(int i=MAX_SIZE-1;i>0;i--){
        //cout<<a[i]<<" ";
        swap(a[0],a[i]);
        MAX_SIZE--;
        min_heapify(a,0);
    }
    MAX_SIZE = max;
}
// time = O(log(N)),space = O(1)
void heap_increase_key(vector<int>&a,int i,int key){
    if(key<a[i])cout<<"Invalid Action";
    a[i]= key;
    //percolate down
    min_heapify(a,i);
    
}
//time = O(log(N)),space = O(log(N))
void heap_decrease_key(vector<int>&a,int i,int key){
    if(key>a[i])cout<<"Invalid Action";
    a[i]= key;
    //percolate up
    while (i>0 && a[i/2]<a[i])
    {
        swap(a[i],a[i/2]);
        i= i/2;
    }
}
// time = O(log(N)),space = O(1) or PUSH 
void heap_insert_key(vector<int>&a,int val){
    a[MAX_SIZE] = val;
    MAX_SIZE+=1;
    int i = MAX_SIZE -1;
    //percolate up
    while (i>0 && a[i/2]<a[i])//i/2 is the index of the parent node
    {
        swap(a[i],a[i/2]);
        i= i/2;
    }
}
int main(){
    vector<int>a(1001);
    //cin>>n;
    for(int i=0;i<MAX_SIZE;i++)cin>>a[i];
    build_heap(a);
    // heapSort(a);
    // print(a);
    // heap_increase_key(a,8,46);
    // heapSort(a);
    print(a);
}