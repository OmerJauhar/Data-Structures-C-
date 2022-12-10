// // C++ program for the above methods
// #include<iostream>
// using namespace std;
// class Stack
// {
// private:
// int* arr;
// int size;
// int noOfElements;
// int top; // Index
// public:
// Stack(int size)
// {
// this->size = size;
// arr = new int[size];
// top = -1;
// }
// ~Stack()
// {
// delete[] arr;
// }
// void push(int val)
// {
// if (top == size - 1)
// {
// cout << "Stack OverFlow" << endl;
// return;
// }
// arr[++top] = val;
// noOfElements++;
// }
// void push1(int val)
// {
// if (top == size - 1)
// {
// cout << "Stack OverFlow" << endl;
// return;
// }
// Stack temp(noOfElements);
// for (int x = 1; x <= noOfElements; x++)
// {
// if (temp.top == temp.size - 1)
// {
// cout << "Stack OverFlow" << endl;
// }
// else
// {
// temp.arr[++temp.top] = pop();
// temp.noOfElements++;
// }
// }
// top = 0;
// arr[top] = val;
// for (int x = 1; x <= noOfElements; x++)
// {
// arr[++top] = temp.pop();
// }
// noOfElements++;
// }
// int pop()
// {
// if (top == -1)
// {
// cout << "Stack UnderFlow" << endl;
// return 0;
// }
// else
// return arr[top--];
// }
// int peek()
// {
// if (top == -1)
// {
// cout << "Stack UnderFlow" << endl;
// return 0;
// }
// return arr[top];
// }
// void display()
// {
// int x = 0;
// for (int i = top; i >= 0; i--)
// cout << "Item: " << ++x << " : " << arr[i] << endl;
// }
// };
// int main()
// {
// Stack stack1(5);
// stack1.push1(1);
// stack1.push1(2);
// stack1.push1(3);
// stack1.push1(4);
// stack1.push1(5);
// stack1.push1(6);
// // stack1.pop();
// stack1.display();
// return 0;
// }


// Stack USING sINGLE Linked List Implementation
//KS.
#include<iostream>
using namespace std;
class node
{
public:

node* previous;

int data;
node(int val)
{
data = val;
previous = NULL;
}
};
class Stack
{
private:

node* top;
int noOfElements;
int size;
public:

Stack()

{
top = NULL;
noOfElements = 0;
size = 10;
}
void push(int val);
// Display
void display();
// Remove
int pop();
int peek()
{
return top->data;
}
bool isEmpty();
int getLength();
void setSize(int size)
{
this->size = size;
}
};
int main()
{
Stack stack1, stack2;
stack1.push(1);
stack1.push(2);
stack1.push(3);
stack1.push(4);
stack1.push(5);
stack1.push(6);
stack1.pop();
stack1.display();
cout << endl << " Stack size: " << stack1.getLength() << endl;
return 0;
}
int Stack :: getLength()
{
return this->noOfElements;
}
bool Stack :: isEmpty()
{
if (noOfElements == 0) // If (top==NULL)
return true;
else
false;
}
int Stack:: pop()
{
if (top == NULL)
{
cout << "List is Empty: Stack Under Flow, return -1" << endl;
return -1;
}
else
{
node* curr = top;
int data = curr->data;
top = curr->previous;
delete curr;
noOfElements--;
return data;
}
}
void Stack::push(int val)
{
    if (noOfElements < size)
{
node* t = new node(val);
if (top == NULL)
{ // Stack is Empty
top = t;
noOfElements++;
}
else
{
t->previous = top;
top = t;
noOfElements++;
}
}
else
cout << "Stack Full: Over Flow" << endl;
}
void Stack::display()
{
node* curr = top;
while (curr != NULL)
{
cout << "Node: " << curr->data << endl;
curr = curr->previous;
}
}