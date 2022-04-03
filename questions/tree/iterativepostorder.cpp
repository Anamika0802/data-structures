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
void post(TreeNode* root){
    stack<TreeNode*>st;
    TreeNode* temp;
    while (root || !st.empty())
    {
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            temp = st.top()->right;
            if(!temp){
                temp = st.top();
                st.pop();
                cout<<temp->val<<" ";
                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout<<temp->val<<" ";
                }
                
            }
            else root = temp;
        }
    }
    
}
void postorder(TreeNode* root){
    if(root== NULL)return;
    stack<TreeNode*> st;
    stack<TreeNode*> st2;
    st.push(root);
   while (!st.empty())
   {
       root = st.top();
       st.pop();
       st2.push(root);
       if (root->left)
           st.push(root->left);
       if(root->right) st.push(root->right);
   }
   while (!st2.empty())
   {
       cout<<st2.top()->val<<" ";
       st2.pop();
   }
   
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    postorder(root);
    cout<<endl;
    post(root);
}