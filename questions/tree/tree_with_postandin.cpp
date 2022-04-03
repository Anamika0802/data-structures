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
TreeNode* buildtree(vector<int>&post, int posts, int poste,int ins, int ine,map<int, int>&m){
    if(posts>poste|| ins>ine) return NULL;
    TreeNode* root = new TreeNode(post[poste]);
    int i = m[root->val];
    int numl = i - ins;
    root->left = buildtree(post,posts,posts+numl-1,ins,ins+numl,m);
    root->right = buildtree(post,posts+numl,poste-1,ins+numl+1,ine,m);
    return root;
}
TreeNode* construct(vector<int>&post, vector<int>&in){
    map<int, int>m;
    int n = in.size();
    for (int i = 0; i < n; i++)
    {
        m[in[i]] =i;
    }
    return buildtree(post,0,n-1,0,n-1,m);
}
 int main(){
    vector<int>post = {4,5,2,3,1};
    vector<int>in = {4,2,5,1,3};
    TreeNode* root = construct(post,in);
    print(root);
}