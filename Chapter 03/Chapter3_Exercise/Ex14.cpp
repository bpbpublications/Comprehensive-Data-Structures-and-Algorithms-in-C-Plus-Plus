//Ex14.cpp : Write a program to remove the last node of the list and insert it in the beginning, without changing info part of any node.

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

		void removeLastInsertAtBeginning();

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

void SingleLinkedList::removeLastInsertAtBeginning()
{
	Node *ptr;
	ptr = start;

	if(start==NULL || start->link==NULL ) //list empty or only one element in the list
		return;

	//ptr has to point to second last node
	while(ptr->link->link != NULL)
		ptr = ptr->link;

	ptr->link->link = start;
	start = ptr->link;
	ptr->link = NULL;

}//End of removeLastInsertAtBeginning()

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

	list.removeLastInsertAtBeginning();

	cout << "List items after removing last and inserting at beginning :\n";
	list.display();

	return 0;
}//End of main()
