#include <iostream>
#include "myqueue3.h"
using namespace std;

int main() 
{
    myqueue3<int> q;

    int n;
    int value;
    int k;

    cout << "enter number the elements: ";
    cin >> n;

    cout << "enter the elements: ";

    for (int i = 0; i < n; i++) 
    {
        cin >> value;
        q.enqueue(value);
    }

    cout << "queue: ";
    q.display();

    cout << "enter the k";
    cin >> k;

    q.reversek(k);

    cout << "output is this";
    q.display();

    return 0;
}