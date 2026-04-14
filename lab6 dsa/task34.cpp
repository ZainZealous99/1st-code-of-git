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

    void insertatposition(t value, int pos)
    {
        node < t >* newnode = new node < t >(value);

        if (pos == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        node < t >* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "invalid position" << endl;
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteatposition(int pos)
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (pos == 1)
        {
            node < t >* temp = head;
            head = head->next;
            delete temp;
            cout << "deleted" << endl;
            return;
        }

        node < t >* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "invalid position" << endl;
            return;
        }

        node < t >* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "deleted" << endl;
    }

    void search(t value)
    {
        node < t >* temp = head;
        int pos = 1;

        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "not found" << endl;
    }

    void countnodes()
    {
        node < t >* temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "total nodes " << count << endl;
    }

    void display()
    {
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
    int pos;

    do
    {
        cout << endl;
        cout << "1 insert at position" << endl;
        cout << "2 delete at position" << endl;
        cout << "3 search element" << endl;
        cout << "4 count nodes" << endl;
        cout << "5 display" << endl;
        cout << "6 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value ";
            cin >> value;
            cout << "enter position ";
            cin >> pos;
            list.insertatposition(value, pos);
            break;

        case 2:
            cout << "enter position ";
            cin >> pos;
            list.deleteatposition(pos);
            break;

        case 3:
            cout << "enter value ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            list.countnodes();
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}