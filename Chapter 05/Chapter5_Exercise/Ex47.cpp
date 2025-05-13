//Ex47.cpp : Write a recursive function to check if two linked lists are identical. Two lists are identical if they have same 
//number of elements and the corresponding elements in both lists are same.

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
		
	private:
		bool isIdentical(Node *ptr1, Node *ptr2);
	public:
		SingleLinkedList();
		~SingleLinkedList();
		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

		bool isIdentical(SingleLinkedList &list2);

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

bool SingleLinkedList::isIdentical(Node *ptr1, Node *ptr2)
{
		if((ptr1==NULL) && (ptr2==NULL))  
			return true;
		if((ptr1==NULL) || (ptr2==NULL))
			return false;
		if(ptr1->info != ptr2->info)
			return false;

		return isIdentical(ptr1->link, ptr2->link);
}//End of isIdentical()

bool SingleLinkedList::isIdentical(SingleLinkedList &list2)
{
	Node *ptr1 = start;
	Node *ptr2 = list2.start;

	return isIdentical(start, list2.start);
}//End of isIdentical()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	//Create the List
	list2.insertAtBeginning(50);
	list2.insertAtBeginning(40);
	list2.insertAtBeginning(30);
	list2.insertAtBeginning(20);
	list2.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	if(list1.isIdentical(list2))
		cout << "List1 and List2 are identical.\n";
	else
		cout << "List1 and List2 are not identical.\n";

	return 0;
}//End of main()
