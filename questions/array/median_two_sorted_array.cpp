#include<iostream>
using namespace std;
int median(int *ar1,int*ar2,int n,int m){
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    //index is median i.e. (m+n)/2
    if((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
     
    // median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    else
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            m2 = m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2)/2;
    }
}
int main(){
    int n,m;
    cout<<"Enter the size of the two arrays: ";
    cin>>n>>m;
    int a[n],b[m];
    //vector<int>a;
    cout<<"Enter the elements of the two arrays: ";
    for (int i = 0; i < n; i++){a[i]};
    for (int i = 0; i < m; i++){b[i]};
    cout<<"Median :"<<median(a,b,n,m);
}