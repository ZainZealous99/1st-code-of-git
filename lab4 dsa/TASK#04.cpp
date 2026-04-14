#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct action 
{
    char character;
    string type;
};

int main() 
{
    string text = " ";

    stack<action> undostack;
    stack<action> redostack;
    int choice;
    char ch;

    do 
    {
        cout << "current text: " << text << endl;
        cout << "1.type a character" << endl;
        cout << "2.delete last character" << endl;
        cout << "3.undo" << endl;
        cout << "4.redo" << endl;
        cout << "5.exit" << endl;
        cout << "enter the your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            cout << "enter the character to type:";
            cin >> ch;
            text += ch;
            undostack.push({ ch, "insert" });

            while (!redostack.empty()) redostack.pop();
            break;
        case 2:
            if (text.empty())
            {
                cout << "text is empty, nothing to delete." << endl;
            }
            else
            {
                ch = text.back();
                text.pop_back();
                undostack.push({ ch, "delete" });

                while (!redostack.empty()) redostack.pop();
            }
            break;
        case 3:
            if (undostack.empty()) 
            {
                cout << "nothing to undo." << endl;
            }
            else
            {
                action last = undostack.top();
                undostack.pop();
                if (last.type == "insert") text.pop_back();
                else text += last.character;
                redostack.push(last);
            }
            break;
        case 4:
            if (redostack.empty()) 
            {
                cout << "nothing to redos." << endl;
            }
            else
            {
                action last = redostack.top();
                redostack.pop();
                if (last.type == "insert") text += last.character;
                else text.pop_back();
                undostack.push(last);
            }
            break;

        case 5:
            cout << "exiting editor." << endl;

            break;

        default:

            cout << "invalid choice." << endl;
        }

    } while (choice != 5);


    return 0;
}