//Ex34.cpp : Write a function to find whether a linked list is palindrome or not.

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

		void reverse();
		bool isIdentical(SingleLinkedList &list);
		bool isPalindrome();


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

bool SingleLinkedList::isIdentical(SingleLinkedList &list)
{
	Node *p1, *p2;
	p1 = start;
	p2 = list.start;

	while(true)
	{
		if(p1==NULL && p2==NULL)
			return true;

		if(p1==NULL || p2==NULL)
			return false;

		if(p1->info != p2->info)
			return false;

		p1 = p1->link;
		p2 = p2->link ;
	}
}//End of isIdentical()

void SingleLinkedList::reverse()
{
	Node *prev, *ptr, *next;
	prev = NULL;
   	ptr = start;

	while(ptr!=NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;

}//End of reverse()

bool SingleLinkedList::isPalindrome()
{
	Node *slowP, *fastP, *prevslowP;  
	bool result;  
 
	if(start==NULL || start->link==NULL) //List empty or only one element
	   return true;

	prevslowP = slowP = fastP = start;

	while(fastP->link!=NULL && fastP->link->link!=NULL)
	{
		prevslowP = slowP;
		slowP = slowP->link;
		fastP = fastP->link->link;
	}

	SingleLinkedList list2;

	list2.start = slowP->link;

	if(fastP->link == NULL) //odd number of elements in the list
    {  
		list2.reverse(); //reverse the second half
		prevslowP->link = NULL; //node pointed by prevslowP is last node of first half, Middle element pointed by slowP will not be in any half
		result = isIdentical(list2); //compare the first half and second half
		list2.reverse(); //reverse second half to get the original order
		prevslowP->link = slowP; //Join first half with the middle element
		slowP->link = list2.start; //Join middle element with the second half
    }  
	else //even number of elements in the list
	{  
		list2.reverse(); //reverse the second half
		slowP->link = NULL; //node pointed by slowP is the last node of first half
		result = isIdentical(list2); //compare the first half and second half
		list2.reverse(); //reverse second half to get the original order
		slowP->link = list2.start; //Join first half and second half
	}

	return result;  
}//End of isPalindrome()

int main()
{
	SingleLinkedList list;

	//Create the List
	list.insertAtBeginning(10);
	list.insertAtBeginning(20);
	list.insertAtBeginning(30);
	list.insertAtBeginning(40);
	list.insertAtBeginning(30);
	list.insertAtBeginning(20);
	list.insertAtBeginning(10);

	cout << "List items :\n";
	list.display();

	if(list.isPalindrome())
		cout << "List is palindrome.\n";
	else
		cout << "List is not palindrome.\n";

	return 0;
}//End of main()
