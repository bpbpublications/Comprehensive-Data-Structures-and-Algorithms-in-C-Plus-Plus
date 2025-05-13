//Ex25.cpp : Write a function to get the nth node from the end of a single linked list, without counting the elements or reversing 
//the list.

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

		int getNthNode(int n);

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

int SingleLinkedList::getNthNode(int n)	
{
	Node *p1,*p2;

	if(start == NULL)
		return NULL;

	p1 = p2 = start;
  
	for(int i=0; i<n; i++) //Move the pointer p1 n times
	{
		if(p1 == NULL)
			throw exception("List is smaller.");

		p1 = p1->link;
	}
  
	while(p1 != NULL) //Move both pointers till p1 becomes NULL
	{
		p1 = p1->link;
		p2 = p2->link;
	}

	return p2->info;	
}//End of getNthNode()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(80);
	list.insertAtBeginning(70);
	list.insertAtBeginning(60);
	list.insertAtBeginning(50);
	list.insertAtBeginning(40);
	list.insertAtBeginning(30);
	list.insertAtBeginning(20);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	int n = 4;
	try
	{
		cout << "Node number " << n << " from end of list : " << list.getNthNode(n) << "\n";
	}
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()
