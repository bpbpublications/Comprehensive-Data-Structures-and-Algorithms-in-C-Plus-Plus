//Ex23.cpp : Given a linked list L1, create two linked lists one having the even numbers of L1 and the other having the odd numbers 
//of L1. Don’t change the list L1.

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
		void insertAtEnd(int data);

		void evenOddList(SingleLinkedList &list2, SingleLinkedList &list3);

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

void SingleLinkedList::insertAtEnd(int data)
{
	Node *ptr, *temp;

	temp = new Node(data);

	if(isEmpty())
		start = temp;
	else
	{
		ptr = start;
		while(ptr->link != NULL)
			ptr = ptr->link;

		ptr->link = temp;
	}
}//End of insertAtEnd()

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

void SingleLinkedList::evenOddList(SingleLinkedList &list2, SingleLinkedList &list3)
{
	Node *p1 = start, *temp;

	while(p1 != NULL)
	{
		if((p1->info)%2 == 0) //Insert in even number list
			list2.insertAtEnd(p1->info);
		else	//Insert in odd number list
			list3.insertAtEnd(p1->info);

		p1 = p1->link;
	}

	start=NULL;

}//End of evenOddList()

int main()
{
	SingleLinkedList list1, list2, list3;

	//Create the List
	list1.insertAtEnd(1);
	list1.insertAtEnd(3);
	list1.insertAtEnd(4);
	list1.insertAtEnd(5);
	list1.insertAtEnd(6);
	list1.insertAtEnd(8);
	list1.insertAtEnd(9);
	list1.insertAtEnd(11);
	list1.insertAtEnd(12);
	list1.insertAtEnd(14);

	cout << "List1 items :\n";
	list1.display();

	list1.evenOddList(list2,list3);

	cout << "Even number list items :\n";
	list2.display();

	cout << "Odd number list items :\n";
	list3.display();

	return 0;
}//End of main()


