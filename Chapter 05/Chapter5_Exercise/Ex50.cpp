//Ex50.cpp : Write a recursive function to delete a node from a single linked list.

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
		Node* del(Node *p, int data);
	public:
		SingleLinkedList();
		~SingleLinkedList();
		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

		void del(int data);

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

Node* SingleLinkedList::del(Node *ptr, int data)
{
	Node *temp;

	if(ptr == NULL)
		return NULL;

	if(ptr->info == data)
	{
		temp = ptr->link;
		delete ptr;
		return temp;
	}
	ptr->link = del(ptr->link, data);

	return ptr;
}//End of del()

void SingleLinkedList::del(int data)
{
	if(!isEmpty())
		start = del(start, data);
	else
		cout << "List is empty\n";
}//End of del()

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

	list.del(30);

	cout << "List items after deleting 30 :\n";
	list.display();

	return 0;
}//End of main()
