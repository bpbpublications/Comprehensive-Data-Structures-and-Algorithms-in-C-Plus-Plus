//Ex2.cpp : Write a function to find the smallest and largest element of a single linked list.

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

		int smallest();
		int largest();


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

int SingleLinkedList::smallest()
{
	Node* ptr;
	int small = start->info;

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info < small)
			small = ptr->info;
		ptr = ptr->link;
	}

	return small;
}//End of smallest()

int SingleLinkedList::largest()
{
	Node* ptr;
	int large = start->info;

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info > large)
			large = ptr->info;
		ptr = ptr->link;
	}

	return large;
}//End of largest()

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

	cout << "Smallest element : " << list.smallest() << "\n";
	cout << "Largest element : " << list.largest() << "\n";

	return 0;
}//End of main()

