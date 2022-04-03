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
 bool isvalid(TreeNode* root,int minval, int maxval){
     if(!root)return true;
     if(root->val>=maxval || root->val<= minval) return false;
     return isvalid(root->left,minval,root->val) and isvalid(root->right, root->val, maxval);
 }
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout<<isvalid(root, INT_MIN,INT_MAX);
}