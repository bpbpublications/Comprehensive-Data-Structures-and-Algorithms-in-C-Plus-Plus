//Ex2.cpp : Implement a queue in an array such that if rear reaches the end, all the elements are shifted left.

#include <iostream>
using namespace std;

static const int maxSize = 5;

class Queue
{
	private:
		int queueArray[maxSize];
		int front;
		int rear;

	public:
		Queue();
		bool isEmpty();
		bool isFull();
		void enqueue(int data);
		int dequeue();
		int peek();
		void display();
		int size();
};//End of class Queue

Queue::Queue()
{
	front = -1;
	rear = -1;
}//End of Queue()

bool Queue::isEmpty()
{
	return (front==-1 || front==rear+1);
}//End of isEmpty()

bool Queue::isFull()
{
	return (front==0 && (rear==maxSize-1));
}//End of isFull()

void Queue::enqueue(int data)
{
	if(isFull())
		cout << "Queue Overflow\n";
	else
	{
		if(front == -1)
			front = 0;

		if(rear == maxSize-1)
		{
			for(int i=0,j=front; i<size(); i++,j++)
				queueArray[i] = queueArray[j];

			rear = size()-1;
			front = 0;
		}

		rear = rear+1;
		queueArray[rear] = data;

	}//End of else
}//End of enqueue()

int Queue::dequeue()
{
	if(isEmpty())
		throw exception("Queue is empty");

	return queueArray[front++];
}//End of dequeue()

int Queue::peek()
{
	if(isEmpty())
		throw exception("Queue is empty");

	return queueArray[front];
}//End of peek()

void Queue::display()
{
	cout << "Front = " << front << "	rear = " << rear << "\n";

	if(isEmpty())
		cout << "Queue is empty\n";
	else
		for(int i=front; i<=rear; i++)
			cout << queueArray[i] << "\n";
}//End of display()

int Queue::size()
{
	int retValue=0;

	if(!isEmpty())
		retValue = rear-front+1;

	return retValue;
}//End of size()

int main()
{
	Queue qu;

	try
	{
		cout << "Is queue empty : " << ((qu.isEmpty()) ? "True" : "False") << "\n";
		cout << "Is queue full : " << ((qu.isFull()) ? "True" : "False") << "\n";

		qu.enqueue(1);
		qu.enqueue(2);
		qu.enqueue(3);
		qu.enqueue(4);
		qu.enqueue(5);

		cout << "Queue Items :\n";
		qu.display();
		cout << "Front Item : " << qu.peek() << "\n";
		cout << "Total items : " << qu.size() << "\n";

		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Deleted Item : " << qu.dequeue() << "\n";
		cout << "Queue Items :\n";
		qu.display();

		qu.enqueue(6);

		cout << "Queue Items :\n";
		qu.display();

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()


