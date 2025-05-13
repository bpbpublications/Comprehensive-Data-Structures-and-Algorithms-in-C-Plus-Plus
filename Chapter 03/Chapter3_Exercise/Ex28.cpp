//Ex28.cpp : Write a function to split a single linked list into two lists at a node containing the given information.

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

		void split(int nodeData, SingleLinkedList &list);

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

void SingleLinkedList::split(int nodeData, SingleLinkedList &list)
{
	Node *ptr = start;
	
	while(ptr != NULL)
	{
		if(ptr->info == nodeData)
			break;
		ptr = ptr->link;
	}

	if(ptr == NULL)
    {
		cout << nodeData << " is not in the list.\n";
		return;
	}

	list.start = ptr->link;
	ptr->link = NULL;

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

	int nodeData = 30;
	list1.split(nodeData, list2);

	cout << "After splitting list1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()
