#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() 
{
    queue<string> printqueue;
    int choice;
    string document;

    do 
    {
        cout << endl;
        cout << "........printer queue menu....." << endl;
        cout << "1add print job" << endl;
        cout << "2print document" << endl;
        cout << "3check next document" << endl;
        cout << "4display pending documents" << endl;
        cout << "exit" << endl;
        cout << "enter the choice:";
        cin >> choice;

        cin.ignore();

        switch (choice) 
        {
        case 1:
            cout << "Enter the document name:";
            getline(cin, document);

            printqueue.push(document);

            cout << document << " adding a queue to print." << endl;
            break;

        case 2:
            if (printqueue.empty()) 
            {
                cout << "No documents to print" << endl;
            }
            else 
            {
                cout << "printing document " << printqueue.front() << endl;
                printqueue.pop();
            }
            break;

        case 3:
            if (printqueue.empty()) 
            {
                cout << "print queue is empty" << endl;
            }
            else {
                cout << "next document to print " << printqueue.front() << endl;
            }
            break;

        case 4:
            if (printqueue.empty()) 
            {
                cout << "no pending documents" << endl;
            }
            else 
            {
                cout << "pending documents ";
                queue<string> temp = printqueue;
                while (!temp.empty()) 
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
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