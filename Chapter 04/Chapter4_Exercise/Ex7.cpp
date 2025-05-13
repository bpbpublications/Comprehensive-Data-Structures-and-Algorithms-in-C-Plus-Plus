//Ex7.cpp : Implement a stack using 2 queues.

#include <iostream>
#include<queue>
using namespace std;

class Stack
{
	private:
		queue<int> qu1, qu2;

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
	return qu1.empty();
}//End of isEmpty()

void Stack::push(int data)
{
	while(!qu1.empty())
	{
		qu2.push(qu1.front());
		qu1.pop();
	}

	qu1.push(data);
	while(!qu2.empty())
	{
		qu1.push(qu2.front());
		qu2.pop();
	}
}//End of push()

int Stack::pop()
{
	int retValue;

	if(qu1.empty())
		throw exception("Stack is empty");
	else
	{
		retValue = qu1.front();
		qu1.pop();
	}

	return retValue;
}//End of pop()

int Stack::peek()
{
	if(qu1.empty())
		throw exception("Stack is empty");

	return qu1.front();
}//End of peek()

int Stack::size()
{
	return qu1.size();
}//End of size()

void Stack::display()
{
	if(qu1.empty())
		cout << "Stack is empty\n";
	else
	{
		while(!qu1.empty())
		{
			qu2.push(qu1.front());
			cout << qu1.front() << "\n";
			qu1.pop();
		}

		while(!qu2.empty())
		{
			qu1.push(qu2.front());
			qu2.pop();
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
