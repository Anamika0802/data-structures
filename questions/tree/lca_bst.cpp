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
     if(!root) return NULL;
     int curr = root->val;
     if(curr<p->val && curr<q->val)
        return lca(root->right, p,q);
     if(curr>p->val && curr>q->val) 
        return lca(root->left,p,q);
     return root;
 }
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode* ans= lca(root,root->left->left ,root->left->right);
    cout<<ans->val;
}