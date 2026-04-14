#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct package 
{
    int id;
    string address;
    int starttime;
    int endtime;
};

int main() 
{
    queue<package> packages;
    int choice;
    int id;
    int starttime;
    int endtime;
    int currenttime;
    string address;

    do 
    {
      
        cout << "........delivery system menu........." << endl;
        cout << "1 add package" << endl;
        cout << "2 process package" << endl;
        cout << "3 check next package" << endl;
        cout << "4 display all packages" << endl;
        cout << "5 check time to deliver" << endl;
        cout << "exit" << endl;

        cout << "Enter the choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            cout << "enter package id ";
            cin >> id;
            cin.ignore();

            cout << "enter address ";
            getline(cin, address);

            cout << "enter start time ";
            cin >> starttime;

            cout << "enter end time ";
            cin >> endtime;

            packages.push({ id, address, starttime, endtime });
            cout << "package " << id << " added to queue." << endl;
            break;

        case 2:
            if (packages.empty()) 
            {
                cout << "queue is empty" << endl;
            }
            else 
            {
                package p = packages.front();
                packages.pop();
                cout << "package " << p.id << " processed and removed from queue" << endl;
            }
            break;

        case 3:
            if (packages.empty())
            {
                cout << "queue is empty" << endl;
            }
            else 
            {
                package p = packages.front();
                cout << "next package id: " << p.id<< " address: " << p.address<< " window: " << p.starttime << "-" << p.endtime << endl;
            }
            break;

        case 4:
            if (packages.empty()) 
            {
                cout << "queue is empty" << endl;
            }
            else 
            {
                queue<package> temp = packages;
                cout << "packages in queue" << endl;
                while (!temp.empty()) {
                    package p = temp.front();
                    cout << "id: " << p.id<< " address: " << p.address<< " window: " << p.starttime << "-" << p.endtime << endl;
                    temp.pop();
                }
            }
            break;

        case 5:
            if (packages.empty()) 
            {
                cout << "queue is empty" << endl;
            }
            else 
            {
                cout << "enter current time ";
                cin >> currenttime;
                while (!packages.empty()) 
                {
                    package p = packages.front();
                    if (currenttime >= p.starttime && currenttime <= p.endtime) 
                    {
                        cout << "package " << p.id << " can be delivered now" << endl;
                        break;
                    }
                    else if (currenttime > p.endtime) 
                    {
                        cout << "package " << p.id << " expired skipping" << endl;
                        packages.pop();
                    }
                    else 
                    {
                        cout << "package " << p.id << " delivery not yet available" << endl;
                        break;
                    }
                }
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