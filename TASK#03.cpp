#include <iostream>
#include <stack>
#include <string>
using namespace std;

class parkinglot 
{
private:
    stack<string> mycarstack;
    const int capacity = 8;

public:
    void parkcar(const string& carnumber) 
    {
        if (mycarstack.size() >= capacity) 
        {
            cout << "parking lot full cannot park more cars" << endl;
            return;
        }
        mycarstack.push(carnumber);
        cout << "car " << carnumber << "parked successfully." << endl;
    }

    void removecar(const string& carnumber) 
    {
        if (mycarstack.empty())
        {
            cout << "parking lot is empty." << endl;
            return;
        }

        stack<string> tempstack;
        bool found = false;

        while (!mycarstack.empty()) 
        {
            string topcar = mycarstack.top();
            mycarstack.pop();
            if (topcar == carnumber) 
            {
                found = true;
                cout << "car " << carnumber << " removed successfully." << endl;
                break;
            }
            else {
                tempstack.push(topcar);
            }
        }

        while (!tempstack.empty())
        {
            mycarstack.push(tempstack.top());
            tempstack.pop();
        }

        if (!found) 
        {
            cout << "car " << carnumber << "not found in the parking lot." << endl;
        }
    }

    void viewcars() 
    {
        if (mycarstack.empty()) 
        {
            cout << "parking lot is empty." << endl;
            return;
        }

        stack<string> tempstack = mycarstack;
        cout << "cars currently parked (from top to bottom)" << endl;
        while (!tempstack.empty())
        {
            cout << tempstack.top() << endl;
            tempstack.pop();
        }
    }

    void totalcars() 
    {
        cout << "total cars parked:" << mycarstack.size() << endl;
    }

    void searchcar(const string& carnumber) 
    {
        stack<string> tempstack = mycarstack;
        bool found = false;

        while (!tempstack.empty())
        {
            if (tempstack.top() == carnumber) 
            {
                found = true;
                break;
            }
            tempstack.pop();
        }

        if (found)
            cout << "car " << carnumber << "is present in the parking lot." << endl;
        else
            cout << "car " << carnumber << "not found in the parking lot." << endl;
    }
};

int main() {
    parkinglot lot;
    int choice;
    string carnumber;

    do {
        cout << "parking lot management" << endl;

        cout << "1.park a new car" << endl;
        cout << "2.remove a car by number" << endl;
        cout << "3.view parked cars" << endl;
        cout << "4.total cars parked" << endl;
        cout << "5.search for a car" << endl;
        cout << "6.exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            cout << "enter car number to park:";
            getline(cin, carnumber);
            lot.parkcar(carnumber);
            break;
        case 2:
            cout << "enter car number to remove:";
            getline(cin, carnumber);
            lot.removecar(carnumber);
            break;
        case 3:
            lot.viewcars();
            break;
        case 4:
            lot.totalcars();
            break;
        case 5:
            cout << "enter car number to search: ";

            getline(cin, carnumber);

            lot.searchcar(carnumber);
            break;
        case 6:
            cout << "exiting parking lot system." << endl;
            break;
        default:
            cout << "invalid choice! try again." << endl;
        }

    } while (choice != 6);

    return 0;
}