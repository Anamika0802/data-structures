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
int ans=0,cnt=0;
 void kthsmallest(TreeNode* root, int k){
     if(!root) return;
     kthsmallest(root->left,k);
     cnt++;
     if(cnt==k){
         ans = root->val;
         return;
     } 
     kthsmallest(root->right,k);
 }
 void kthlargest(TreeNode* root, int k){
     if(!root) return;
     kthlargest(root->left,k);
     cnt++;
     if(cnt==k){
         ans = root->val;
         return;
     } 
     kthlargest(root->right,k);
 }
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    // kthsmallest(root,3);
    kthlargest(root,3);//no. of nodes - k;
    cout<<ans;
}