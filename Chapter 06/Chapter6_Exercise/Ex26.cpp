//Ex26.cpp : Write a function to check whether a binary tree is binary search tree or not.

#include<iostream>
#include<limits>
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
		void inorder(Node *ptr);
		bool isBST(Node *ptr, int MIN, int MAX);

	public:
		BinaryTree();
		~BinaryTree();

		void display();
		void inorder();
		bool isBST();

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

void BinaryTree::inorder(Node *ptr)
{
	if(ptr == NULL )//Base Case
		return;
	inorder(ptr->lchild);
	cout << ptr->info << " ";
	inorder(ptr->rchild);
}//End of inorder()

void BinaryTree::inorder()
{
	inorder(root);
}//End of inorder()

bool BinaryTree::isBST(Node *ptr, int MIN, int MAX)
{ 
	if(ptr == NULL) 
		return true;

	if(ptr->info < MIN || ptr->info > MAX)
		return false;

	return (isBST(ptr->lchild,MIN,ptr->info) && isBST(ptr->rchild,ptr->info,MAX)); 
}//End of isBST()

bool BinaryTree::isBST()  
{
	return isBST(root, INT_MIN, INT_MAX);
}//End of isBST()

int main()
{
	BinaryTree bt1, bt2;

	//Create the Binary Tree
	bt1.root = new Node(32);
	bt1.root->lchild = new Node(23);
	bt1.root->rchild = new Node(36);
	bt1.root->lchild->rchild = new Node(25);
	bt1.root->rchild->lchild = new Node(33);

	cout << "Binary Tree 1 :\n";
	bt1.display();
	cout << "\n";
	cout << "Inorder :\n";
	bt1.inorder();
	cout << "\n";

	bt2.root = new Node(42);
	bt2.root->lchild = new Node(60);
	bt2.root->rchild = new Node(19);
	bt2.root->lchild->rchild = new Node(36);
	bt2.root->rchild->lchild = new Node(41);

	cout << "Binary Tree 2 :\n";
	bt2.display();
	cout << "\n";
	cout << "Inorder :\n";
	bt2.inorder();
	cout << "\n";
	
	if(bt1.isBST())  
		cout << "Binary Tree 1 is a BST\n";
	else
		cout << "Binary Tree 2 is not a BST\n";

	if(bt2.isBST())  
		cout << "Binary Tree 2 is a BST\n";
	else
		cout << "Binary Tree 2 is not a BST\n";

	return 0;
}//End of main()
