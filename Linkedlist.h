#include <ostream>
using namespace std;

class ll_Node
{
public:
    int data;
    ll_Node* next;
    ll_Node* prev;
  

    ll_Node() : data(0), next(nullptr), prev(nullptr) {}
    ll_Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    ll_Node(int data, ll_Node* next, ll_Node *prev): 
        data(data), next(next), prev(prev) {} 
};


class LinkedList
{
private:
    ll_Node *head;
    ll_Node *tail;
public:
    LinkedList();
    ~LinkedList();

    void insert(int data);
    void prepend(int data);
    bool remove(int data);
    void display(ostream &os);
    void taildisplay(ostream &os);
    bool tailremove(int data);
    bool search(int data);

    friend ostream &operator<<(ostream& os, LinkedList& right);

}; 
