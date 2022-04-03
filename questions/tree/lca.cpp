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
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root== NULL || p== root || q== root)return root;
    TreeNode* left = lca(root->left,p,q);
    TreeNode* right = lca(root->right,p,q);
    if(!left) return right;
    else if(!right) return left;
    else return root;
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int>res;
    TreeNode* ans =lca(root,root->left->left , root->left->right);
    cout<<ans->val;
}