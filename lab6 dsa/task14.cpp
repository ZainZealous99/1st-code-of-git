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
class singlylinkedlist
{
private:
    node < t >* head;

public:
    singlylinkedlist()
    {
        head = nullptr;
    }

    void createnode(t value)
    {
        node < t >* newnode = new node < t >(value);

        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            node < t >* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
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
    singlylinkedlist < int > list;

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << "1 create node" << endl;
        cout << "2 display list" << endl;
        cout << "3 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value ";
            cin >> value;
            list.createnode(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 3);

    return 0;
}