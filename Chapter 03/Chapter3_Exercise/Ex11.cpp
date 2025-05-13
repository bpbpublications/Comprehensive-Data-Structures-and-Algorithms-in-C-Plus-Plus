//Ex11.cpp : Write a function for deleting all the nodes from a single linked list which have a value N.

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

		void deleteNodes(int n);

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

void SingleLinkedList::deleteNodes(int n)
{
	Node *prev, *ptr;
	
	if(start==NULL)
		return;

	//Delete all the nodes that are at the beginning of the list and have value n
	while(start!=NULL && start->info==n)
	{
		ptr = start;
		start = start->link;
		delete ptr;
	}
	
	prev = ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info == n)
		{
			prev->link = ptr->link;
			delete ptr;
			ptr=prev->link;
		}
		else
		{
			prev = ptr;
			ptr = ptr->link;
		}
	}

}//End of deleteNodes()

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
	list.deleteNodes(5);

	cout << "List items after deleting the nodes having value " << n << " :\n";
	list.display();

	return 0;
}//End of main()

