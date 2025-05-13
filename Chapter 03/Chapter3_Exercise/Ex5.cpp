//Ex5.cpp : Given a linked list L, write a function to create a single linked list that is reverse of the list L. For example if the 
//list L is 1->2->3->4->5 then the new list should be 5->4->3->2->1. The list L should remain unchanged.

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

		void createReverse(SingleLinkedList &list);

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

void SingleLinkedList::createReverse(SingleLinkedList &list)
{
	Node *ptr;
	
	if(start == NULL)
		return;
   	
	ptr = start;
	list.insertAtBeginning(ptr->info);
	ptr = ptr->link;

	while(ptr != NULL)
	{
		list.insertAtBeginning(ptr->info);
		ptr = ptr->link;
	}

}//End of createReverse()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	list1.createReverse(list2);

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()


