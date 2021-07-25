 #include <iostream>
 using namespace std;
 #define Max 10
 int push(int stack[], int top)
 {
 if (top == Max - 1)
 cout<<"Stack is full..... Please remove the elements from the stack first \n";
 else
 {
 top++;
 int element;
 cout<<"Enter the element you want to insert : ";
 cin>>element;
 stack[top] = element;
 }
 return top;
 }
 int pop(int stack[], int top)
 {
 if (top == -1)
  cout<<"Stack is empty..... Please fill the stack first \n";
 else
 {
 cout<<"Deleted "<<stack[top]<<" from the stack\n";
 top--;
 }
 return top;
 }
 void peek(int stack[],int top){
     cout<<"Last element of the atack is :"<<stack[top]<<endl;
 }
 void display(int stack[], int top)
 {
 if (top == -1)
 cout<<"There is nothing to display as the stack is empty\n";
 else
 {
 cout<<"Elements of the stack are";
 for (int i = 0; i <=top; i++)
 {
     cout<<stack[i]<<" ";
 }
 cout<<endl;}
 return ;}
 int main(){
 int stack[Max], top = -1, ch;
 char ch1;
 do
 {
 cout<<"\n Menu\n 1 push\n 2 Pop\n 3 Display\n 4 Peek";
cout<<"\nEnter your Choice : ";
cin>>ch;
 switch (ch)
 {
 case 1:
 top = push(stack, top);
 break;
 case 2:
 top = pop(stack, top);
 break;

 case 3:
display(stack, top);
 break;
 case 4:
    peek(stack, top);
 break;
default:
 printf("INVALID CHOICE\n");
 }
cout<<"DO YOU WANT TO CONTINUE .... PRESS Y FOR YES AND N FOR NO : ";
cin>>ch1;

 } while (ch1 != 'N');
 return 0;
 }