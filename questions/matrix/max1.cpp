#include<iostream>
#include<vector>
using namespace std;
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ma =0,ans=-1;
	    for(int i=0;i<n;i++){
	        int a = count(arr[i].begin(),arr[i].end(),1);
	        if(ma<a){
	            ma = a;
	            ans =i;
	        }
	    }
	    return ans;
}
        
int main(){
    int r,c;
    vector<vector<int>>a;
    cin>>r>>c;
    for (int i = 0; i < r; i++)
    {
        vector<int>rows;
        for (int j = 0; j < c; j++)
        {
            int el;
            cin>>el;
            rows.push_back(el);
        }
        a.push_back(rows);
    }
   cout<<rowWithMax1s(a,r,c);
}