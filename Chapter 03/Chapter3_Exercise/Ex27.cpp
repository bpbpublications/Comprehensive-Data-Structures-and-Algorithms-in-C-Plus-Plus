//Ex27.cpp : Write a function to split a single linked list into two halves.

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

		void split(SingleLinkedList &list);

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

void SingleLinkedList::split(SingleLinkedList &list)
{
	Node *slow, *fast;

	if(start->link == NULL) //only one element
	{
		cout << "Only one element, split is not possible.\n";
		return;
	}
	
	slow = fast = start;
	
	while(fast->link!=NULL && fast->link->link!=NULL)
	{
		slow = slow->link;
		fast = fast->link->link;
	}

	list.start = slow->link;
	slow->link = NULL;
}//End of split()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(80);
	list1.insertAtBeginning(70);
	list1.insertAtBeginning(60);
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	list1.split(list2);

	cout << "After splitting list1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()
