//Ex21.cpp : Write a function to create a linked list that is union of two single linked lists.

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
		void insertAtEnd(int data);
		void unionLists(SingleLinkedList &list2, SingleLinkedList &list3);
	private:
		bool isPresent(int data);

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

void SingleLinkedList::insertAtEnd(int data)
{
	Node *ptr, *temp;

	temp = new Node(data);

	if(isEmpty())
		start = temp;
	else
	{
		ptr = start;
		while(ptr->link != NULL)
			ptr = ptr->link;

		ptr->link = temp;
	}
}//End of insertAtEnd()

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

bool SingleLinkedList::isPresent(int data)
{
	Node *ptr=start;

	while(ptr!=NULL)
	{
		if(ptr->info == data)
			return true;
		ptr=ptr->link;
	}

	return false;
}//End of isPresent()

void SingleLinkedList::unionLists(SingleLinkedList &list2, SingleLinkedList &list3)
{
	Node *ptr = start;

	while(ptr != NULL)
	{
		list3.insertAtEnd(ptr->info);			
		ptr=ptr->link;
	}

	ptr=list2.start;
	while(ptr!=NULL)
	{
		if(!isPresent(ptr->info) )	
			list3.insertAtEnd(ptr->info);			
		ptr=ptr->link;	
	}

}//End of unionLists()

int main()
{
	SingleLinkedList list1, list2, list3;

	//Create the List
	list1.insertAtEnd(10);
	list1.insertAtEnd(20);
	list1.insertAtEnd(30);
	list1.insertAtEnd(40);
	list1.insertAtEnd(50);
	list1.insertAtEnd(60);

	cout << "List1 items :\n";
	list1.display();

	//Create the List
	list2.insertAtEnd(10);
	list2.insertAtEnd(15);
	list2.insertAtEnd(30);
	list2.insertAtEnd(35);
	list2.insertAtEnd(40);
	list2.insertAtEnd(60);

	cout << "List2 items :\n";
	list2.display();

	list1.unionLists(list2,list3);
	cout << "Union of List1 and List2 :\n";
	list3.display();

	return 0;
}//End of main()


