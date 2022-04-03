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
 int leftheight(TreeNode* root){
     int h =0;
     while (root)
     {
         h++;
         root =root->left;
     }
     return h;
 }
 int rightheight(TreeNode* root){
     int h =0;
     while (root)
     {
         h++;
         root =root->right;
     }
     return h;
 }
int countnodes(TreeNode* root){
    if(!root)return 0;
    int lh = leftheight(root);
    int rh = rightheight(root);
    if(lh == rh) return (1<<lh )-1;
    return 1+ countnodes(root->left)+ countnodes(root->right);
}

 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<countnodes(root);
}