//Ex4.cpp : Write a function to create a copy of a single linked list.

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

		void copy(SingleLinkedList &list);

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

void SingleLinkedList::copy(SingleLinkedList &list)
{
	struct node *startCopy=NULL;
	Node *ptr1, *ptr2, *temp;
	
	if(start == NULL)
		return;
   	
	ptr1=start;
	temp = new Node(ptr1->info);
	ptr2 = list.start = temp;
	ptr1 = ptr1->link;

	while(ptr1 != NULL)
	{
		temp = new Node(ptr1->info);
		ptr2->link = temp;
		ptr2 = temp;
		ptr1 = ptr1->link;
	}

	ptr2->link=NULL;

}//End of copy()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	//Copy list1 items to list2
	list1.copy(list2);

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()


