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
//  int levelcnt=1;
bool issymmetric(TreeNode* left, TreeNode* right){
    if(!left || !right) return left == right;
    if(left->val != right->val) return false;
    // levelcnt++;
    return issymmetric(left->left, right->right) and issymmetric(left->right, right->left);
}
bool checksymmetry(TreeNode* root){
    return !root || issymmetric(root->left, root->right);
}
int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    if(checksymmetry(root)) cout<<"yes";
    else cout<<"no";
    // cout<<" "<<levelcnt;
}