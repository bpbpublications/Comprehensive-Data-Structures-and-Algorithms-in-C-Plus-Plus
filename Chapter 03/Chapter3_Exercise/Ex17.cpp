// Ex17.cpp : Write functions to insert a node just before and just after a node pointed to by a pointer p, without using the 
//pointer start.

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

		void insertAfterBefore(int nodeData, int data);

	private:
		void insertAfter(Node *ptr, int data);
		void insertBefore(Node *ptr, int data);

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

void SingleLinkedList::insertAfter(Node *ptr, int data)
{
	Node *temp;
	temp = new Node(data);
	temp->link = ptr->link;
	ptr->link = temp;
}//End of insertAfter()

void SingleLinkedList::insertBefore(Node *ptr, int data)
{
	Node *temp;
	temp = new Node(ptr->info);
	temp->link = ptr->link;
	ptr->link = temp;
	ptr->info=data;
}//End of insertBefore()

void SingleLinkedList::insertAfterBefore(int nodeData, int data)
{
	Node* ptr;

	ptr = start;
	while(ptr != NULL)
	{
		if(nodeData == ptr->info)
			break;
		ptr = ptr->link;
	}

	if(ptr == NULL)
		cout << "Node data " << nodeData << " does not exist.\n";
	else
	{
		insertAfter(ptr,data);
		insertBefore(ptr,data);
	}

}//End of insertAfterBefore()

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

	int nodeData = 50, data = 45;
	list.insertAfterBefore(nodeData,data);

	cout << "List items after inserting after, before " << nodeData << " node value " << data << " :\n";
	list.display();

	return 0;
}//End of main()
