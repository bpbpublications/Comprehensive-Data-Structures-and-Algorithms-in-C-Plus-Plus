//Ex11.cpp : Write a function to sort a linked list using insertion sort.

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

		void insertionSort();

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

void SingleLinkedList::insertionSort()
{
	Node *p1,*p2,*q;
	Node *last; //last points to last node of sorted part

	if(start==NULL)
		return;

	last = start; //Initially only first node is in the sorted part
    while(last->link!=NULL) 
	{
			q=last->link; //q points to the node that is to be inserted
			if(q->info < start->info) //If item to be inserted is less than first element of list then insert it at the begining and change start
			{
				last->link = q->link;
				q->link = start;
				start = q;
			}
			else //start searching from the beginning of the list
			{ 
				p1=start;
				p2=start->link;
				while(q->info > p2->info)
				{
					p1=p2;
					p2=p2->link;
				}
				if(q==p2) //If item to be inserted is at its proper place, then make last point to it
					last=q;
				else //insert the node at proper place
				{
					last->link = q->link;
					q->link = p2;
					p1->link = q;
				}
			}//End of else
	}//End of while

}//End of insertionSort()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(40);
	list.insertAtBeginning(30);
	list.insertAtBeginning(50);
	list.insertAtBeginning(10);
	list.insertAtBeginning(20);

	cout << "Unsorted list is :\n";
	list.display();

	list.insertionSort();
	cout << "Sorted list is :\n";
	list.display();

	return 0;
}//End of main()
