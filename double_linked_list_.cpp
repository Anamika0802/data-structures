#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next=NULL;
    node* prev=NULL;
}; node* root =NULL;
//insert the elements in double linked list
void insert(int d,int n){
    node* t;
    t = new node;
    t->data= d;
    t->next = NULL;
    t->prev = NULL;
 if (n==1){
     if(root == NULL){
         root = t;
         return;
     }
   t->next= root;
   root->prev = t->next;
     root = t;
 }
 else
 {
     node* t1 = root;
     for (int i = 0; i < n-2; i++)
     {
         t1 = t1->next;
     }
     t->prev = t1;
     t1->next = t;  
 }
}
//print all the elements of double linked list in forward order
void display(){
    node* t=root;
    while (t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
   cout<<endl; 
   return;
}
//print all the elements of double linked list in reverse order
void reverse(){
node* t = root;
if(t==NULL)return;
while (t->next != NULL)
{
    t =t->next;
}
while (t!=NULL)
{
    cout<<t->data<<" ";
    t= t->prev;
}
cout<<endl;
}
int main(){
insert(1,1);
insert(2,2);
insert(3,3);
display();
reverse();
    return 0;
}
