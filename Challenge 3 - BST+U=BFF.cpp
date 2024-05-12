// Challenge 3 - BST+U=BFF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include "BST.h"
using namespace std;



bool BST::search(int data)
{
    return search(root, data);
}
bool BST::search(bst_Node*& node, int data)
{
    if (node == nullptr) {
        return false;
    }
    if (data < node->data) {
        return search(node->left, data);
    }
    if (data > node->data) {
        return search(node->right, data);
    }
    return true;
}
bool BST::insert(int data)
{
    return insert(root, data);
}
bool BST::insert(bst_Node*& node, int data)
{
    if (node == nullptr) {
        node = new bst_Node(data);
        return true;
    }
    if (data < node->data)
        return insert(node->left, data);
    if (data > node->data)
        return insert(node->right, data);
    return false;
}

bool BST::remove(int data)
{
    return remove(root, data);
}
bool BST::remove(bst_Node*& node, int data)
{
    if (node == nullptr) {
        return false;
    }
    if (data < node->data) {
        return remove(node->left, data);
    }
    if (data > node->data) {
        return remove(node->right, data);
    }
    int deg = node->degree();
    if (deg == 0)
    {
        delete node;
        node = nullptr;
    }
    if (deg == 1)
    {
        bst_Node* tmp = node;
        if (node->left != nullptr)
        {
            node = node->left;
        }
    else
    {
        node = node->right;
    }
    delete tmp;
    }
    else if (deg == 2)
    {
        bst_Node* tmp = node->left;
        while (node->right != nullptr)
        {
            tmp = tmp->right;
        }
        node->data = tmp->data;
        remove(node->left, tmp->data);
    }
    return true;
 }


int bst_Node::degree() {
    int cnt_child = 0;
    if (left != nullptr)
    {
        cnt_child++;
    }
    if (right != nullptr)
    {
        cnt_child++;
    }
    return cnt_child;
}

void BST::postOrder(bst_Node*& node)
{
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}
void BST::preOrder(bst_Node*& node)
{
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void BST::inOrder(bst_Node*& node)
{
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
void BST::postOrder()
{
    return postOrder(root);
    cout << endl;
}
void BST::preOrder()
{
    return preOrder(root);
    cout << endl;
}
void BST::inOrder()
{
    return inOrder(root);
    cout << endl;
}



