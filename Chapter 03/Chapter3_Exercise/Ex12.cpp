//Ex12.cpp : Given a single linked list L1 which is sorted in ascending order, and another single linked list L2 which is not 
//sorted, write a function to print the elements of second list according to the first list.

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

		void printList(SingleLinkedList &list);

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

void SingleLinkedList::printList(SingleLinkedList &list)
{
	Node *ptr1, *ptr2;
	int i = 1;

	ptr1 = start;
	ptr2 = list.start;
	
	if(ptr1==NULL || ptr2==NULL)
		return;
		
	while(ptr1 != NULL)
	{
		while(i < ptr1->info)
		{
			ptr2 = ptr2->link;
			if(ptr2 == NULL)
			{
				cout << "\nError : Less than " << ptr1->info << " elements\n";
				return;
			}
			i++;
		}
		cout << ptr2->info << " ";
		ptr1 = ptr1->link;
	}
	cout << "\n";
}/*End of printList()*/

int main()
{
	SingleLinkedList list1, list2;

	//Create the List
	list1.insertAtBeginning(8);
	list1.insertAtBeginning(7);
	list1.insertAtBeginning(5);
	list1.insertAtBeginning(2);
	list1.insertAtBeginning(1);

	//Create the List
	list2.insertAtBeginning(80);
	list2.insertAtBeginning(70);
	list2.insertAtBeginning(60);
	list2.insertAtBeginning(50);
	list2.insertAtBeginning(40);
	list2.insertAtBeginning(30);
	list2.insertAtBeginning(20);
	list2.insertAtBeginning(10);

	cout << "List1 items :\n";
	list1.display();

	cout << "List2 items :\n";
	list2.display();

	cout << "List2 items from list1 positions :\n";
	list1.printList(list2);


	return 0;
}//End of main()


