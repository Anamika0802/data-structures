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
 bool isleaf(TreeNode* root){
     return (!root->left and !root->right);
 }
 void addleftboundary(TreeNode* curr, vector<int>&res){
     TreeNode* root = curr->left;
     while(root)
     {
        if(!isleaf(root))res.push_back(root->val);
        if(root->left)root =root->left;
        else root = root->right;
     }
 }
 void addleaves(TreeNode* root, vector<int>&res){
     if(isleaf(root)){
         res.push_back(root->val);
         return;
     }
     if(root->left) addleaves(root->left,res);
     if(root->right) addleaves(root->right,res);
 }
 void addrightboundary(TreeNode* curr, vector<int>&res){
     TreeNode* root = curr->right;
     vector<int>temp;
     while(root)
     {
        if(!isleaf(root))temp.push_back(root->val);
        if(root->right)root =root->right;
        else root = root->left;
     }
     for(int i = temp.size()-1;i>=0;i--)
        res.push_back(temp[i]);
 }
 void boundary(TreeNode* root){
     vector<int>res;
     if(!root)return ;
     if(!isleaf(root)) res.push_back(root->val);
     addleftboundary(root,res);
     addleaves(root,res);
     addrightboundary(root,res);
     for(auto i:res)cout<<i<<" ";
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    boundary(root);
}