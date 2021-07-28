#include<iostream>
using namespace std;
# define Max 10
int q[Max];
int front =0,rear =0;
void queueEnqueue(){
int d;
 if (rear==Max -1)
 cout<<"Queue is full";
 else{
 cout<<"Enter Data";
 cin>>d;
 q[rear]=d;
 rear++;
 } 
 return; 
}
void queueDequeue(){
 if (rear==front)
 cout<<"Queue is empty!";
 else{
 for (int i = front; i < rear -1; i++)
 {
 q[i]=q[i+1];
 }
 cout<<"Deleted element is "<<q[front]<<"\n";
 rear--;
 }
 return;
}
void queueDisplay(){
 if (rear==front)
 cout<<"Queue is empty!";
 else{
 for (int i = 0; i < rear; i++)
 cout<<q[i]<<" ";
 }
 cout<<"\n";
 return;
}
int main(){
int c;
do{
 cout<<"Menu\n1: Insert\n2: Delete\n3: Display\n4: Exit\n";
 cout<<"Enter choice";
 cin>>c;
switch (c)
{
case 1:
queueEnqueue();
 break;
case 2:
 queueDequeue();
 break;
case 3:
 queueDisplay();
 break;
case 4:
 break;
default:
 cout<<"Invalid Choice!";
 break;
}}while(c!=4);
}