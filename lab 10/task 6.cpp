#include <iostream>
using namespace std;

class node
{
public:

    int data;
    node* next;
    node* prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

node* headGlobal = NULL;
node* tailGlobal = NULL;

void printforward(node* head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printforward(head->next);
}

void printreverse(node* tail)
{
    if (tail == NULL)
    {
        return;
    }
    cout << tail->data << " ";
    printreverse(tail->prev);
}

node* insertend(node* head, int value)
{
    if (head == NULL)
    {
        node* newnode = new node(value);
        tailGlobal = newnode;
        return newnode;
    }
    head->next = insertend(head->next, value);
    head->next->prev = head;

    if (head->next->next == NULL)
    {
        tailGlobal = head->next;
    }

    return head;
}

node* insertbegin(node* head, int value)
{
    node* newnode = new node(value);

    if (head == NULL)
    {
        tailGlobal = newnode;
        return newnode;
    }

    newnode->next = head;
    head->prev = newnode;

    return newnode;
}

node* insertpos(node* head, int value, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        node* newnode = new node(value);

        if (head != NULL)
        {
            newnode->next = head;
            head->prev = newnode;
        }
        else
        {
            tailGlobal = newnode;
        }

        return newnode;
    }

    head->next = insertpos(head->next, value, pos - 1);

    if (head->next != NULL)
    {
        head->next->prev = head;
    }

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

        if (temp != NULL)
        {
            temp->prev = NULL;
        }

        delete head;
        return temp;
    }

    head->next = deletevalue(head->next, value);

    if (head->next != NULL)
    {
        head->next->prev = head;
    }

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

        if (temp != NULL)
        {
            temp->prev = NULL;
        }

        delete head;
        return temp;
    }

    head->next = deletepos(head->next, pos - 1);

    if (head->next != NULL)
    {
        head->next->prev = head;
    }

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

node* gettail(node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    return gettail(head->next);
}

bool checkpal(node* left, node* right)
{
    if (left == NULL || right == NULL)
    {
        return true;
    }

    if (left == right || left->prev == right)
    {
        return true;
    }

    if (left->data != right->data)
    {
        return false;
    }

    return checkpal(left->next, right->prev);
}

bool ispalindrome(node* head)
{

    node* tail = gettail(head);
    return checkpal(head, tail);
}

int main()
{
    node* head = NULL;

    head = insertend(head, 1);
    head = insertend(head, 2);
    head = insertend(head, 3);
    head = insertend(head, 2);
    head = insertend(head, 1);

    cout << "forward";
    printforward(head);
    cout << endl;

    cout << "reverse";
    printreverse(gettail(head));
    cout << endl;

    cout << "palindrome" << (ispalindrome(head) ? "true" : "false") << endl;

    head = deletevalue(head, 3);

    cout << "after deletion";
    printforward(head);
    cout << endl;

    head = deletepos(head, 2);
    cout << "after position deletion";
    printforward(head);
    cout << endl;


    cout << "search: " << search(head, 2, 1) << endl;

    return 0;
}