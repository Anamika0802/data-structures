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
 void print(TreeNode*root){
     if(!root)return ;
     print(root->left);
     cout<<root->val<<" ";
     print(root->right);
 }
 TreeNode* deserialize(string data){
     if(data.size()==0) return NULL;
     stringstream s(data);
     string str;
     getline(s,str,',');
     queue<TreeNode*>q;
     TreeNode* root = new TreeNode(stoi(str));
     q.push(root);
     while (!q.empty())
     {
         TreeNode* node = q.front();
         q.pop();
         getline(s,str,',');
         if(str== "#"){
             node->left = NULL;
         }
         else
         {
             node->left = new TreeNode(stoi(str));
             q.push(node->left);
         }
         getline(s,str,',');
         if(str== "#"){
             node->right = NULL;
         }
         else
         {
             node->right = new TreeNode(stoi(str));
             q.push(node->right);
         }
     }
     return root;
 }
 string serialize(TreeNode* root){
     if(!root) return "";
     queue<TreeNode*>q;
     q.push(root);
     string s = "";
     while (!q.empty())
     {
         TreeNode* node = q.front();
         q.pop();
         if(!node)s.append("#,");
         else s.append(to_string(node->val)+",");
         if (node)
         {
             q.push(node->left);
             q.push(node->right);
         }
         
     }
     return s;
 }
 int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    string s = serialize(root);
    TreeNode* roo = deserialize(s);
    print(roo);
}