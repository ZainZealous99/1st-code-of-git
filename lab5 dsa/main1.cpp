#include <iostream>
#include "myQueue1.h"
using namespace std;

int main() 
{
    int size;
    cout << "enter the size of queue:";
    cin >> size;

    myqueue<int> q(size);

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << ".........queue menu............." << endl;
        cout << "1enqueue" << endl;
        cout << "2dequeue" << endl;
        cout << "3front" << endl;
        cout << "4check empty" << endl;
        cout << "5check full" << endl;
        cout << "6display" << endl;
        cout << "exit" << endl;

        cout << "enter choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "enter the  value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "removed: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "front: " << q.front() << endl;
            break;

        case 4:
            cout << (q.isempty() ? "queue is empty" : "queue is not empty") << endl;
            break;

        case 5:
            cout << (q.isfull() ? "queue is full" : "queue is not full") << endl;
            break;

        case 6:
            q.display();
            break;

        case 0:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}