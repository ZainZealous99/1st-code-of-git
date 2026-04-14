#include <iostream>
using namespace std;

class mycarstack
{
private:
    string arr[8];
    int topindex;

public:
    mycarstack()
    {
        topindex = -1;
    }

    bool isempty()
    {
        return topindex == -1;
    }

    bool isfull()
    {
        return topindex == 7;
    }

    void push(string car)
    {
        if (isfull())
        {
            cout << "parking is full" << endl;
            return;
        }

        topindex++;
        arr[topindex] = car;

        cout << "car parked " << car << endl;
    }

    string pop()
    {
        if (isempty())
        {
            cout << "parking is empty" << endl;
            return "";
        }

        string car = arr[topindex];
        topindex--;

        return car;
    }

    string top()
    {
        if (isempty())
        {
            return "";
        }

        return arr[topindex];
    }

    int count()
    {
        return topindex + 1;
    }

    void display()
    {
        if (isempty())
        {
            cout << "no cars parked" << endl;
            return;
        }

        for (int i = topindex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    int search(string car)
    {
        for (int i = 0; i <= topindex; i++)
        {
            if (arr[i] == car)
            {
                return i;
            }
        }
        return -1;
    }

    void removecar(string car)
    {
        if (isempty())
        {
            cout << "parking is empty" << endl;
            return;
        }

        mycarstack temp;

        bool found = false;

        while (!isempty())
        {
            string topcar = pop();

            if (topcar == car)
            {
                found = true;
                cout << "car removed " << car << endl;
                break;
            }
            else
            {
                temp.push(topcar);
            }
        }

        while (!temp.isempty())
        {
            push(temp.pop());
        }

        if (!found)
        {
            cout << "car not found" << endl;
        }
    }
};

int main()
{
    mycarstack parking;

    int choice;
    string car;

    do
    {
        cout << endl;
        cout << "1 park car" << endl;
        cout << "2 remove car" << endl;
        cout << "3 show cars" << endl;
        cout << "4 total cars" << endl;
        cout << "5 search car" << endl;
        cout << "6 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter car number ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "enter car number ";
            cin >> car;
            parking.removecar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "total cars " << parking.count() << endl;
            break;

        case 5:
            cout << "enter car number ";
            cin >> car;

            if (parking.search(car) != -1)
                cout << "car found" << endl;
            else
                cout << "car not found" << endl;

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