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
 class node{
     public:
     int maxNode, minNode, maxSize;
     node(int ma, int mi, int si){
         maxNode = ma;
         minNode = mi;
         maxSize = si;
     }
 };
 node lbshelper(TreeNode* root){
     if(!root) return node(INT_MAX, INT_MIN,0);
     auto left = lbshelper(root->left);
     auto right = lbshelper(root->right);
     if(left.maxNode <root->val and root->val< right.minNode){
         return node(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize +1);
     }
     return node(INT_MIN, INT_MAX,max(left.maxSize, right.maxSize));
 }
 int lbs(TreeNode*root){
     return lbshelper(root).maxSize;
 }
int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout<<lbs(root);
}