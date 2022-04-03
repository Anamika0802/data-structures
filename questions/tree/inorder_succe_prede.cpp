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
 //max in left subtree
 TreeNode* inorderpredecessor(TreeNode* root, TreeNode* p){
     TreeNode* pred = NULL;
     while (root)
     {
         if(p->val==root->val){
             if(root->left){
                 TreeNode* tmp = root->left;
                 while (tmp->right)
                 {
                     tmp= tmp->right;
                 }
                 return tmp;
             }
         }
         if(p->val>root->val) root = root->right;
         else root = root->left;
     }
   return pred;  
 }
 //mini in right subtree
 TreeNode* inordersuccessor(TreeNode* root, TreeNode* p){
     TreeNode* succesor = NULL;
     while (root)
     {
         if(p->val>=root->val)
            root= root->right;
        else
        {
            succesor = root;
            root= root->left;
        }
        
     }
     return succesor;
 }
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode* succ =inordersuccessor(root, root->left->left);
    TreeNode* pred =inorderpredecessor(root, root->left->left);
    cout<<succ->val<<" "<<pred->val;
}