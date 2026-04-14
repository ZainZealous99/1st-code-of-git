#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct flight
{
    string id;
};

int main() 
{
    queue<flight> q1;
    queue<flight> q2;
    queue<flight> q3;
    int choice;

    while (true) 
    {
        cout << "1. add flight" << endl;
        cout << "2. land flight" << endl;
        cout << "3. exit" << endl;
        cout << "choice: ";
        cin >> choice;

        if (choice == 3)
        {
            break;
        }

        if (choice == 1)
        {
            string id;
            int type;
            cout << "id: ";
            cin >> id;
            cout << "type (1:emergency, 2:passenger, 3:cargo): ";
            cin >> type;
            flight f = 
            { 
                id 
            };
            if (type == 1) 
            {
                q1.push(f);
            }
            else if (type == 2)
            {
                q2.push(f);
            }
            else if (type == 3)
            {
                q3.push(f);
            }
        }
        else if (choice == 2) 
        {
            if (!q1.empty())
            {
                cout << "landing emergency: " << q1.front().id << endl;
                q1.pop();
            }
            else if (!q2.empty())
            {
                cout << "landing passenger: " << q2.front().id << endl;
                q2.pop();
            }
            else if (!q3.empty()) 
            {
                cout << "landing cargo: " << q3.front().id << endl;
                q3.pop();
            }
            else {
                cout << "no flights" << endl;
            }
        }
        else {
            cout << "invalid" << endl;
        }
    }

    return 0;
}