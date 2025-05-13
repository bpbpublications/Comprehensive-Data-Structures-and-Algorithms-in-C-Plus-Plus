//Ex8.cpp : Implement a stack with one queue.

#include <iostream>
#include<queue>
using namespace std;

class Stack
{
	private:
		queue<int> qu;

	public:
		Stack(){};
		bool isEmpty();
		void push(int data);
		int pop();
		int peek();
		void display();
		int size();
};//End of class Stack

bool Stack::isEmpty()
{
	return qu.empty();
}//End of isEmpty()

void Stack::push(int data)
{
	qu.push(data);

	int size = qu.size();
	for(int i=0; i<size-1; i++)
	{
		qu.push(qu.front());
		qu.pop();
	}

}//End of push()

int Stack::pop()
{
	int retValue;

	if(qu.empty())
		throw exception("Stack is empty");
	else
	{
		retValue = qu.front();
		qu.pop();
	}

	return retValue;
}//End of pop()

int Stack::peek()
{
	if(qu.empty())
		throw exception("Stack is empty");

	return qu.front();
}//End of peek()

int Stack::size()
{
	return qu.size();
}//End of size()

void Stack::display()
{
	if(qu.empty())
		cout << "Stack is empty\n";
	else
	{
		int size = qu.size();
		for(int i=0; i<size; i++)
		{
			cout << qu.front() << "\n";
			qu.push(qu.front());
			qu.pop();
		}
	}

}//End of display()

int main()
{
	Stack st;

	try
	{
		cout << "Is stack empty : " << ((st.isEmpty()) ? "True" : "False") << "\n";

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
