//Ex22.cpp : Two binary trees are similar if their structure is same. Write a function to check whether two binary trees are similar or not.

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
		bool isSimilar(Node *ptr1, Node *ptr2);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		void insert(int key);
		void display();
		bool isSimilar(BinarySearchTree &bst);
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

bool BinarySearchTree::isSimilar(Node *ptr1, Node *ptr2)
{
	if(ptr1==NULL && ptr2==NULL)
		return true;

	if(ptr1!=NULL && ptr2!=NULL)
		if(isSimilar(ptr1->lchild, ptr2->lchild) && isSimilar(ptr1->rchild, ptr2->rchild))
			return true;

	return false;
}//End of isSimilar()

bool BinarySearchTree::isSimilar(BinarySearchTree &bst)
{
	return isSimilar(root, bst.root);
}//End of isSimilar()

int main()
{
	BinarySearchTree bst1, bst2, bst3;

	//Create the Binary Search Tree
	bst1.insert(10);
	bst1.insert(2);
	bst1.insert(9);
	bst1.insert(5);

	bst2.insert(6);
	bst2.insert(3);
	bst2.insert(8);
	bst2.insert(7);
	bst2.insert(1);
	bst2.insert(4);

	bst3.insert(16);
	bst3.insert(13);
	bst3.insert(18);
	bst3.insert(17);
	bst3.insert(11);
	bst3.insert(14);

	cout << "Binary Search Tree 1 :\n";
	bst1.display();
	cout << "\n";

	cout << "Binary Search Tree 2 :\n";
	bst2.display();
	cout << "\n";

	cout << "Binary Search Tree 3 :\n";
	bst3.display();
	cout << "\n";

	if(bst1.isSimilar(bst2))
		cout << "Tree 1 and 2 are similar\n";
	else
		cout << "Tree 1 and 2 are not similar\n";

	if(bst2.isSimilar(bst3))
		cout << "Tree 2 and 3 are similar\n";
	else
		cout << "Tree 2 and 3 are not similar\n";

	return 0;
}//End of main()
