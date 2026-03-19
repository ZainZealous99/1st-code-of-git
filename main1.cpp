#include <iostream>
#include "Stack1.h"

using namespace std;

int main() {
    int size;
    cout << "enter stack size: ";
    cin >> size;

    mystack<int> stack(size);
    int choice, value;

    do {
        cout << endl;
        cout << "......................." << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. top" << endl;
        cout << "4. check if empty" << endl;
        cout << "5. check if full" << endl;
        cout << "6. display" << endl;
        cout << "0. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "enter value: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            cout << "popped: " << stack.pop() << endl;
            break;
        case 3:
            cout << "top element: " << stack.top() << endl;
            break;
        case 4:
            cout << (stack.isempty() ? "stack is empty" : "stack is not empty") << endl;
            break;
        case 5:
            cout << (stack.isfull() ? "stack is full" : "stack is not full") << endl;
            break;
        case 6:
            stack.display();
            break;
        case 0:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}