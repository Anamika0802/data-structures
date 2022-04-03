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
 void solve(TreeNode* root, int level, vector<int>&res){
     if(!root)return;
     if(res.size()== level)res.push_back(root->val);
     if(root->left) solve(root->left,level+1, res);
     if(root->right) solve(root->right,level+1, res);
 }
 void leftview(TreeNode* root){
    vector<int>res;
    solve(root,0,res);
    for(auto i:res)cout<<i<<" ";
 }
 void solve1(TreeNode* root, int level, vector<int>&res){
     if(!root)return;
     if(res.size()== level)res.push_back(root->val);
     if(root->right) solve1(root->right,level+1, res);
     if(root->left) solve1(root->left,level+1, res);
 }
 void rightview(TreeNode* root){
    vector<int>res;
    solve1(root,0,res);
    for(auto i:res)cout<<i<<" ";
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    rightview(root);
    cout<<endl;
    leftview(root);
}