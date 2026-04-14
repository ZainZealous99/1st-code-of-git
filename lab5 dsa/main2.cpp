#include <iostream>
#include "myqueue2stack.h"
using namespace std;

int main() 
{
    myqueue2stack<int> q;

    int choice, value;

    do {
        cout << endl;
        cout << ".....queue using stack menu....." << endl;

        cout << "enqueue" << endl;
        cout << "2dequeue" << endl;
        cout << "3front" << endl;
        cout << "4display" << endl;
        cout << "exit" << endl;

        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "enter the value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "removed " << q.dequeue() << endl;
            break;

        case 3:
            cout << "front " << q.front() << endl;
            break;

        case 4:
            cout << "queue elements";
            q.display();
            break;

        case 0:
            cout << "exiting" << endl;
            break;

        default:
            cout << "choice is invalid" << endl;
        }

    } while (choice != 0);

    return 0;
}