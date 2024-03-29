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
    if(root== NULL)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void preorder(TreeNode* root){
    if(root== NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root){
    if(root== NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
}