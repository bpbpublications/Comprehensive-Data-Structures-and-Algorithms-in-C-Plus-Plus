//Ex25.cpp : Write a function to find whether two binary trees are mirror image of each other or not.

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
		bool isIdentical(Node *ptr1, Node *ptr2);
		bool isMirrorImage(Node *ptr);

	public:
		BinaryTree();
		~BinaryTree();

		void display();
		bool isMirrorImage(BinaryTree &bt);
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

bool BinaryTree::isMirrorImage(Node *ptr)
{
	bool flag;

	swapChildren(root);

	if(isIdentical(root, ptr))
		flag = true;
	else
		flag = false;

	swapChildren(root);

	return flag;
}//End of isMirrorImage()

bool BinaryTree::isMirrorImage(BinaryTree &bt)
{
	return isMirrorImage(bt.root);
}//End of isMirrorImage()

bool BinaryTree::isIdentical(Node *ptr1, Node *ptr2)
{
	if(ptr1==NULL && ptr2==NULL)
		return true;

	if(ptr1!=NULL && ptr2!=NULL && ptr1->info == ptr2->info)
		if(isIdentical(ptr1->lchild, ptr2->lchild) && isIdentical(ptr1->rchild, ptr2->rchild))
			return true;

	return false;
}//End of isIdentical()

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

int main()
{
	BinaryTree bt1, bt2, bt3;

	//Create the Binary Tree
	bt1.root = new Node(32);
	bt1.root->lchild = new Node(23);
	bt1.root->rchild = new Node(13);
	bt1.root->lchild->rchild = new Node(45);
	bt1.root->rchild->lchild = new Node(48);

	cout << "Binary Tree 1 :\n";
	bt1.display();
	cout << "\n";

	bt2.root = new Node(42);
	bt2.root->lchild = new Node(60);
	bt2.root->rchild = new Node(19);
	bt2.root->lchild->rchild = new Node(36);
	bt2.root->rchild->lchild = new Node(41);

	cout << "Binary Tree 2 :\n";
	bt2.display();
	cout << "\n";
	
	bt3.root = new Node(32);
	bt3.root->lchild = new Node(13);
	bt3.root->rchild = new Node(23);
	bt3.root->lchild->rchild = new Node(48);
	bt3.root->rchild->lchild = new Node(45);

	cout << "Binary Tree 3 :\n";
	bt3.display();
	cout << "\n";

	if(bt1.isMirrorImage(bt2))
		cout << "Binary Tree 1 is mirror image of Binary Tree 2\n";
	else
		cout << "Binary Tree 1 is not mirror image of Binary Tree 2\n";

	if(bt1.isMirrorImage(bt3))
		cout << "Binary Tree 1 is mirror image of Binary Tree 3\n";
	else
		cout << "Binary Tree 1 is not mirror image of Binary Tree 3\n";

	return 0;
}//End of main()
