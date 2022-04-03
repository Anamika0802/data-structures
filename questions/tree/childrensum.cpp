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
void changetree(TreeNode* root){
    if(!root) return;
    int child =0;
    if(root->left)
        child+=root->left->val;
    if(root->right)
        child+=root->right->val;
    if(child >= root->val) root->val = child;
    else{
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }
    changetree(root->left);
    changetree(root->right);
    int tot=0;
    if(root->left) tot+=root->left->val;
    if(root->right) tot+= root->right->val;
    if(root->left or root->right) root->val = tot;
}
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    changetree(root);
}