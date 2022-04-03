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
 void print(TreeNode*root){
     if(!root)return ;
     print(root->left);
     cout<<root->val<<" ";
     print(root->right);
 }
TreeNode* buildtree(vector<int>&pre, int pres, int pree,int ins, int ine,map<int, int>&m){
    if(pres>pree|| ins>ine) return NULL;
    TreeNode* root = new TreeNode(pre[pres]);
    int i = m[root->val];
    int numl = i - ins;
    root->left = buildtree(pre,pres+1,pres+numl,ins,ins+numl,m);
    root->right = buildtree(pre,pres+numl+1,pree,ins+numl+1,ine,m);
    return root;
}
TreeNode* construct(vector<int>&pre, vector<int>&in){
    map<int, int>m;
    int n = in.size();
    for (int i = 0; i < n; i++)
    {
        m[in[i]] =i;
    }
    return buildtree(pre,0,n-1,0,n-1,m);
}
 int main(){
    vector<int>pre = {1,2,4,5,3};
    vector<int>in = {4,2,5,1,3};
    TreeNode* root = construct(pre,in);
    print(root);
}