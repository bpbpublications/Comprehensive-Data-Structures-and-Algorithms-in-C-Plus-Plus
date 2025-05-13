//Ex4.cpp : Write a program to implement 2 stacks in a single array of size N.

#include <iostream>
using namespace std;

static const int maxSize = 10;

class Stack
{
	private:
		int stackArray[maxSize];
		int topA;
		int topB;

	public:
		Stack();
		bool isEmpty();
		bool isFull();
		void pushA(int data);
		void pushB(int data);
		int popA();
		int popB();
		void displayA();
		void displayB();
};//End of class Stack

Stack::Stack()
{ 
	topA = -1;
	topB = maxSize;
}//End of Stack()

bool Stack::isFull()
{
	return (topA == topB-1);
}//End of isFull()

void Stack::pushA(int data)
{
	if(isFull())
		cout << "Stack Overflow\n";
	else
	{
		topA++;
		stackArray[topA] = data;
	}
}//End of pushA()

void Stack::pushB(int data)
{
	if(isFull())
		cout << "Stack Overflow\n";
	else
	{
		topB--;
		stackArray[topB] = data;
	}
}//End of pushB()

int Stack::popA()
{
	if(topA==-1)
		throw exception("Stack is empty");

	int retValue = stackArray[topA];
	topA = topA-1;

	return retValue;
}//End of pop()

int Stack::popB()
{
	if(topB==maxSize)
		throw exception("Stack is empty");

	int retValue = stackArray[topB];
	topB = topB+1;

	return retValue;
}//End of popB()

void Stack::displayA()
{
	if(topA==-1)
		cout << "StackA is empty\n";
	else
		for(int i=topA; i>=0; i--)
			cout << stackArray[i] << "\n";

}//End of displayA()

void Stack::displayB()
{
	if(topB==maxSize)
		cout << "StackB is empty\n";
	else
		for(int i=topB; i<maxSize; i++)
			cout << stackArray[i] << "\n";

}//End of displayA()


int main()
{
	Stack st;

	try
	{
		st.pushA(1);
		st.pushA(2);
		st.pushA(3);
		st.pushA(4);

		cout << "StackA Items : \n";
		st.displayA();

		cout << "StackA Popped Item : " << st.popA() << "\n";
		cout << "StackA Items : \n";
		st.displayA();

		st.pushA(4);
		st.pushA(5);

		cout << "StackA Items : \n";
		st.displayA();

		st.pushB(6);
		st.pushB(7);
		st.pushB(8);
		st.pushB(9);

		cout << "StackB Items : \n";
		st.displayB();

		cout << "StackB Popped Item : " << st.popB() << "\n";
		cout << "StackB Items : \n";
		st.displayB();

		st.pushB(9);
		st.pushB(10);

		cout << "StackB Items : \n";
		st.displayB();

		st.pushA(11);
		st.pushB(12);

		cout << "StackA Popped Item : " << st.popA() << "\n";
		cout << "StackA Popped Item : " << st.popA() << "\n";
		cout << "StackA Popped Item : " << st.popA() << "\n";
		cout << "StackA Popped Item : " << st.popA() << "\n";
		cout << "StackA Popped Item : " << st.popA() << "\n";

		cout << "StackA Items : \n";
		st.displayA();

		cout << "StackB Popped Item : " << st.popB() << "\n";
		cout << "StackB Popped Item : " << st.popB() << "\n";
		cout << "StackB Popped Item : " << st.popB() << "\n";
		cout << "StackB Popped Item : " << st.popB() << "\n";
		cout << "StackB Popped Item : " << st.popB() << "\n";

		cout << "StackB Items : \n";
		st.displayB();

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()
