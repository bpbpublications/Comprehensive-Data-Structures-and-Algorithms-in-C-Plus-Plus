//Ex22.cpp : Given a list L1, delete all the nodes having negative numbers in info part and insert them into list L2 and all the 
//nodes having positive numbers into list L3. No new nodes should be allocated.

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

		void positiveNegativeList(SingleLinkedList &list2, SingleLinkedList &list3);

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

void SingleLinkedList::positiveNegativeList(SingleLinkedList &list2, SingleLinkedList &list3)
{
	Node *p1 = start, *p2 = list2.start, *p3 = list3.start;

	while(p1 != NULL)
	{
		if((p1->info) < 0) //Insert in negative number list
		{
			if(list2.start == NULL)
				p2 = list2.start = p1;
			else
			{
				p2->link = p1;
				p2 = p2->link;
			}
		}
		else	//Insert in positive number list
		{
			if(list3.start == NULL)
				p3 = list3.start = p1;
			else
			{
				p3->link = p1;
				p3 = p3->link;
			}
		}
		p1 = p1->link;
	}

	if(p2 != NULL)
		p2->link = NULL;
	if(p3 != NULL)
		p3->link = NULL;
	start=NULL;

}//End of positiveNegativeList()

int main()
{
	SingleLinkedList list1, list2, list3;

	//Create the List
	list1.insertAtBeginning(95);
	list1.insertAtBeginning(-90);
	list1.insertAtBeginning(80);
	list1.insertAtBeginning(70);
	list1.insertAtBeginning(-60);
	list1.insertAtBeginning(50);
	list1.insertAtBeginning(40);
	list1.insertAtBeginning(-30);
	list1.insertAtBeginning(-20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	list1.positiveNegativeList(list2,list3);

	cout << "Negative number list items :\n";
	list2.display();

	cout << "Positive number list items :\n";
	list3.display();

	return 0;
}//End of main()
