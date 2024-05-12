// Challenge 1 - The Missing link.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

bool LinkedList::search(int data)
{
    ll_Node* tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->data = data) return true;
        tmp = tmp->next;
    }
    return false;
}
//add tmp to point to prev and let it equal tail
void LinkedList::insert(int data) 
{
    ll_Node* tmp = new ll_Node(data);
    tmp->prev = tail;
    if (head == nullptr)
    {
        head = tmp;
    }
    else
    {
        tail->next = tmp;
    }
    tail = tmp;
}

//an else statement where head points equal to tmp
//move line up 45
void LinkedList::prepend(int data) 
{
    ll_Node* tmp = new ll_Node(data);
    tmp->next = head;
    if (head == nullptr)
    {
        tail = tmp;
    }
    else 
    {
        head->prev = tmp;
    }
    head = tmp;
}

//tail: set tmp node to tail
//if tmp points to prev is not a nullptr, the tmp->prev->next equals tmp->next
//then switch them out
bool LinkedList::remove(int data)
{
    ll_Node* tmp = head;
    ll_Node* prev = nullptr;
    while (tmp != nullptr)
    {
        if (tmp->data == data)
        {  
            if (tmp->prev != nullptr) 
            {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next != nullptr)
            {
                tmp->next->prev = tmp->prev;
            }
            if (tmp == head)
            {
                head = tmp->next;
            }
            else 
            {
                prev->next = tmp->next;
            }
            if (tmp == tail)
            {
                tail = tmp->prev; //change to prev
            }
            delete tmp;

            return true;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return false;
}

//tail: tail then prev but the same 
void LinkedList::display(ostream &os)
{
    ll_Node* tmp = head;
    while (tmp != nullptr)
    {
        os << tmp->data << " ";
        tmp = tmp->next;
    }
}


LinkedList::~LinkedList()
{
    ll_Node* tmp = head;
    while (tmp != nullptr)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
    tail = nullptr;
}
ostream &operator<<(ostream& os, LinkedList& right)
{
    right.display(os);
    return os;
}

void LinkedList::taildisplay(ostream& os)
{
    ll_Node* tmp = tail;
    while (tmp != nullptr)
    {
        os << tmp->data << " ";
        tmp = tmp->prev;
    }
}
bool LinkedList::tailremove(int data)
{
    ll_Node* tmp = tail;
    ll_Node* prev = nullptr;
    while (tmp != nullptr)
    {
        if (tmp->data == data)
        {
            if (tmp->prev != nullptr)
            {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next != nullptr)
            {
                tmp->next->prev = tmp->prev;
            }
            if (tmp == head)
            {
                head = tmp->next;
            }
            else
            {
                tmp->next = tmp->prev;
            }
            if (tmp == tail)
            {
                tail = tmp->prev; //change to prev
            }
            delete tmp;

            return true;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return false;
}




