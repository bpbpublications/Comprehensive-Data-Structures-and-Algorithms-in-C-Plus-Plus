//Ex10.cpp : Reverse a stack using a queue.

#include <iostream>
#include<queue>
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
	Stack st;
	queue<int> qu;

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	cout << "Stack Items :\n";
	st.display();

	while(!st.isEmpty())
		qu.push(st.pop());

	while(!qu.empty())
	{
		st.push(qu.front());
		qu.pop();
	}

	cout << "Reversed stack items : \n";
	st.display();

	return 0;
}//End of main()


