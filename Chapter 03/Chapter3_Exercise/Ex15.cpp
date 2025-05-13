//Ex15.cpp : Write a program to move a node n positions forward in a single linked list.

#include<iostream>
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

class SingleLinkedList
{
	private:
		Node *start;
		
	public:
		SingleLinkedList();
		~SingleLinkedList();
		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

		void moveNode(int nodeData, int n);

};//End of class SingleLinkedList

SingleLinkedList::SingleLinkedList()
{
	start = NULL;
}//End of SingleLinkedList()

SingleLinkedList::~SingleLinkedList()
{
	Node *ptr;
	while(start != NULL)
	{
		ptr = start->link;
		delete start;
		start = ptr;
	}
}//End of ~SingleLinkedList()

bool SingleLinkedList::isEmpty()
{
	return (start == NULL);
}//End of isEmpty()

void SingleLinkedList::insertAtBeginning(int data)
{
	Node *temp;

	temp = new Node(data);
	if(!isEmpty())
		temp->link = start;

	start = temp;
}//End of insertAtBeginning()

void SingleLinkedList::display()
{
	Node *ptr;

	if(!isEmpty())
	{
		ptr = start;
		while(ptr != NULL)
		{
			cout << ptr->info << " ";
			ptr = ptr->link;
		}
		cout << "\n";
	}
	else
		cout << "List is empty\n";
}//End of display()

void SingleLinkedList::moveNode(int nodeData, int n)
{
	Node *r,*p,*q;

	if(n <= 0)
		return;

	r = p = start;
	while(p != NULL)
	{
		if(p->info == nodeData)
			break;
		r = p;
		p = p->link;
	}

	if(p == NULL)
    {
		cout << nodeData << " does not exist.\n";
		return;
	}
	
	q = p;
	for(int i=1; i<=n; i++)
	{
		if(q->link == NULL)
		{	
			cout << "Cannot move " << n << " positions.\n";
			return;
		}
		q = q->link;
	}
	
	if(p != start)
		r->link = p->link;
	else
		start = start->link;

	p->link = q->link;
	q->link = p;

}//End of moveNode()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(80);
	list.insertAtBeginning(70);
	list.insertAtBeginning(60);
	list.insertAtBeginning(50);
	list.insertAtBeginning(40);
	list.insertAtBeginning(30);
	list.insertAtBeginning(20);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	int nodeData = 30;
	int n = 4;

	list.moveNode(nodeData,n);

	cout << "List items after moving node data " << nodeData << " for " << n << " positions.\n";
	list.display();

	return 0;
}//End of main()
