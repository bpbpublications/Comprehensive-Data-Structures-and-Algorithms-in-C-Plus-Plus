//Ex13.cpp : Copy a queue Q1 to another queue Q2.

#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
        int info;
        Node *link;

        Node(int data)
        {
            info = data;
            link = NULL;
        }
};//End of class Node

class QueueL
{
    private:
		Node *front;
		Node *rear;

    public:
		QueueL();
		bool isEmpty();
		void enqueue(int data);
		int dequeue();
		int peek();
		void display();
		int size();
};//End of class QueueL

QueueL::QueueL()
{
	front = NULL;
	rear = NULL;
}//End of QueueL()

bool QueueL::isEmpty()
{
    return (front == NULL);
}//End of isEmpty()

void QueueL::enqueue(int data)
{
	Node *temp;

	temp = new Node(data);

	if(isEmpty()) //If queue is empty
		front = temp;
	else
		rear->link = temp;

	rear = temp;
}//End of enqueue()

int QueueL::dequeue()
{
	Node *temp;
	int retValue;

	if(isEmpty())
		throw exception("Queue is empty");
	else 
	{
		retValue = front->info;
		temp = front;
		front = front->link;

		delete temp;
	}

	return retValue;
}//End of dequeue()

int QueueL::peek()
{
	if(isEmpty())
		throw exception("Queue is empty");

	return front->info;
}//End of peek()

void QueueL::display()
{
	Node *ptr;

	if(!isEmpty())
	{
		ptr = front;
		while(ptr != NULL)
		{
			cout << ptr->info << "\n";
			ptr = ptr->link;
		}
	}
	else
		cout << "Queue is empty\n";
}//End of display()

int QueueL::size()
{
	Node* ptr;
	int count = 0;

	ptr = front;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}

	return count;
}//End of size()

int main()
{
	QueueL qu1, qu2;

	qu1.enqueue(1);
	qu1.enqueue(2);
	qu1.enqueue(3);
	qu1.enqueue(4);
	qu1.enqueue(5);

	cout << "Queue1 Items :\n";
	qu1.display();

	int size = qu1.size();

	for(int i=0; i<size; i++)
	{
		qu1.enqueue(qu1.peek());
		qu2.enqueue(qu1.peek());
		qu1.dequeue();
	}

	cout << "After copy queue1 items :\n";
	qu1.display();

	cout << "After copy queue2 items :\n";
	qu2.display();

	return 0;
}//End of main()
