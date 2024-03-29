#include<bits/stdc++.h>
using namespace std;
class medianFinder(){
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    void addNum(int num){
        int lsize= max_heap.size();
        int rsize = min_heap.size();
        if(lsize==0) //max_heap have no element
            max_heap.push(num);
        //both have same size
        else if(lsize== rsize){
            if(num<min_heap.top())
                max_heap.push(num);
            else{
                int temp = min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                max_heap.push(temp);
            }
        }
        //max_heap size = min_heap size +1
        else
        {
            if (rsize==0)
            {
                if(num>max_heap.top())
                    min_heap.push(num);
                else{
                    int temp = max_heap.top();
                    max_heap.pop();
                    max_heap.push(num);
                    min_heap.push(temp);
                }
            }
            else if (num>min_heap.top())
                min_heap.push(num);
            else
            {
               if(num<max_heap.top()){
                   int temp = max_heap.top();
                   max_heap.pop();
                   max_heap.push(num);
                   min_heap.push(temp);
               }
               else
                    min_heap.push(num);
            }
            
        }
        
    }

    double find_median(){
        int lsize= max_heap.size();
        int rsize = min_heap.size();
        if(lsize>rsize)
            return double(max_heap.top());
        else
            return (double(max_heap.top())+double(min_heap.top()))/2;
    }
}
int main(){
    //read data from the stream
}