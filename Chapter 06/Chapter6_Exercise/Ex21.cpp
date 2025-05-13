//Ex21.cpp : Write a function that displays all root to leaf paths in a binary tree.

#include<iostream>
using namespace std;

static const int maxSize = 30;

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

class BinarySearchTree
{
	private:
		Node *root;

	private:
		void display(Node *ptr, int level);
		void destroy(Node *ptr);
		void displayPaths(Node* ptr, int path[], int n);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		void displayPaths();
};//End of class BinarySearchTree

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}//End of BinarySearchTree()

BinarySearchTree::~BinarySearchTree()
{
	destroy(root);
	root = NULL;
}//End of ~BinarySearchTree()

void BinarySearchTree::destroy(Node *ptr)
{
	if(ptr == NULL)
		return;
	destroy(ptr->lchild);
	destroy(ptr->rchild);

	delete ptr;
}//End of destroy()

//Non Recursive insertion
void BinarySearchTree::insert(int key)
{
	Node *parent = NULL;
	Node *ptr = root;

	while(ptr != NULL)
	{
		parent = ptr;

		if(key < ptr->info)
			ptr = ptr->lchild;
		else if(key > ptr->info)
			ptr = ptr->rchild;
		else
		{
			cout << key << " is already there\n";
			return;
		}
	}

	Node *temp = new Node(key);

	if(parent == NULL)
		root = temp;
	else if(key < parent->info)
		parent->lchild = temp;
	else
		parent->rchild = temp;
}//End of insert()

void BinarySearchTree::display(Node *ptr, int level)
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

void BinarySearchTree::display()
{
	display(root, 0);
}//End of display()

void BinarySearchTree::displayPaths(Node* ptr, int path[], int n)
{ 
	if(ptr==NULL) 
		return;

	path[n++] = ptr->info; 
	
	if(ptr->lchild==NULL && ptr->rchild==NULL) 
	{
		for(int i=0; i<n; i++) 
			cout << path[i] << " ";
		cout << "\n";
	}	
	else 
	{ 
	    displayPaths(ptr->lchild, path, n); 
		displayPaths(ptr->rchild, path, n); 
	} 
}//End of displayPaths()

void BinarySearchTree::displayPaths()
{
	int path[maxSize];

	displayPaths(root, path, 0);
}//End of displayPaths()

int main()
{
	BinarySearchTree bst;

	//Create the Binary Search Tree
	bst.insert(80);
	bst.insert(70);
	bst.insert(65);
	bst.insert(75);
	bst.insert(90);
	bst.insert(85);
	bst.insert(95);

	cout << "Binary Search Tree is :\n";
	bst.display();
	cout << "\n";

	cout << "Root to leaf nodes paths :\n";
	bst.displayPaths();

	return 0;
}//End of main()
