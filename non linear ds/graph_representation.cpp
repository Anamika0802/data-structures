// its a program for the linked and the matrix representaion of a graph
//graph can be of any kind i.e. weighted, unweighted, directed, undirected.
#include<iostream>
#include<vector>
#include<map>
using namespace std;
void linkedRepresentation(map<char,vector<char>> *graph){
for(auto x:*graph){
        cout<<x.first<<" [";
        for(auto y : x.second)cout<<y<<" ";
        cout<<"]"<<endl;
    }
}
void matrixRepresentation( vector<vector<int>> *matrix){
    int r,c;
    r = c = matrix->size();
    for(auto x:*matrix){
        for(auto y :x){
            cout<< y<<" ";
        }
        cout<<endl;
    }
}
int main(){
    map<char,vector<char>>graph;
    int v,e;
    cout<<"Enter the vetex and number of edeges ";
    cin>>v>>e;
    vector<vector<int>>matrix(v,vector<int>(v,0));
    cout<<"Enter data for undirected graph ";
    for (int  i = 0; i < e; i++)
    {
        char u,v;
        cin>>u>>v;
        graph[u].push_back(v);//for directed use only single statement
        graph[v].push_back(u);
    }
     cout<<"Enter data for directed weighted graph ";
    for (int  i = 0; i < e; i++)
    {
        char u,v;
        int w;
        cin>>u>>v>>w;
        matrix[(int)u-97][(int)v- 97]= w; //weight for the edge
        //matrix[v][u] = w //for undirected weighted graph
    }
    linkedRepresentation(&graph);
    matrixRepresentation(&matrix);
}