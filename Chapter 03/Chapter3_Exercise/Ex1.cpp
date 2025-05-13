//Ex1.cpp : Write a function to count the number of occurrences of an element in a single linked list.

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

		int frequency(int data);

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

int SingleLinkedList::frequency(int data)
{
	Node* ptr;
	int count = 0;

	ptr = start;
	while(ptr != NULL)
	{
		if(data == ptr->info)
			count++;
		ptr = ptr->link;
	}

	return count;
}//End of frequency()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(45);
	list.insertAtBeginning(5);
	list.insertAtBeginning(35);
	list.insertAtBeginning(20);
	list.insertAtBeginning(5);
	list.insertAtBeginning(30);
	list.insertAtBeginning(10);
	list.insertAtBeginning(20);
	list.insertAtBeginning(5);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	int n = 5;
	cout << "Frequency of " << n << " : " << list.frequency(n) << "\n";

	return 0;
}//End of main()

