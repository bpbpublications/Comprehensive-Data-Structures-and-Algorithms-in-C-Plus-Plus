//Ex24.cpp : Write a function to swap right and left children of a binary tree i.e. all right children become left children and 
//vice versa. The new tree is the mirror image of the original tree.

#include<iostream>
using namespace std;

class Node
{
	public:
		int info;
		Node *lchild;
		Node *rchild;

		Node(int key)
		{
			info = key;
			lchild = NULL;
			rchild = NULL;
		}
};//End of class Node

class BinaryTree
{
	public:
		Node *root;

	private:
		void display(Node *ptr, int level);
		void destroy(Node *ptr);
		void swapChildren(Node *ptr);

	public:
		BinaryTree();
		~BinaryTree();

		void display();
		void swapChildren();
};//End of class BinaryTree

BinaryTree::BinaryTree()
{
	root = NULL;
}//End of BinaryTree()

BinaryTree::~BinaryTree()
{
	destroy(root);
	root = NULL;
}//End of ~BinaryTree()

void BinaryTree::destroy(Node *ptr)
{
	if(ptr == NULL)
		return;
	destroy(ptr->lchild);
	destroy(ptr->rchild);

	delete ptr;
}//End of destroy()

void BinaryTree::display(Node *ptr, int level)
{
	if(ptr == NULL)
		return;

	display(ptr->rchild, level+1);
	cout << "\n";

	for(int i=0; i<level; i++)
		cout << "    ";
	cout << ptr->info;

	display(ptr->lchild, level+1);
}//End of display()

void BinaryTree::display()
{
	display(root, 0);
}//End of display()

void BinaryTree::swapChildren(Node *ptr)
{ 
	Node* temp;

	if (ptr==NULL) 
		return;

	swapChildren(ptr->lchild); 
	swapChildren(ptr->rchild);

    temp = ptr->lchild; 
    ptr->lchild = ptr->rchild; 
    ptr->rchild = temp; 
}//End of swapChildren()

void BinaryTree::swapChildren()
{
	swapChildren(root);
}//End of swapChildren()

int main()
{
	BinaryTree bt;

	//Create the Binary Tree
	bt.root = new Node(32);
	bt.root->lchild = new Node(43);
	bt.root->rchild = new Node(25);
	bt.root->rchild->lchild = new Node(65);
	bt.root->rchild->rchild = new Node(14);
	bt.root->lchild->rchild = new Node(16);

	cout << "Binary Tree :\n";
	bt.display();
	cout << "\n";

	bt.swapChildren();

	cout << "After swap right and left, Binary Tree :\n";
	bt.display();
	cout << "\n";

	return 0;
}//End of main()
