// Ex16.cpp : Write a function to delete a node from a single linked list. The only information we have is a pointer to the node 
//that has to be deleted.

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

		void deleteNode(int data);
	
	private:
		void deleteNode(Node *ptr);

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

void SingleLinkedList::deleteNode(Node *ptr)
{
	Node *temp;

	if(ptr->link==NULL)	//If ptr points to last node
	{
		cout << "Can not delete last node\n";
		return;
	}

	ptr->info = ptr->link->info;
	temp = ptr->link;
	ptr->link = ptr->link->link;

	delete temp;
}//End of deleteNode()

void SingleLinkedList::deleteNode(int nodeData)
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
		deleteNode(ptr);

}//End of deleteNode()

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

	int nodeData = 50;
	list.deleteNode(nodeData);

	cout << "List items after deleting node with value " << nodeData << " :\n";
	list.display();

	return 0;
}//End of main()

