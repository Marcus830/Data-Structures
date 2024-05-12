// Stacksandquese.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include "Header.h"
using namespace std;

Stack::~Stack() //add bottom equals nullptr outside of the while loop
{
    Node* tmp = top;
    while (tmp != nullptr)
    {
        top = top->next;
        delete tmp;
        tmp = top;
    }
    bottom = nullptr;
}
ostream& operator<<(ostream& os, Stack& right)
{
    right.display(os);
    return os;
}
bool Stack::peek(int& data)
{
    if (top == nullptr) return false;
    data = top->data;
    return true;
}
void Stack::push(int data) //del 33 & 34, add if top equals nullptr then top equals tmp, else bottom points to next equals tmp. bottom equals tmp
{
    Node* tmp = new Node(data);
    if (top == nullptr)
    {
        top = tmp;
    }
    else
    {
        bottom->next = tmp;
    }
    bottom = tmp;
}
bool Stack::pop() //between line 40 and 41 add if top = nullptr then bottom = nullptr
{
    Node* tmp = top;
    if (top == nullptr) return false;
    top = top->next;
    if (top == nullptr)
    {
        bottom = nullptr;
    }
    delete tmp;
    return true;
}
void Stack::display(ostream& os)
{
    Node* tmp = top;
    while (tmp != nullptr)
    {
        os << tmp->data << " ";
        tmp = tmp->next;
        cout << endl;
    }
}

int main()
{
    Stack S;
    int tmp;
    S.push(5);
    S.peek(tmp);
     cout << tmp << endl;
    S.push(33);
    S.push(1);
    S.push(7);
    S.peek(tmp);
    cout << tmp << endl;
    cout << "\n";
    S.push(33);
    S.push(12);
    S.display(cout);
    cout << "\n";
    S.pop();
    S.display(cout);
    cout << "\n";
    S.push(14);
    S.display(cout);
    cout << "\n";
    S.pop();
    S.pop();
    S.display(cout);
    cout << "\n";
    S.pop();
    S.pop();
    S.display(cout);
    cout << "\n";
    S.peek(tmp);
    cout << tmp << endl;
}

