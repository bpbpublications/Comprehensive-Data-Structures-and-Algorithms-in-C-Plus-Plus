//Ex12.cpp : Copy the contents of a stack S1 to another stack S2 using one temporary stack.

#include <iostream>
using namespace std;

static const int maxSize = 30;

class Stack
{
	private:
		int stackArray[maxSize];
		int top;

	public:
		Stack();
		bool isEmpty();
		bool isFull();
		void push(int data);
		int pop();
		int peek();
		void display();
		int size();
};//End of class Stack

Stack::Stack()
{ 
	top = -1;
}//End of Stack()

bool Stack::isEmpty()
{
	return (top == -1);
}//End of isEmpty()

bool Stack::isFull()
{
	return (top == maxSize-1);
}//End of isFull()

void Stack::push(int data)
{
	if(isFull())
		cout << "Stack Overflow\n";
	else
	{
		top++;
		stackArray[top] = data;
	}
}//End of push()

int Stack::pop()
{
	if(isEmpty())
		throw exception("Stack is empty");

	int retValue = stackArray[top];
	top = top-1;

	return retValue;
}//End of pop()

int Stack::peek()
{
	if(isEmpty())
		throw exception("Stack is empty");

	return stackArray[top];
}//End of peek()

int Stack::size()
{
	return (top+1);
}//End of size()

void Stack::display()
{
	if(isEmpty())
		cout << "Stack is empty\n";
	else
		for(int i=top; i>=0; i--)
			cout << stackArray[i] << "\n";
}//End of display()

int main()
{
	Stack st1, st2, temp;

	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	st1.push(50);

	cout << "Stack1 Items : \n";
	st1.display();

	while(!st1.isEmpty())
		temp.push(st1.pop());

	cout << "Temporary stack items : \n";
	temp.display();

	while(!temp.isEmpty())
	{
		st1.push(temp.peek());
		st2.push(temp.peek());
		temp.pop();
	}

	cout << "Stack1 Items : \n";
	st1.display();

	cout << "Stack2 Items : \n";
	st2.display();

	return 0;
}//End of main()
