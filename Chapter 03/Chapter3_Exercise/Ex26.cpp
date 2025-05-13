//Ex26.cpp : Write a function to find out the middle node of a single linked list without counting all the elements of the list.

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

		int findMiddle();

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

int SingleLinkedList::findMiddle()
{
	Node *slow, *fast;

	if(start->link == NULL) //only one node
		return start->info;

	slow = fast = start;
	
	//while(fast!=NULL && fast->link!=NULL) //this condition gives (n/2+1)th as the middle node in case of even nodes
	while(fast->link!=NULL && fast->link->link!=NULL) //this condition gives (n/2)th as the middle node in case of even nodes
	{
		slow = slow->link;
		fast = fast->link->link;
	}

	return slow->info;

}//End of findMiddle()

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

	cout << "Middle node is : " << list.findMiddle() << "\n";

	return 0;
}//End of main()
