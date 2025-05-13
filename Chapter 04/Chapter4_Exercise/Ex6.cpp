//Ex6.cpp : Implement a queue using 2 stacks.

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
	private:
		stack<int> instack, outstack;

	public:
		Queue(){};
		bool isEmpty();
		bool isFull();
		void enqueue(int data);
		int dequeue();
		int peek();
		void display();
		int size();
};//End of class Queue

bool Queue::isEmpty()
{
	return (instack.empty() && outstack.empty());
}//End of isEmpty()

void Queue::enqueue(int data)
{
	instack.push(data);
}//End of enqueue()

int Queue::dequeue()
{
	if(isEmpty())
		throw exception("Queue is empty");

	if(outstack.empty())
	{
		while(!instack.empty())
		{
			outstack.push(instack.top());
			instack.pop();
		}
	}

	int retValue = outstack.top();
	outstack.pop();

	return retValue;
}//End of dequeue()

int Queue::peek()
{
	if(isEmpty())
		throw exception("Queue is empty");

	if(outstack.empty())
	{
		while(!instack.empty())
		{
			outstack.push(instack.top());
			instack.pop();
		}
	}

	int retValue = outstack.top();

	return retValue;
}//End of peek()

void Queue::display()
{
	if(isEmpty())
		cout << "Queue is empty\n";
	else
	{
		int instackSize = instack.size();
		int outstackSize = outstack.size();
		while(!outstack.empty())
		{
			instack.push(outstack.top());
			cout << outstack.top() << "\n";
			outstack.pop();
		}

		while(!instack.empty())
		{
			outstack.push(instack.top());
			instack.pop();
		}

		for(int i=0; i<instackSize; i++)
		{
			instack.push(outstack.top());
			cout << outstack.top() << "\n";
			outstack.pop();
		}
	}//End of else

}//End of display()

int Queue::size()
{
	int retValue=0;

	if(!isEmpty())
		retValue = instack.size() + outstack.size();

	return retValue;
}//End of size()

int main()
{
	Queue qu;

	try
	{
		cout << "Is queue empty : " << ((qu.isEmpty()) ? "True" : "False") << "\n";

		qu.enqueue(1);
		qu.enqueue(2);
		qu.enqueue(3);
		qu.enqueue(4);

		cout << "Queue Items :\n";
		qu.display();
		cout << "Front Item : " << qu.peek() << "\n";
		cout << "Total items : " << qu.size() << "\n";

		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Queue Items :\n";
		qu.display();

		qu.enqueue(5);

		cout << "Queue Items :\n";
		qu.display();

		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Deleted Item : " << qu.dequeue() << "\n";

		cout << "Queue Items :\n";
		qu.display();

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()
