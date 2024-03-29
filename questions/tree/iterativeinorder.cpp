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
void inorder(TreeNode* root){
    if(root== NULL)return;
    stack<TreeNode*> st;
    TreeNode * node = root;
   while (node || !st.empty())
   {
       while(node){
           st.push(node);
           node= node->left;
       }
        node= st.top();
        st.pop();
        cout<<node->val<<" ";
        node=node->right;  
   }  
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    inorder(root);
}