//BST program to show the level order or breadth first traversal using queue data structure
#include<iostream>
#include<queue>
using namespace std;
struct bst_node{
    int data;
    bst_node* left,*right ;
};
void level_order(bst_node* root){
    if (root ==NULL){
        cout<<"EMPTY TREE!"<<endl;
    }
queue<bst_node*> q;
q.push(root);
while (!q.empty())
{
    bst_node* t = q.front();
    q.pop();
    cout<<t->data<<" ";
    if(t ->left != NULL) q.push(t->left);
    if(t ->right != NULL) q.push(t->right);
}
}
bst_node* insert(bst_node* root, int data){
    if(root ==NULL){
       bst_node* node = new bst_node();
       node->data = data;
       node->left =node ->right =NULL;
       root =node;
    }
    else if (data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
     root->right=insert(root->right,data);
     return root;
}
int main(){
bst_node * root = NULL;
root = insert(root,32);
root = insert(root,35);
root = insert(root,38);
root = insert(root,40);
root = insert(root,55);
root = insert(root,60);
root = insert(root,65);
root = insert(root,75);
level_order(root);
}