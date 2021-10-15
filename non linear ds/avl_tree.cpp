#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int calheight(Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}
Node* newNode(int key){
   Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
int max(int a,int b){
    return (a>b) ? a:b;
}
Node* rightRotation(Node *y){
    Node* x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(calheight(y->left),calheight(y->right))+1;
    x->height = max (calheight(x->left),calheight(x->right))+1;
    return x;
}
Node* leftRotation(Node * x){
    Node* y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(calheight(x->left),calheight(x->right))+1;
    y->height = max (calheight(y->left),calheight(y->right))+1;
    return y;
}
int getBalanceFactor(Node* n){
    if(n==NULL)return 0;
    return calheight(n->left) - calheight(n->right);
}
Node* insert(Node* node, int key){
    if(node == NULL)
        return newNode(key);
    if(key< node->key)
        node->left = insert(node->left,key);
    else if(key > node->key)
        node->right = insert(node->right,key);
    else
        return node;
    node->height = 1+max(calheight(node->left), calheight(node->right));

    int balance = getBalanceFactor(node);
    if(balance>1 && key<node->left->key)
        return rightRotation(node);
    if(balance < -1 && key>node->right->key)
        return leftRotation(node);
    if(balance>1 && key>node->left->key){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if(balance < -1 && key<node->right->key){
        node->right =rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}
 void preorder(Node* root){
     if(root != NULL){
         cout<<root->key<<" ";
         preorder(root->left);
         preorder(root->right);
     }
 }
 int main(){
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    cout<<"Preorder: "<<endl;
    preorder(root);
    return 0;
 }