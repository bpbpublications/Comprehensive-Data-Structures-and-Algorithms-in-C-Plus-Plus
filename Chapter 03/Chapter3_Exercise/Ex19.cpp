//Ex19.cpp : Write a function to remove duplicates from an unsorted single linked list.

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
	Node *ptr1, *ptr2, *duplicate;

	ptr1=start; 
   
	while(ptr1 != NULL) 
	{ 
		ptr2 = ptr1; 
		while(ptr2->link != NULL) 
		{ 
			if(ptr1->info == ptr2->link->info) 
			{ 
				duplicate = ptr2->link; 
				ptr2->link = ptr2->link->link; 
				delete duplicate;
			} 
			else 
				ptr2 = ptr2->link; 
		} 
		ptr1 = ptr1->link; 
  } 
}//End of removeDuplicates()

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

	list.removeDuplicates();

	cout << "List items after removing duplicates :\n";
	list.display();

	return 0;
}//End of main()
