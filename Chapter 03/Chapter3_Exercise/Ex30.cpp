//Ex30.cpp : Write a function to combine the alternate nodes of two null terminated single linked lists.

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

		void combineAlternateNodes(SingleLinkedList &list);

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

void SingleLinkedList::combineAlternateNodes(SingleLinkedList &list)
{
	Node *p1, *p2, *pnext;
	p1 = start;
	p2 = list.start;

	if(p1 == NULL) //If first list is empty
	{
		start = list.start;
		list.start = NULL;
		return;
	}

	if(p2==NULL) //If second list is empty
		return;

	while(p1->link!=NULL && p2!=NULL)
	{
		pnext = p1->link;
		p1->link = p2;
		p1 = pnext;
		pnext = p2->link;
		p2->link = p1;
		p2=pnext;
	}

	if(p1->link==NULL)
		p1->link = p2;

	list.start = NULL;
}//End of combineAlternateNodes()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List1
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	//Create the List2
	list2.insertAtBeginning(35);
	list2.insertAtBeginning(25);
	list2.insertAtBeginning(15);

	cout << "List2 items :\n";
	list2.display();

	list1.combineAlternateNodes(list2);

	cout << "After combining alternate nodes, list1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()
