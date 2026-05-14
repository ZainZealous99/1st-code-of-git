#include <iostream>
using namespace std;

class node
{
public:

    int data;
    node* next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void printlist(node* head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->data << " ";

    printlist(head->next);
}

int main()
{
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);

    head->next = second;
    second->next = third;

    cout << "the link list element are:";

    printlist(head);

    return 0;
}