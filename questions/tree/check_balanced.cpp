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
int checkbalanced(TreeNode* root){
    if(!root) return 0;
    int lh = checkbalanced(root->left);
    int rh = checkbalanced(root->right);
    if(abs(lh-rh)>1) return -1;
    return 1+ max(lh, rh);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    if(checkbalanced(root)== -1)cout<<"not balaced";
    else cout<<"balanced";
}