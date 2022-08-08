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
 int leftsofar = -1, h = 0;
 int height(TreeNode* root){
     if(!root) return -1;
     int l = height(root->left);
     int r = height(root->right);
     h = max(l+r+2,h);
     return 1+ max(l, r);
 }
 void addleft(TreeNode* root,vector<int>& res, int l){
     if(!root) return;
     if(l>leftsofar or isleaf(root)){
         res.push_back(root->val);
         leftsofar = l;
     }
     addleft(root->left,res,l+1);
     addleft(root->right,res, l+1);
 }
 void boundary_special(TreeNode* root){
     vector<int>res;
     if(!root) return ;
    //  height(root);
     addleft(root, res,0);
     addrightboundary(root,res);
     for(int i =0;i<res.size();i++)
        cout<<res[i]<<" ";
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(15);
    root->right->right->left = new TreeNode(18);
    root->right->right->right = new TreeNode(16);
    root->right->right->right->right = new TreeNode(17);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->right->right->right = new TreeNode(13);
    root->left->right->right->right->right = new TreeNode(14);
    root->left->right->right->left = new TreeNode(8);
    root->left->right->right->left->left = new TreeNode(9);
    root->left->right->right->left->left->left = new TreeNode(10);
    root->left->right->right->left->left->right = new TreeNode(11);
    root->left->right->right->left->left->left->left = new TreeNode(12);
    boundary_special(root);
}