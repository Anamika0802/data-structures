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
 int sum =0;
int maxpathsum(TreeNode* root){
    if(!root) return 0;
    int ls = maxpathsum(root->left);
    int rs = maxpathsum(root->right);
    sum = max(sum, root->val+ ls+ rs);
    return root->val+ max(ls, rs);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    maxpathsum(root);
    cout<<sum;
}