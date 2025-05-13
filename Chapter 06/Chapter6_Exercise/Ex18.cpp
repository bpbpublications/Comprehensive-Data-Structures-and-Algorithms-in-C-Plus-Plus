//Ex18.cpp : Write a function that returns the total number of leaf nodes in a binary tree and displays the info part of each leaf node.

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

class BinarySearchTree
{
	private:
		Node *root;

	private:
		void display(Node *ptr, int level);
		void destroy(Node *ptr);
		void leafNodes(Node *ptr);
		int countLeafNodes(Node *ptr);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		void leafNodes();
		int countLeafNodes();
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

void BinarySearchTree::leafNodes(Node *ptr)
{  
	if(ptr == NULL)  
		return;

	if(ptr->lchild == NULL && ptr->rchild==NULL)  
	{
		cout << ptr->info << " ";	
	}
	else
	{
		leafNodes(ptr->lchild);
		leafNodes(ptr->rchild);
	}
}//End of leafNodes()

void BinarySearchTree::leafNodes()  
{
	leafNodes(root);
}//End of leafNodes()

int BinarySearchTree::countLeafNodes(Node *ptr)
{  
	if(ptr == NULL)  
		return 0;

	if(ptr->lchild == NULL && ptr->rchild==NULL)  
		return 1;  
	else 
		return countLeafNodes(ptr->lchild) +  countLeafNodes(ptr->rchild);  
}//End of countLeafNodes()

int BinarySearchTree::countLeafNodes()  
{
	return countLeafNodes(root);
}//End of countLeafNodes()

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

	cout << "Leaf nodes are :\n";
	bst.leafNodes();
	cout << "\n";

	cout << "Total number of leaf nodes = " << bst.countLeafNodes();
	cout << "\n";

	return 0;
}//End of main()
