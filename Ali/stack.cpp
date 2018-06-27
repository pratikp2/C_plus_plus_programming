#include <iostream>
using namespace std;
struct ArrayStack
{
int top;
int capacity;
int *Array;
};

ArrayStack* createStack(int cap)
{
ArrayStack *Stack;
Stack = new ArrayStack;
Stack->top = -1;
Stack->capacity = cap;
Stack->Array = new int[Stack->capacity] ;
return Stack;
}

int isFull(ArrayStack *Stack)
{
if(Stack->top == Stack->capacity-1)
    {
cout << "Stack is Full!!!!" << endl;
return 1;
}
else
    return 0;
}

int isEmpty(ArrayStack *Stack)
{
if(Stack->top == -1)
{
        cout << "Stack is Empty!!!!" << endl;
        return 1;
}
else
    return 0;
}

void push(ArrayStack *Stack,int element)
{
 if(!isFull(Stack))
 {
 Stack->top++;
 Stack->Array[Stack->top] = element;
cout << "Element inserted to Stack!!!!" << element <<endl;
 }
}

int pop(ArrayStack *Stack)
{
if(!isEmpty(Stack))
{
int element = Stack -> Array[Stack->top];
Stack->top--;
return element;
}
return -1;
}

int main()
{
ArrayStack *Stack;
int choice;
int element;
Stack = createStack(3);
cout << "enter choice" << endl;

while(1)
{
    cin >> choice;
switch(choice)
{
case 1:
    push(Stack,40);
    break;
case 2:
    element = pop(Stack);
    cout << element << endl;
   // break;
}
}
}
