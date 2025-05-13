//Ex10.cpp : Write a function to move the smallest element to the beginning of a single linked list.

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

		void moveSmallestAtBeginning();

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

void SingleLinkedList::moveSmallestAtBeginning()
{
	Node *p,*q;
	int temp;

	if(start == NULL)
		return;
	
	p = start;
	q = start->link;
	while(q != NULL)
	{
		if(p->info > q->info )
		{
			temp = p->info;
			p->info = q->info;
			q->info = temp;
		}
		q = q->link;
	}
}//End of moveSmallestAtBeginning()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(7);
	list.insertAtBeginning(3);
	list.insertAtBeginning(6);
	list.insertAtBeginning(11);
	list.insertAtBeginning(9);
	list.insertAtBeginning(8);
	list.insertAtBeginning(1);
	list.insertAtBeginning(4);
	list.insertAtBeginning(5);
	list.insertAtBeginning(2);

	cout << "List items :\n";
	list.display();

	list.moveSmallestAtBeginning();

	cout << "List items after moving smallest at beginning :\n";
	list.display();

	return 0;
}//End of main()

