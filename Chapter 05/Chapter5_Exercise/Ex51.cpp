//Ex51.cpp : Write a recursive function to insert a node in a sorted single linked list.

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

class SortedLinkedList
{
	private:
		Node *start;
		Node* insert(Node *ptr, int data);
	public:
		SortedLinkedList();
		~SortedLinkedList();

		bool isEmpty();
		void display();
		void insert(int data);

};//End of class SortedLinkedList

SortedLinkedList::SortedLinkedList()
{
	start = NULL;
}//End of SortedLinkedList()

SortedLinkedList::~SortedLinkedList()
{
	Node *ptr;
	while(start != NULL)
	{
		ptr = start->link;
		delete start;
		start = ptr;
	}
}//End of ~SortedLinkedList()

bool SortedLinkedList::isEmpty()
{
	return (start == NULL);
}//End of isEmpty()

void SortedLinkedList::display()
{
	Node *ptr;

	if(!isEmpty())
	{
		ptr = start;
		while(ptr != NULL)
		{
			cout << ptr->info << "\n";
			ptr = ptr->link;
		}
	}
	else
		cout << "List is empty\n";
}//End of display()

Node* SortedLinkedList::insert(Node *ptr, int data)
{
	Node *temp;

	if(ptr == NULL || data < ptr->info )
	{
		temp = new Node(data);
		temp->link = ptr;
		return temp;
	}

	ptr->link = insert(ptr->link, data);

	return ptr;
}//End of insert()

void SortedLinkedList::insert(int data)
{
	start = insert(start, data);
}//End of insert()

int main()
{
	SortedLinkedList list;

	list.insert(10);
	list.insert(20);
	list.insert(50);
	list.insert(40);
	list.insert(30);

	cout << "List Items :\n";
	list.display();

	return 0;
}//End of main()
