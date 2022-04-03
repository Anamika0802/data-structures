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
 vector<int>trav;
 void spiral(TreeNode* root){
     if(!root)return;
     queue<TreeNode*>q;
     q.push(root);
     bool isrev =false;
     while (!q.empty())
     {
        int size = q.size();
        vector<int>temp(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode* node =  q.front();
            q.pop();
            int index = (isrev)?(size-1-i):i;
            temp[i] =node->val;
            // cout<<root->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        trav.insert(trav.end(),temp.begin(),temp.end());
        isrev = !isrev;
     }
     
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    spiral(root);
    for(auto i:trav){cout<<i<<" ";}
}