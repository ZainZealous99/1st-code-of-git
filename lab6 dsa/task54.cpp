#include <iostream>
using namespace std;

class node
{
public:
    string name;
    int priority;
    node* next;

    node(string n, int p)
    {
        name = n;
        priority = p;
        next = nullptr;
    }
};

class reservationlist
{
private:
    node* head;

public:
    reservationlist()
    {
        head = nullptr;
    }

    void addstudent(string name, int priority)
    {
        node* newnode = new node(name, priority);

        if (head == nullptr || priority < head->priority)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        node* temp = head;

        while (temp->next != nullptr && temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void removestudent(string name)
    {
        if (head == nullptr)
        {
            cout << "list empty" << endl;
            return;
        }

        if (head->name == name)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "removed" << endl;
            return;
        }

        node* temp = head;

        while (temp->next != nullptr && temp->next->name != name)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "not found" << endl;
            return;
        }

        node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "removed" << endl;
    }

    void updatepriority(string name, int newp)
    {
        removestudent(name);
        addstudent(name, newp);
    }

    void serve()
    {
        if (head == nullptr)
        {
            cout << "no student" << endl;
            return;
        }

        node* temp = head;
        cout << "served " << temp->name << endl;

        head = head->next;
        delete temp;
    }

    void display()
    {
        node* temp = head;

        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }

        while (temp != nullptr)
        {
            cout << temp->name << " " << temp->priority << endl;
            temp = temp->next;
        }
    }

    void count()
    {
        node* temp = head;
        int c = 0;

        while (temp != nullptr)
        {
            c++;
            temp = temp->next;
        }

        cout << "total " << c << endl;
    }
};

class book
{
public:
    string title;
    reservationlist list;

    book(string t)
    {
        title = t;
    }
};

int main()
{
    book b1("data structures");
    book b2("algorithms");

    int choice;
    int bookchoice;
    string name;
    int priority;

    do
    {
        cout << endl;
        cout << "1 add student" << endl;
        cout << "2 remove student" << endl;
        cout << "3 update priority" << endl;
        cout << "4 display list" << endl;
        cout << "5 count students" << endl;
        cout << "6 serve next" << endl;
        cout << "7 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            cout << "select book 1 or 2 ";
            cin >> bookchoice;
        }

        reservationlist* r;

        if (bookchoice == 1)
            r = &b1.list;
        else
            r = &b2.list;

        switch (choice)
        {
        case 1:
            cout << "enter name ";
            cin >> name;
            cout << "enter priority ";
            cin >> priority;
            r->addstudent(name, priority);
            break;

        case 2:
            cout << "enter name ";
            cin >> name;
            r->removestudent(name);
            break;

        case 3:
            cout << "enter name ";
            cin >> name;
            cout << "enter new priority ";
            cin >> priority;
            r->updatepriority(name, priority);
            break;

        case 4:
            r->display();
            break;

        case 5:
            r->count();
            break;

        case 6:
            r->serve();
            break;

        case 7:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 7);

    return 0;
}