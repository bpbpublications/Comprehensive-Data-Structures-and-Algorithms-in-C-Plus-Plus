//Ex29.cpp : Write a function to split a single linked list into two lists such that the alternate nodes (even numbered nodes) go 
//to a new list.

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

		void alternateSplit(SingleLinkedList &list);

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

void SingleLinkedList::alternateSplit(SingleLinkedList &list)
{
	Node *prev,*ptr;
	
	if(start == NULL)
		return;
	
	list.start = start->link;
	
	prev = start;
	ptr = start->link;
	
	while(ptr != NULL)
	{
		prev->link = ptr->link;
		prev = prev->link;

		if(prev == NULL)
            ptr->link = NULL;
		else
			ptr->link = prev->link;
		ptr = ptr->link;
	}

}//End of alternateSplit()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(80);
	list1.insertAtBeginning(70);
	list1.insertAtBeginning(60);
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	list1.alternateSplit(list2);

	cout << "After alternate splitting list1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	return 0;
}//End of main()
