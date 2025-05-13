//Ex31.cpp : Write a function to find the merge point (intersection point) of two single linked list.

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

		bool isEmpty();
		void display();
		void insertAtBeginning(int data);

		void setMergePoint(SingleLinkedList &list);
		int intersectionPoint(SingleLinkedList &list);

};//End of class SingleLinkedList

SingleLinkedList::SingleLinkedList()
{
	start = NULL;
}//End of SingleLinkedList()

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

void SingleLinkedList::setMergePoint(SingleLinkedList &list)
{
	list.start = start;
}//End of setMergePoint()

int SingleLinkedList::intersectionPoint(SingleLinkedList &list)
{
	Node *p, *q;
	int len1=0, len2=0, d;
	
	p = start;
	while(p != NULL) //Find length of first list
	{
		len1++;
		p = p->link;
	}

	p = list.start;
	while(p != NULL) //Find length of second list
	{
		len2++;
		p = p->link;
	}
	
	p = start;
	q = list.start;
		
	if(len1 > len2) //If first list is longer
	{
		d = len1-len2;	
		for(int i=1; i<=d; i++)
			p = p->link;
	}
	else if(len1 < len2) //If second list is longer
	{
		d = len2-len1;	
		for(int i=1; i<=d; i++)
			q = q->link;
	}

	while(p!=NULL && q!=NULL)
	{
		if(p == q)
			return p->info;	//Merge point found
		p = p->link;
		q = q->link;
	}

}//End of intersectionPoint()

int main()
{
	SingleLinkedList list1, list2;

	//Create the List1
	list1.insertAtBeginning(80);
	list1.insertAtBeginning(70);
	list1.insertAtBeginning(60);
	list1.insertAtBeginning(50);

	list1.setMergePoint(list2);

	list1.insertAtBeginning(40);
	list1.insertAtBeginning(30);
	list1.insertAtBeginning(20);
	list1.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	//Create the List2
	list2.insertAtBeginning(35);
	list2.insertAtBeginning(25);

	cout << "List2 items :\n";
	list2.display();

	cout << "Merge point of List1 and List2 is : " << list1.intersectionPoint(list2) << "\n";

	return 0;
}//End of main()
