// Ex18.cpp : Write a function to remove duplicates from a sorted single linked list.

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

		void removeDuplicates();

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

void SingleLinkedList::removeDuplicates()
{
	Node *ptr, *duplicate;

	if(start==NULL)
		return;

	ptr=start;

	while(ptr->link != NULL)
	{
		if(ptr->info == ptr->link->info)
		{
			duplicate = ptr->link;
			ptr->link = ptr->link->link;
			delete duplicate;
		}
		else
			ptr = ptr->link;
	}

}//End of removeDuplicates()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(80);
	list.insertAtBeginning(50);
	list.insertAtBeginning(50);
	list.insertAtBeginning(50);
	list.insertAtBeginning(40);
	list.insertAtBeginning(20);
	list.insertAtBeginning(20);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	list.removeDuplicates();

	cout << "List items after removing duplicates :\n";
	list.display();

	return 0;
}//End of main()
