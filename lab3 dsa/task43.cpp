#include <iostream>
using namespace std;

class texteditor
{
private:
    string text;

    string undostack[100];
    int utop;

    string redostack[100];
    int rtop;

public:
    texteditor()
    {
        text = "";
        utop = -1;
        rtop = -1;
    }

    void saveundo()
    {
        if (utop < 99)
        {
            utop++;
            undostack[utop] = text;
        }
    }

    void clearredo()
    {
        rtop = -1;
    }

    void addtext(string str)
    {
        saveundo();

        text = text + str;

        clearredo();

        cout << "text " << text << endl;
    }

    void deletechar()
    {
        if (text.length() == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        saveundo();

        text = text.substr(0, text.length() - 1);

        clearredo();

        cout << "text " << text << endl;
    }

    void undo()
    {
        if (utop == -1)
        {
            cout << "nothing to undo" << endl;
            return;
        }

        if (rtop < 99)
        {
            rtop++;
            redostack[rtop] = text;
        }

        text = undostack[utop];
        utop--;

        cout << "text " << text << endl;
    }

    void redo()
    {
        if (rtop == -1)
        {
            cout << "nothing to redo" << endl;
            return;
        }

        if (utop < 99)
        {
            utop++;
            undostack[utop] = text;
        }

        text = redostack[rtop];
        rtop--;

        cout << "text " << text << endl;
    }

    void show()
    {
        cout << "current text " << text << endl;
    }
};

int main()
{
    texteditor editor;

    int choice;
    string str;

    do
    {
        cout << endl;
        cout << "1 add text" << endl;
        cout << "2 delete last character" << endl;
        cout << "3 undo" << endl;
        cout << "4 redo" << endl;
        cout << "5 show text" << endl;
        cout << "6 exit" << endl;
        cout << "enter choice ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "enter text ";
            getline(cin, str);
            editor.addtext(str);
            break;

        case 2:
            editor.deletechar();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.show();
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