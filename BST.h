#include <ostream>
#include <iostream>
class bst_Node
{
public:
	int data;
	bst_Node* left;
	bst_Node* right;
	bst_Node() : data(0), left(nullptr), right(nullptr) {}
	bst_Node(int data) : data(data), left(nullptr), right(nullptr) {}
	int degree();
};
class BST
{
private:
	bst_Node* root;
	bool search(bst_Node*& node, int data);
	bool insert(bst_Node*& node, int data);
	bool remove(bst_Node*& node, int data);
	bool degree(bst_Node*& node, int data);
	void inOrder(bst_Node* &node);
	void preOrder(bst_Node* &node);
	void postOrder(bst_Node* &node);
	bool inOrder(int data);
	bool postOrder(int data);
	bool preOrder(int data);
public:
	BST() : root(nullptr) {}
	bool insert(int data);
	bool remove(int data);
	bool find(int data);
	void inOrder();
	void preOrder();
	void postOrder();
	bool search(int data);
};

