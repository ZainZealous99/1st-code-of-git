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
node* insertbegin(node* head, int value)
{
    node* newnode = new node(value);
    newnode->next = head;
    head = newnode;
    return head;
}
node* insertend(node* head, int value)
{
    if (head == NULL)
    {
        return new node(value);
    }

    head->next = insertend(head->next, value);
    return head;
}
node* insertpos(node* head, int value, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        node* newnode = new node(value);
        newnode->next = head;
        return newnode;
    }

    head->next = insertpos(head->next, value, pos - 1);
    return head;
}
node* deletevalue(node* head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == value)
    {
        node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletevalue(head->next, value);
    return head;
}
node* deletepos(node* head, int pos)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (pos == 1)
    {
        node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletepos(head->next, pos - 1);
    return head;
}
int search(node* head, int value, int pos)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->data == value)
    {
        return pos;
    }

    return search(head->next, value, pos + 1);
}
int main()
{
    node* head = NULL;

    head = insertbegin(head, 10);
    printlist(head);
    cout << endl;

    head = insertend(head, 20);
    printlist(head);
    cout << endl;

    head = insertend(head, 30);
    printlist(head);
    cout << endl;

    head = insertpos(head, 25, 3);
    printlist(head);
    cout << endl;

    head = deletevalue(head, 20);
    printlist(head);
    cout << endl;

    head = deletepos(head, 2);
    printlist(head);
    cout << endl;

    cout << "search result" << search(head, 30, 1) << endl;

    return 0;
}