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
 void levelorder(TreeNode* root){
     if(!root)return;
     map<int,int>m;
     queue<pair<TreeNode*, int>>q;
     q.push({root,0});
     while (!q.empty())
     {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node =  q.front().first;
            int line = q.front().second;
            q.pop();
            m[line] = node->val;
            if(node->left)
                q.push({node->left,line-1});
            if(node->right)
                q.push({node->right,line+1});
        }
     }
    for(auto i:m){
        cout<<i.second<<" ";
    } 
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    levelorder(root);
}