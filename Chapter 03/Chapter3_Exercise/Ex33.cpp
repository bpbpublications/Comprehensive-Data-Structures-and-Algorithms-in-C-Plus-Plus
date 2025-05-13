//Ex33.cpp : Write a function to add two numbers represented by doubly linked lists. Each node of the list can store 4 digits of the 
//given number.

#include<iostream>
#include<string>
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
		void insertAtEnd(int data);

		void createList(string num);
		void displayNumber();
		void addNumberList(DoublyLinkedList &list2, DoublyLinkedList &list3);
        
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

void DoublyLinkedList::insertAtEnd(int data)
{
	Node *ptr, *temp;

	temp = new Node(data);

	if(isEmpty())
		start = temp;
	else
	{
		ptr = start;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = temp;
		temp->prev = ptr;
	}
}//End of insertAtEnd()

void DoublyLinkedList::createList(string str)
{
	int i, j, num, x=0;
	char temp[100];

	i = str.length()-1;

	while(i != -1)
	{
		if(i < 3)
		{
			j = i;	
			x = i+1;
		}
		else
			j = 3;

		while(j!=-1 && i!=-1)
		{
			temp[j] = str[i];
			j--;
			i--;
		}
		
		if(x == 0)
			temp[4]='\0';
		else
			temp[x]='\0';
		sscanf(temp, "%d",&num);

		insertAtEnd(num);
	}//End of while

}//End of createList()

void DoublyLinkedList::displayNumber()
{
	Node *ptr;
	int d, num;

	if(start == NULL)
	{
		cout << "List is empty\n";
		return;
	}

	ptr = start;
	while(ptr->next != NULL)
		ptr = ptr->next;
	
	while(ptr != NULL)
	{
		if(ptr->next != NULL)
		{
			//If number is of 3 digits display 1 zero, if 2 digits display 2 zeros, if 1 digit display 3 zeros
			num = ptr->info;		
			d = 1;
			while(num/10 != 0)
			{
				d++;	
				num /= 10;
			}

			if(d == 1)
				cout << "000";
			else if(d == 2)
				cout << "00";
			else if(d == 3)
				cout << "0";
		}

		cout << ptr->info;
		ptr = ptr->prev;
	}//End of while

	cout << "\n";

}//End of displayNumber()

void DoublyLinkedList::addNumberList(DoublyLinkedList &list2, DoublyLinkedList &list3)
{
	int carry, total, num;
	Node *p, *q;
	
	carry = 0;
	p = start;
	q = list2.start;
	
	while(p!=NULL && q!=NULL)
	{
		total = p->info + q->info + carry;
		num = total % 10000;
		carry = total / 10000;
		list3.insertAtEnd(num);
		p = p->next;
		q = q->next;
	}
	while(p != NULL)
	{
		total = p->info + carry;
		num = total % 10000;
		carry = total / 10000;
		list3.insertAtEnd(num);
		p = p->next;
	}
	
	while(q != NULL)
	{
		total = q->info + carry;
		num = total % 10000;
		carry = total / 10000;
		list3.insertAtEnd(num);
		q = q->next;
	}

	if(carry == 1)
		list3.insertAtEnd(num);

}//End of addNumberList()

int main()
{
	DoublyLinkedList list1, list2, list3;

	//Create the List
	string str1 = "23156782913287";
	list1.createList(str1);

	cout << "List1 :\n";
	list1.display();
	cout << "List1 number :\n";
	list1.displayNumber();

	//Create the List
	string str2 = "1";
	list2.createList(str2);

	cout << "List2 :\n";
	list2.display();
	cout << "List2 number :\n";
	list2.displayNumber();

	list1.addNumberList(list2,list3);

	cout << "List3 :\n";
	list3.display();
	cout << "List3 number :\n";
	list3.displayNumber();

	return 0;
}//End of main()
