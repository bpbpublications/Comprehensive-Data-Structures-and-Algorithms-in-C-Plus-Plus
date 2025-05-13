//Ex6.cpp : Write a program to swap adjacent elements of a single linked list
//(i) by exchanging info part (ii) by rearranging links

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

		void swapAdjacentInfo();
		void swapAdjacent();

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

void SingleLinkedList::swapAdjacentInfo()
{
	Node *p, *q;
	int temp;

	if(start==NULL || start->link==NULL) //List empty or only one element in the list
		return;

	p = start;
	while(p!=NULL && p->link!=NULL)
	{
		q = p->link;
		temp = p->info;
		p->info = q->info;
		q->info = temp;
		p = q->link;
	}

}//End of swapAdjacentInfo()

void SingleLinkedList::swapAdjacent()
{
	Node *r,*p,*q;
	if(start==NULL || start->link==NULL) //List empty or only one element in the list
		return;

	r = p = start;
	while(p->link != NULL)
	{
		q = p->link;
		p->link = q->link;
		q->link = p;

		if(p != start)
			r->link = q;
		else
			start = q;
		r = p;

		if(p->link != NULL)
			p = p->link;
	}

}//End of swapAdjacent()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(8);
	list1.insertAtBeginning(7);
	list1.insertAtBeginning(6);
	list1.insertAtBeginning(5);
	list1.insertAtBeginning(4);
	list1.insertAtBeginning(3);
	list1.insertAtBeginning(2);
	list1.insertAtBeginning(1);

	cout << "List1 items :\n";
	list1.display();

	list1.swapAdjacentInfo();

	cout << "List1 items after swaping adjacent elements using info :\n";
	list1.display();

	//Create the List
	list2.insertAtBeginning(8);
	list2.insertAtBeginning(7);
	list2.insertAtBeginning(6);
	list2.insertAtBeginning(5);
	list2.insertAtBeginning(4);
	list2.insertAtBeginning(3);
	list2.insertAtBeginning(2);
	list2.insertAtBeginning(1);

	cout << "List2 items :\n";
	list2.display();

	list2.swapAdjacent();

	cout << "List2 items after swaping adjacent elements using links :\n";
	list2.display();

	return 0;
}//End of main()
