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
void flatten(TreeNode* root){
    TreeNode* curr = root;
    TreeNode* prev;
    while (curr)
    {
        if(curr->left){
            prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            
        }
        curr = curr->right;
    }
    
}
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    print(root);
    cout<<endl;
    flatten(root);
    print(root);
}