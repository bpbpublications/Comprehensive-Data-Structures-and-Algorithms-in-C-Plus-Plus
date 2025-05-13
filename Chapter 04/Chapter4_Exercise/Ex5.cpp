//Ex5.cpp : Write a program to implement 2 queues in a single array.

static const int maxSize = 6;

#include <iostream>
using namespace std;

class Queue
{
	private:
		int queueArray[maxSize];
		int frontA;
		int rearA;
		int frontB;
		int rearB;

	public:
		Queue();
		bool isEmptyA();
		bool isEmptyB();
		bool isFull();
		void enqueueA(int data);
		void enqueueB(int data);
		int dequeueA();
		int dequeueB();
		void displayA();
		void displayB();
};//End of class Queue

Queue::Queue()
{
	frontA = -1;
	rearA = -1;
	frontB = maxSize;
	rearB = maxSize;
}//End of Queue()

bool Queue::isEmptyA()
{
	return (frontA==-1);
}//End of isEmptyA()

bool Queue::isEmptyB()
{
	return (frontB == maxSize);
}//End of isEmptyB()

bool Queue::isFull()
{
	return (rearA == rearB-1);
}//End of isFull()

void Queue::enqueueA(int data)
{
	if(isFull())
		cout << "Queue Overflow\n";
	else
	{
		if(frontA == -1)
			frontA = 0;

		rearA = rearA+1;
		queueArray[rearA] = data;
	}
}//End of enqueueA()

void Queue::enqueueB(int data)
{
	if(isFull())
		cout << "Queue Overflow\n";
	else
	{
		if(frontB == maxSize)
			frontB = maxSize-1;

		rearB = rearB-1;
		queueArray[rearB] = data;
	}
}//End of enqueueB()

int Queue::dequeueA()
{
	if(isEmptyA())
		throw exception("Queue is empty");

	int retValue = queueArray[frontA++];

	if(frontA==rearA+1)
	{
		frontA = -1;
		rearA = -1;
	}

	return retValue;
}//End of dequeueA()

int Queue::dequeueB()
{
	if(isEmptyB())
		throw exception("Queue is empty");

	int retValue = queueArray[frontB--];

	if(frontB==rearB-1)
	{
		frontB = maxSize;
		rearB = maxSize;
	}

	return retValue;
}//End of dequeueB()

void Queue::displayA()
{
	cout << "FrontA = " << frontA << "	rearA = " << rearA << "\n";

	if(isEmptyA())
		cout << "Queue is empty\n";
	else
		for(int i=frontA; i<=rearA; i++)
			cout << queueArray[i] << "\n";
}//End of displayA()

void Queue::displayB()
{
	cout << "FrontB = " << frontB << "	rearB = " << rearB << "\n";

	if(isEmptyB())
		cout << "Queue is empty\n";
	else
		for(int i=frontB; i>=rearB; i--)
			cout << queueArray[i] << "\n";
}//End of displayB()

int main()
{
	Queue qu;

	try
	{
		//For Queue A
		qu.enqueueA(1);
		qu.enqueueA(2);
		qu.enqueueA(3);

		cout << "QueueA Items :\n";
		qu.displayA();

		cout << "QueueA deleted Item : " << qu.dequeueA() << "\n";
		cout << "QueueA Items :\n";
		qu.displayA();

		cout << "QueueA deleted Item : " << qu.dequeueA() << "\n";
		cout << "QueueA Items :\n";
		qu.displayA();

		cout << "QueueA deleted Item : " << qu.dequeueA() << "\n";
		cout << "QueueA Items :\n";
		qu.displayA();

		qu.enqueueA(4);
		qu.enqueueA(5);
		qu.enqueueA(6);
		cout << "QueueA Items :\n";
		qu.displayA();

		//For Queue B
		qu.enqueueB(7);
		qu.enqueueB(8);
		qu.enqueueB(9);

		cout << "QueueB Items :\n";
		qu.displayB();

		cout << "QueueB deleted Item : " << qu.dequeueB() << "\n";
		cout << "QueueB Items :\n";
		qu.displayB();

		cout << "QueueB deleted Item : " << qu.dequeueB() << "\n";
		cout << "QueueB Items :\n";
		qu.displayB();

		cout << "QueueB deleted Item : " << qu.dequeueB() << "\n";
		cout << "QueueB Items :\n";
		qu.displayB();

		qu.enqueueB(10);
		qu.enqueueB(11);
		qu.enqueueB(12);

		cout << "QueueB Items :\n";
		qu.displayB();

		//Now queue is full
		qu.enqueueB(14);

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()
