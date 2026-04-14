#include <iostream>
using namespace std;

template < typename t >
class node
{
public:
    t data;
    node < t >* next;

    node(t value)
    {
        data = value;
        next = nullptr;
    }
};

template < typename t >
class listadt
{
private:
    node < t >* head;

public:
    listadt()
    {
        head = nullptr;
    }

    void insertbegin(t value)
    {
        node < t >* newnode = new node < t >(value);

        newnode->next = head;
        head = newnode;
    }

    void insertend(t value)
    {
        node < t >* newnode = new node < t >(value);

        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        node < t >* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    void deletevalue(t value)
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (head->data == value)
        {
            node < t >* temp = head;
            head = head->next;
            delete temp;
            cout << "deleted" << endl;
            return;
        }

        node < t >* current = head;

        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "not found" << endl;
            return;
        }

        node < t >* temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "deleted" << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        node < t >* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    listadt < int > list;

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << "1 insert beginning" << endl;
        cout << "2 insert end" << endl;
        cout << "3 delete value" << endl;
        cout << "4 display" << endl;
        cout << "5 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value ";
            cin >> value;
            list.insertbegin(value);
            break;

        case 2:
            cout << "enter value ";
            cin >> value;
            list.insertend(value);
            break;

        case 3:
            cout << "enter value ";
            cin >> value;
            list.deletevalue(value);
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}