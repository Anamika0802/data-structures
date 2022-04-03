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
 class bst_iterator
 {
 private:
     stack<TreeNode*> st;
     bool reverse;
 public:
     bst_iterator(TreeNode* root, bool rev){
         reverse = rev;
         pushAll(root);
     }
     bool hasnext(){
         return st.empty();
     }
     int next(){
         TreeNode* node = st.top();
         st.pop();
         if(!reverse)pushAll(node->right);
         else pushAll(node->left);
         return node->val;
     }
 private:
    void pushAll(TreeNode* root){
        while (root)
        {
            st.push(root);
            if(reverse)root = root->right;
            else root = root->left;
        }    
    }
 };
 
 bool findtarget(TreeNode* root, int k){
     if(!root) return false;
     bst_iterator l(root,false);
     bst_iterator r(root,true);
     int i = l.next();
     int j= r.next();
     while (i<j)
     {
         if(i+j==k)return true;
         else if(i+j<k)i = l.next();
         else j = r.next();
     }
     return false;
 }
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout<<findtarget(root, 10);
}