#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* front =NULL;
node* rear = NULL;
//To enqueue elements in the queue
void enqueue(int x){
node* temp;
temp = (node*)malloc(sizeof(node));
temp->data = x;
temp->next= NULL;
if (front ==NULL && rear == NULL){
    front = temp;
     rear = temp;
    return;
}
rear ->next = temp;
rear = temp;
return;
}
//To dequeue elements from the queue
void dequeue(){
     if(front ==NULL){
     cout<<"Queue is Empty...!";
     return;}
     if(front == rear){
         front = rear = NULL;
     }
     else{
         front = front ->next;
     }
}
// To display the first element of the queue
void first(){
    if(front ==NULL){
    cout<<"Queue is Empty...!";
    return;}
    cout<<"Data at front is :"<<front->data<<endl;
    return;
}
// To display all the elements of the queue
void display(){
    node* temp = front;
    while(temp!= NULL){
        cout<< temp ->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}
int main(){
enqueue(2);
display();
enqueue(3);
enqueue(4);
enqueue(5);
display();
dequeue();
first();
display();
return 0;
}