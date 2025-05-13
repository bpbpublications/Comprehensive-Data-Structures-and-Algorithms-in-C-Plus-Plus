//Ex24.cpp : Write a function to delete alternate nodes (even numbered nodes) from a single linked list.

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

		void deleteAlternate();

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

void SingleLinkedList::deleteAlternate()
{
	Node *ptr, *prev;
	
	if(start == NULL)
		return;
	
	prev = start;
	ptr = start->link;

	while(prev!=NULL &&  ptr!=NULL)
	{
		prev->link = ptr->link;
		delete ptr;
		prev = prev->link;
		if(prev != NULL)
            ptr = prev->link;
	}

}//End of deleteAlternate()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(10);
	list.insertAtBeginning(9);
	list.insertAtBeginning(8);
	list.insertAtBeginning(7);
	list.insertAtBeginning(6);
	list.insertAtBeginning(5);
	list.insertAtBeginning(4);
	list.insertAtBeginning(3);
	list.insertAtBeginning(2);
	list.insertAtBeginning(1);

	cout << "List items :\n";
	list.display();

	list.deleteAlternate();

	cout << "List items after deleting alternate nodes :\n";
	list.display();

	return 0;
}//End of main()
