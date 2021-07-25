#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
vector<char> bfs(map<char,vector<char>> graph,char s,char d){
vector<char> path;
map<char,bool>visited;
queue<char>queue;
path.push_back(s);
queue.push(s);
visited[s]= true;
int c=0;
while (queue.size()!=0)
{
      char tmpnode =queue.front();
    queue.pop();
    auto x = graph.at(tmpnode);
    for(auto neighbour : x){
        if(visited[neighbour]== false){
            path.push_back(neighbour);
            if(neighbour == d){
                c=1;
                return path;
            }
            queue.push(neighbour);
            visited[neighbour] = true;
        }
    }
}
if(c==0){
    path.clear();
}
    return path;
}
//by recursion dfs
// vector<char> dfs(map<char,vector<char>> graph,char s,char d,map<char,bool> &visited,vector<char> *path){
// path->push_back(s);
// visited[s]=true;
// auto x = graph.at(s);
//     for(auto neighbour : x){
//         if(visited[neighbour]== false){
//              dfs(graph,neighbour,d,visited,path);
//         }
//     }
//     return *path;
// }
vector<char> dfs(map<char,vector<char>> &graph,char s,char d){
map<char,bool>visited;
vector<char> path;
stack<char>stack;
stack.push(s);
auto x = graph.at(s);
while(!stack.empty()){
char tmpnode =stack.top();
stack.pop();
if(visited[tmpnode]== false){
path.push_back(tmpnode);
if(tmpnode == d)return path;
visited[tmpnode]= true;}
for(auto neighbour : x){
    if(visited[neighbour]== false)
            stack.push(neighbour);
}
x = graph.at(stack.top());
}
cout<<"hi";
path.clear();
return path;
}
int main(){
    map<char,vector<char>>graph;
    int v,e;
    cout<<"Enter the vetex and number of edeges ";
    cin>>v>>e;
    cout<<"Enter data for undirected graph ";
    for (int  i = 0; i < e; i++)
    {
        char u,v;
        cin>>u>>v;
        graph[u].push_back(v);//for directed use only single statement
        graph[v].push_back(u);
    }
    char s,d;
    cout<<"Enter source and destination ";
    cin>>s>>d;
    // vector<char>traversed_path =bfs(graph,s,d);
    // cout<<"Path to be traversed is ";
    // for(auto x : traversed_path){
    //     cout<<x<<" ";
    // }
    map<char,bool>visited;
    vector<char> path;
    //vector<char>traversed_path =dfs(graph,s,d,visited,path);
    vector<char>traversed_path =dfs(graph,s,d);
    for(auto x : traversed_path){
        cout<<x<<" ";
    }
}