//EX36.cpp : Write a function to check wheather a BST is AVL tree or not.

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
		int height(Node *ptr);
		bool isAVL(Node *ptr);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		bool isAVL();

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

bool BinarySearchTree::isAVL(Node *ptr)  
{
	int heightLeft, heightRight, diff;

	if(ptr == NULL)  
		return true;

	heightLeft = height(ptr->lchild);  
	heightRight = height(ptr->rchild);  
	diff = heightLeft > heightRight ? heightLeft-heightRight : heightRight-heightLeft;

	if(diff<=1 &&  isAVL(ptr->lchild) && isAVL(ptr->rchild))  
		return true;

	return false;
}//End of isAVL()

bool BinarySearchTree::isAVL()
{
	return isAVL(root);
}//End of isAVL()

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

	if(bst.isAVL())
		printf("BST is an AVL tree\n");
	else
		printf("BST is not an AVL tree\n");

	return 0;
}//End of main()
