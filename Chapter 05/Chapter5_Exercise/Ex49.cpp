//Ex49.cpp : Write a recursive function to print alternate nodes of a single linked list.

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
		
	private:
		void displayAlternateNodes(Node *ptr);
	public:
		SingleLinkedList();
		~SingleLinkedList();
		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

		void displayAlternateNodes();

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

void SingleLinkedList::displayAlternateNodes(Node *ptr)
{
	if(ptr==NULL)
		return;

	cout << ptr->info << " ";
	
	if(ptr->link!=NULL)
        displayAlternateNodes(ptr->link->link);
}//End of displayAlternateNodes()

void SingleLinkedList::displayAlternateNodes()
{
	if(!isEmpty())
	{
		displayAlternateNodes(start);
		cout << "\n";
	}
	else
		cout << "List is empty\n";
}//End of displayAlternateNodes()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(50);
	list.insertAtBeginning(40);
	list.insertAtBeginning(30);
	list.insertAtBeginning(20);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	cout << "List alternate items :\n";
	list.displayAlternateNodes();

	return 0;
}//End of main()
