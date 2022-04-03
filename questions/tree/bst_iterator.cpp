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
 public:
     bst_iterator(TreeNode* root){
         pushAll(root);
     }
     bool hasnext(){
         return st.empty();
     }
     int next(){
         TreeNode* node = st.top();
         st.pop();
         pushAll(node->right);
         return node->val;
     }
 private:
    void pushAll(TreeNode* root){
        while (root)
        {
            st.push(root);
            root = root->left;
        }    
    }
 };
 
 
 int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    bst_iterator r(root);
    cout<<r.hasnext()<<endl;
    cout<<r.next();
}