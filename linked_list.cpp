#include<iostream>
using namespace std;
struct node
{
    int data;
    node *p ;
};
node* root= NULL;
//insert a new data element to the node at the provided position
void insert(int d,int n){
    node* t;
    t = new node;
    t->data= d;
    t->p = NULL;
 if (n==1){
     t->p = root;
 root= t;
 }
 else
 {
     node* t1 = root;
     for (int i = 0; i < n-2; i++)
     {
         t1 = t1->p;
     }
     t->p = t1->p;
     t1->p = t;  
 }
 free(t);
}
// remove the elment from the list of a given position
void remove(int n){
node* t = root;
 if (n==1){
root = t->p;
free(t);
return;
 }
 node* t1=root;
 for (int i = 0; i < n-2; i++)
     {
         t1 = t1->p;
     }
     t->p->p = t1->p->p;
}
// print all the elements in the list in forward direction
void display(){
    node * t=root;
    while (t->p!= NULL)
    {
        cout<<t->data<<" ";
        t = t->p;
    }
    cout<<t->data<<" "<<"\n";
}
/* for recusive forward print
void print(struct node* p){
    if(p==NULL){
        cout<<endl;
    return;}
    cout<<p->data;
    print(p->p);
}*/
// print all the elements in the list in the reverse direction
void reverse(struct node* p){
if(p==NULL)
return;
reverse(p->p);
cout<<p->data<<" ";    
}
int main(){
    insert(3,1);
    insert(4,2);
    insert(5,3);
    insert(7,1);
    display();
    remove(3);
    display();
    reverse(root);
}