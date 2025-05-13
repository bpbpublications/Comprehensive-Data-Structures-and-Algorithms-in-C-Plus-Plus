//Ex1.cpp : Implement a stack in an array A, using A[0] as the top.

#include <iostream>
using namespace std;

static const int maxSize = 5;

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
	top = 0;
}//End of Stack()

bool Stack::isEmpty()
{
	return (top == 0);
}//End of isEmpty()

bool Stack::isFull()
{
	return (top == maxSize);
}//End of isFull()

void Stack::push(int data)
{
	if(isFull())
		cout << "Stack Overflow\n";
	else
	{
		stackArray[top] = data;
		top++;
	}
}//End of push()

int Stack::pop()
{
	if(isEmpty())
		throw exception("Stack is empty");

	top = top-1;
	int retValue = stackArray[top];

	return retValue;
}//End of pop()

int Stack::peek()
{
	if(isEmpty())
		throw exception("Stack is empty");

	return stackArray[top-1];
}//End of peek()

int Stack::size()
{
	return (top);
}//End of size()

void Stack::display()
{
	if(isEmpty())
		cout << "Stack is empty\n";
	else
		for(int i=top-1; i>=0; i--)
			cout << stackArray[i] << "\n";
}//End of display()

int main()
{
	Stack st;

	try
	{
		cout << "Is stack empty : " << ((st.isEmpty()) ? "True" : "False") << "\n";
		cout << "Is stack full : " << ((st.isFull()) ? "True" : "False") << "\n";

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		cout << "Stack Items : \n";
		st.display();
		cout << "Top Item : " << st.peek() << "\n";
		cout << "Total items : " << st.size() << "\n";

		cout << "Popped Item : " << st.pop() << "\n";
		cout << "Stack Items : \n";
		st.display();

		st.push(4);
		st.push(5);

		cout << "Stack Items : \n";
		st.display();

		cout << "Popped Item : " << st.pop() << "\n";
		cout << "Popped Item : " << st.pop() << "\n";
		cout << "Popped Item : " << st.pop() << "\n";
		cout << "Popped Item : " << st.pop() << "\n";
		cout << "Popped Item : " << st.pop() << "\n";

		cout << "Stack Items : \n";
		st.display();

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()


