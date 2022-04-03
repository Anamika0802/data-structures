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
void preorder(TreeNode* root){
    if(root== NULL)return;
    stack<TreeNode*> st;
    // while (!st.empty() || root)
    // {
    //     while (root)
    //     {
    //         cout<<root->val<<" ";
    //         if(root->right)st.push(root->right);
    //         root= root->left;
    //     }
    //     if (!st.empty())
    //     {
    //         root = st.top();
    //         st.pop();
    //     }
        
    // }
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        cout<<root->val<<" ";
        if(root->right)st.push(root->right);
        if(root->left) st.push(root->left);
    }
    
    
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    preorder(root);
}