//Ex8.cpp : Write a program to swap the first and last elements of a single linked list
//(i) by exchanging info part (ii) by rearranging links.

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

		void swapFirstLastInfo();
		void swapFirstLast();

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

void SingleLinkedList::swapFirstLastInfo()
{
	Node *ptr = start;
	int temp;

	if(ptr==NULL || ptr->link==NULL) //List empty or ony one element in the list
		return;

	while(ptr->link != NULL)
		ptr = ptr->link;

	//Now ptr points to last node
	temp = start->info;
	start->info = ptr->info;
	ptr->info = temp;
}//End of SwapFirstLastInfo()

void SingleLinkedList::swapFirstLast()
{
	Node *ptr = start, *psave;
	if(ptr==NULL || ptr->link==NULL) //List empty or only one element in the list
		return;

	if(ptr->link->link == NULL) //only two elements
	{
		ptr->link->link = start;
		start = ptr->link;
		ptr->link = NULL;
		return;
	}
	
	while(ptr->link->link != NULL)
		ptr = ptr->link;
	
	//Now p points to second last node
	ptr->link->link = start->link;
	psave = ptr->link;
	ptr->link = start;
	ptr->link->link=NULL;  
	start = psave;

}//End of swapFirstLast()

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

	list1.swapFirstLastInfo();

	cout << "List1 items after swaping first and last elements using info :\n";
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

	list2.swapFirstLast();

	cout << "List2 items after swaping first and last elements using links :\n";
	list2.display();

	return 0;
}//End of main()


