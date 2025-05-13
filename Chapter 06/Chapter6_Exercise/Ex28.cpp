//Ex28.cpp : Width of a binary tree is the number of nodes on the level that has maximum nodes. Write a function that returns the 
//width of a binary tree.

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
		int nodesAtLevel(Node *ptr, int level);
		int height(Node *ptr);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		int width();
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

int BinarySearchTree::nodesAtLevel(Node *ptr, int level) 
{
	if(ptr==NULL)
		return 0;

	if(level==0) 
		return 1;

	return nodesAtLevel(ptr->lchild,level-1) + nodesAtLevel(ptr->rchild,level-1);
}//End of nodesAtLevel()

int BinarySearchTree::height(Node *ptr)
{
	int hLeft, hRight;

	if(ptr == NULL)	//Base case
		return 0;

	hLeft = height(ptr->lchild);
	hRight = height(ptr->rchild);

	if(hLeft > hRight)
		return 1+hLeft;
	else
		return 1+hRight;
}//End of height()

int BinarySearchTree::width()
{
	int n, max = 0; 
	for(int i=0; i<height(root); i++)	
		if((n=nodesAtLevel(root,i)) > max )
			max = n;
	return max;	
}//End of width()

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

	cout << "Width = " << bst.width();
	cout << "\n";

	return 0;
}//End of main()
