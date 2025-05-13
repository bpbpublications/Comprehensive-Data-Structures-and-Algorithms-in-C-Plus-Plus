//Ex7.cpp : Write a program to swap adjacent elements of a double linked list by rearranging links.

#include<iostream>
using namespace std;

class Node
{
    public:
        int info;
        Node* prev;
        Node* next;

        Node(int data)
        {
            info = data;
            prev = NULL;
            next = NULL;
        }
};//End of class Node

class DoublyLinkedList
{
    private:
        Node* start;

    public:
		DoublyLinkedList();
		~DoublyLinkedList();
		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

        void swapAdjacent();
};//End of class DoublyLinkedList

DoublyLinkedList::DoublyLinkedList()
{
    start = NULL;
}//End of DoublyLinkedList()

DoublyLinkedList::~DoublyLinkedList()
{
	Node *ptr;

	while(start != NULL)
	{
		ptr = start->next;
		delete start;
		start = ptr;
	}
}//End of ~DoublyLinkedList()

bool DoublyLinkedList::isEmpty()
{
	return (start == NULL);
}//End of isEmpty()

void DoublyLinkedList::display()
{
	Node *ptr;

	if(!isEmpty())
	{
		ptr = start;
		while(ptr != NULL)
		{
			cout << ptr->info << " ";
			ptr = ptr->next;
		}
		cout << "\n";
	}
	else
		cout << "List is empty\n";
}//End of display()

void DoublyLinkedList::insertAtBeginning(int data)
{
	Node *temp;

	temp = new Node(data);
	if(!isEmpty())
	{
		temp->next = start;
		start->prev = temp;
	}

	start = temp;
}//End of insertAtBeginning()

void DoublyLinkedList::swapAdjacent()
{
	Node *p,*q;
	if(start==NULL || start->next==NULL) //List empty or only one element in the list
		return;
	
	p = start;
	while(p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		q->prev = p->prev;
		if(q->next != NULL)
			q->next->prev = p;
		q->next=p;
		if(p!=start)
			p->prev->next=q;
		else
			start=q;
		p->prev=q;
		if(p->next!=NULL)
			 p=p->next;
	}

}//End of swapAdjacent()

int main()
{
	DoublyLinkedList list;

	//Create the List
	list.insertAtBeginning(8);
	list.insertAtBeginning(7);
	list.insertAtBeginning(6);
	list.insertAtBeginning(5);
	list.insertAtBeginning(4);
	list.insertAtBeginning(3);
	list.insertAtBeginning(2);
	list.insertAtBeginning(1);

	cout << "List items :\n";
	list.display();

	list.swapAdjacent();

	cout << "List items after swaping adjacent elements using links :\n";
	list.display();

	return 0;
}//End of main()