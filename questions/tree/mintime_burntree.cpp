#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
void markparent(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &parent){
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
void burntime(TreeNode* root,TreeNode* target, int k){
    unordered_map<TreeNode* , TreeNode*> parent;
    markparent(root,parent);
    unordered_map<TreeNode* , bool>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target] = true;
    int time =0;
    while (!q.empty())
    {
        int size = q.size();
        bool change = false;
        for (int i = 0; i < size; i++)
        {
             TreeNode* curr = q.front();
             q.pop();
             if(curr->left and !visited[curr->left]){
                 visited[curr->left] = true;
                 q.push(curr->left);
                 change = true;
             }
             if(curr->right and !visited[curr->right]){
                 visited[curr->right] = true;
                 q.push(curr->right);
                 change = true;
             }
             if(parent[curr] and !visited[parent[curr]]){
                 visited[parent[curr]] = true;
                 q.push(parent[curr]);
                 change = true;
             }
        }
        if(change)time++;
    }
    cout<<time;
}
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    burntime(root,root->left,1);
}