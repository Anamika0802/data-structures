#include<bits/stdc++.h>
using namespace std;
vector<int>pre;
vector<int>in;
vector<int>post;
void print(int n, vector<int> a){ for(int i=0;i<n;i++)cout<<a[i]<<" ";}
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right){};
};

void traversal(TreeNode* root){
    stack<pair<TreeNode*,int>>s;
    s.push({root, 0});
    while (!s.empty())
    {
        root = s.top().first;
        int t = s.top().second;
        s.pop();
        if(t==0){
            pre.push_back(root->val);
            t++;
            s.push({root, t});
            if(root->left) s.push({root->left,0});
        }
        else if(t==1){
            in.push_back(root->val);
            t++;
            s.push({root,t});
            if(root->right) s.push({root->right,0});
        }
        else
        {
            post.push_back(root->val);
        }
        
    }
    
}
int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    traversal(root);
    print(pre.size(), pre);
    cout<<endl;
    print(in.size(), in);
    cout<<endl;
    print(post.size(), post);
}