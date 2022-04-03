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
 void inorder(TreeNode* root){
     if(!root) return;
     inorder(root->left);
     cout<<root->val<<" ";
     inorder(root->right);
 }
 TreeNode* build(vector<int>&pre, int &i, int bound){
     if(i==pre.size()|| pre[i]>bound)return NULL;
     TreeNode* root = new TreeNode(pre[i++]);
     root->left = build(pre, i, root->val);
     root->right = build(pre, i, bound);
     return root;
 }
 int main(){
    vector<int>pre = {4,2,1,3,5};
    int i=0;
    TreeNode* root = build(pre,i,INT_MAX);
    inorder(root);
}