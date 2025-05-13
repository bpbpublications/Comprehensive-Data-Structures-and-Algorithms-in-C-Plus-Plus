//Ex14.cpp : Implement a data structure that supports stack push and pop operations and returns the minimum element.

#include <iostream>
using namespace std;

class Node
{
    public:
        int info;
		int min;
        Node *link;

        Node(int data, int minimum)
        {
            info = data;
			min = minimum;
            link = NULL;
        }
};//End of class Node

class StackL
{
    private:
        Node *top;

    public:
		StackL();
        bool isEmpty();
		void push(int data);
		int pop();
		int peek();
		void display();
		int size();
		int min();
};//End of class StackL

StackL::StackL()
{ 
	top = NULL;
}//End of StackL()

bool StackL::isEmpty()
{
    return (top == NULL);
}//End of isEmpty()

void StackL::push(int data)
{
	Node *temp;
	int min;

	if(top==NULL || top->min>data)
		min = data;
	else
			min = top->min;

	temp = new Node(data, min);
	if(!isEmpty())
		temp->link = top;

	top = temp;
}//End of push()

int StackL::pop()
{
	Node *temp;
	int retValue;

	if(isEmpty())
		throw exception("Stack is empty");
	else 
	{
		retValue = top->info;
		temp = top;
		top = top->link;

		delete temp;
	}

	return retValue;
}//End of pop()

int StackL::peek()
{
	if(isEmpty())
		throw exception("Stack is empty");

	return top->info;
}//End of peek()

void StackL::display()
{
	Node *ptr;

	if(!isEmpty())
	{
		ptr = top;
		while(ptr != NULL)
		{
			cout << ptr->info << "\n";
			ptr = ptr->link;
		}
	}
	else
		cout << "Stack is empty\n";

}//End of display()

int StackL::size()
{
	Node *ptr;
	int count = 0;

	ptr = top;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}

	return count;
}//End of size()

int StackL::min()
{
	if(isEmpty())
		throw exception("Stack is empty");

	return top->min;
}//End of min()

int main()
{
	StackL st;

	try
	{
		st.push(20);
		st.push(10);
		st.push(8);
		st.push(30);
		st.push(40);

		cout << "Stack Items : \n";
		st.display();

		cout << "Minimum item in stack : " << st.min() << "\n";

	}//End of try
	catch(exception e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}//End of main()
