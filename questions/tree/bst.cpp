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
 int ceil(TreeNode* root, int data){
     int ceilval = -1;
     while(root){
         if(root->val== data){
             ceilval = root->val;
             return ceilval;
         }
         if(data>root->val){
             root= root->right;
         }
         else{
             ceilval = root->val;
             root= root->left;
         }
     }
     return ceilval;

 }
int floor(TreeNode* root, int data){
     int floorval = -1;
     while(root){
         if(root->val== data){
             floorval = root->val;
             return floorval;
         }
         if(data<root->val){
             root= root->left;
         }
         else{
             floorval = root->val;
             root= root->right;
         }
     }
     return floorval;

 }
 void insert(TreeNode* root,int data){
     if(!root) root = new TreeNode(data);
     while (root)
     {
        if(data>root->val){
            if(root->right)
                root = root->right;
            else {
                root->right = new TreeNode(data);
                return;
            }
        }
        else {
            if(root->left)root = root->left;
            else{
                root->left = new TreeNode(data);
                return;
            }
        }
     }
 }
 TreeNode* findlastright(TreeNode* root){
     while(root){
         root = root->right;
     }
     return root;
 }
 TreeNode* deletenode(TreeNode* , int);
TreeNode* helper(TreeNode* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    TreeNode* lastright = findlastright(root->left);
    root->val = lastright->val;
    deletenode(lastright, lastright->val);
    return root;
}
 TreeNode* deletenode(TreeNode* root, int key){
     if(!root)return NULL;
     if(root->val == key){
        return helper(root);
     }
     TreeNode* tmp = root;
     while (root)
     {
         if(root->val >key){
         if(root->left and root->left->val == key){
            root ->left= helper(root->left);
            break;
         }
         else root = root->left;
         }
         else
         {
             if (root->right and root->right->val==key)
             {
                 root->right = helper(root->right);
                 break;
             }
             else root= root->right;
         }
     }
    return tmp; 
 }
 void inorder(TreeNode* root){
     if(!root) return;
     inorder(root->left);
     cout<<root->val<<" ";
     inorder(root->right);
 }
bool search(TreeNode* root, int data){
    if(!root)return false;
    if(root->val== data) return true;
    if(root->val >data) return search(root->left,data);
    else return search(root->right,data);
}
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    // cout<<search(root,6);
    // cout<<ceil(root, 1);
    insert(root, 6);
    deletenode(root, 3);
    inorder(root);
}