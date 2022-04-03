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
void getinorder(TreeNode* root){
    TreeNode* curr = root;
    while (curr)
    {
        if(!curr->left){
            cout<<curr->val<<" ";
            curr= curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while (prev->right and prev->right!=curr)
            {
                prev = prev->right;
            }
            if(!prev->right){
                prev->right = curr;
                curr= curr->left;
            }
            else
            {
                prev->right = NULL;
                cout<<curr->val<<" ";
                curr= curr->right;
            }
            
        }
    }
    
}
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    getinorder(root);
}