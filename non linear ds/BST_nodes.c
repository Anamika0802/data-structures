#include<stdio.h>
#include<stdlib.h>
struct bst_node{
    int data;
    struct bst_node* left,*right ;
};
// Function to insert a new node
struct  bst_node* insert(struct bst_node* root, int data){
    if(root ==NULL){
       struct bst_node* node = (struct bst_node *)malloc(sizeof(struct bst_node));
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
//function to count all nodes of BST
static int c =0;
int allnodescount(struct bst_node * root){
if(root!= NULL){
    allnodescount(root->left);
    c++;
    allnodescount(root->right);
}
return c;
} 
//function to count all leaf nodes of BST
static int c1=0;
int leafcount(struct bst_node * root){

if(root!= NULL){
    leafcount(root->left);
    if(root->left == NULL && root->right ==NULL)c1++;
    leafcount(root->right);
}
return c1;
} 
//function to count all nodes with right child only of BST
static int c2=0;
int rightchild(struct bst_node * root){

if(root!= NULL){
    rightchild(root->left);
    if(root->left == NULL && root->right !=NULL)c2++;
    rightchild(root->right);
}
return c2;
} 
//function to count all nodes with left child only of BST
static int c3=0;
int leftchild(struct bst_node * root){

if(root!= NULL){
    leftchild(root->left);
    if(root->left != NULL && root->right ==NULL)c3++;
    leftchild(root->right);
}
return c3;
} 
//function to count all nodes of BST having information greater than root
static int c4=0;
int greaterroot(struct bst_node * root){
if(root!=NULL && c4==0) root = root->right;
if(root!= NULL){
    c4++;
    greaterroot(root->left);
    greaterroot(root->right);
}
return c4;
} 
void inorder(struct bst_node * root){
    if(root == NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
} 
int main(){
struct bst_node * root = NULL;
root = insert(root,5);
root = insert(root,10);
root = insert(root,15);
root = insert(root,3);
root = insert(root,4);
root = insert(root,1);
root = insert(root,9);
printf("Total numbeer of nodes in the tree are : %d \n",allnodescount(root));
printf("Total numbeer of leaf nodes : %d\n",leafcount(root));
printf("Total numbeer of nodes with right child only : %d\n",rightchild(root));
printf("Total numbeer of nodes with left child only : %d\n",leftchild(root));
printf("Total numbeer of nodes with info greater than root : %d\n",greaterroot(root));
}
