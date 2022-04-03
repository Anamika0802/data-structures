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
int width(TreeNode* root){
     if(!root)return 0;
     queue<pair<TreeNode*,int>>q;
     q.push({root,0});
     int ans  =0;
     while (!q.empty())
     {
        int size = q.size();
        int mini = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node =  q.front().first;
            int curr_id = q.front().second- mini;
            q.pop();
            if(i==0) first = curr_id;
            if(i== size-1) last = curr_id;
            if(node->left)
                q.push({node->left,curr_id*2+1});
            if(node->right)
                q.push({node->right,curr_id*2+2});
        }
        ans = max(ans, last-first+1);
     }
    return ans; 
 }
int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<width(root);
}