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
void inorder(TreeNode* root, vector<int>&t){
    if(root== NULL)return;
    inorder(root->left,t);
    t.push_back(root->val);
    inorder(root->right,t);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    TreeNode * roo = new TreeNode(1);
    roo->left = new TreeNode(2);
    // roo->right = new TreeNode(3);
    roo->left->left = new TreeNode(4);
    roo->left->right = new TreeNode(5);
    vector<int>p1;
    vector<int>p2;
    inorder(root,p1);
    inorder(roo,p2);
    if(p1==p2) cout<<"yes";
    else cout<<"no";
}