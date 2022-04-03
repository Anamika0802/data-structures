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
 class solu{
    private:
        TreeNode* first;
        TreeNode* last;
        TreeNode* middle;
        TreeNode* prev;
        void inorder(TreeNode* root){
            if(!root)return;
            inorder(root->left);
            if(prev and (root->val <prev->val)){
                if(!first){
                    first = prev;
                    middle = root;
                }
                else last = root;
            }
            prev = root;
            inorder(root->right);
        }
    public:
        void recoverTree(TreeNode* root){
            first = middle = last = NULL;
            prev = new TreeNode(INT_MIN);
            inorder(root);
            if(first and last) swap(first->val, last->val);
            else if(first and middle) swap(first->val , middle->val);
        }
 };
void print(TreeNode* root){
    if(!root) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}
int main(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    print(root);
    cout<<endl;
    solu s;
    s.recoverTree(root);
    print(root);
}