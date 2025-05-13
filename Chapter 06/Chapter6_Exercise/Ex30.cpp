//Ex30.cpp : Write a function to traverse a binary tree in zigzag order.

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
		void displayLevelLeftToRight(Node* ptr, int level);
		void displayLevelRightToLeft(Node* ptr, int level);
		int height(Node *ptr);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		void zigzagOrder();

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

//Displays nodes on a level from left to right
void BinarySearchTree::displayLevelLeftToRight(Node* ptr, int level)
{  
	if(ptr == NULL)  
		return;

	if(level == 0)  
		cout << ptr->info << " ";

	displayLevelLeftToRight(ptr->lchild, level-1); 
	displayLevelLeftToRight(ptr->rchild, level-1);  
}//End of displayLevelLeftToRight()

//Displays nodes on a level from right to left
void BinarySearchTree::displayLevelRightToLeft(Node* ptr, int level)
{  
	if(ptr == NULL)  
		return;

	if(level == 0)
		cout << ptr->info << " ";

	displayLevelRightToLeft(ptr->rchild, level-1);
	displayLevelRightToLeft(ptr->lchild, level-1);
}//End of displayLevelRightToLeft()

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

void BinarySearchTree::zigzagOrder()  
{  
	int h = height(root);
	for(int i=0; i<height(root); i++)	
		if(i%2==0)
			displayLevelLeftToRight(root,i);
		else
			displayLevelRightToLeft(root,i);
}//End of zigzagOrder()

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
	bst.insert(68);
	bst.insert(98);

	cout << "Binary Search Tree is :\n";
	bst.display();
	cout << "\n";

	cout << "Display tree in spiral order = ";
	bst.zigzagOrder();
	cout << "\n";

	return 0;
}//End of main()
