#include <iostream>
#include "myqueue4.h"
using namespace std;

int main() {
    myqueue4 tickets;

    int choice, 
    int ticketid;

    do {
        cout << endl;
        cout << "customer support ticket system" << endl;
        cout << "1add ticket" << endl;
        cout << "2resolve ticket" << endl;
        cout << "3next ticket" << endl;
        cout << "4display pending tickets" << endl;
        cout << "exit" << endl;

        cout << "enter the choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "enter ticket id: ";
            cin >> ticketid;
            tickets.enqueue(ticketid);
            break;

        case 2:
            tickets.dequeue();
            break;

        case 3:
            ticketid = tickets.front();

            if (ticketid != -1)
                cout << "next ticket to resolve: " << ticketid << endl;
            break;

        case 4:
            tickets.display();
            break;

        case 0:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice is this" << endl;
        }

    } while (choice != 0);

    return 0;
}