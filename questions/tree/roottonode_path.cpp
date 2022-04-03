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
bool path(TreeNode* root, int data, vector<int>&res){
    if(root== NULL)return false;
    res.push_back(root->val);
    if(root->val== data)return true;
    if(path(root->left,data,res) || path(root->right,data, res))return true;
    res.pop_back();
    return false;
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int>res;
    path(root, 5, res);
    for(auto i:res)cout<<i<<" ";
}