#ifndef MYQUEUE4_H
#define MYQUEUE4_H

#include <iostream>
#include <queue>
using namespace std;

class myqueue4 
{
private:
    queue<int> q;

public:
    void enqueue(int ticketid) 
    {
        q.push(ticketid);
        cout << "ticket " << ticketid << " added to queue." << endl;
    }

    int dequeue() 
    {
        if (q.empty()) 
        {
            cout << "No tickets to resolve" << endl;
            return -1;
        }
        int ticketid = q.front();
        q.pop();
        cout << "ticket " << ticketid << " resolved everything" << endl;
        return ticketid;
    }

    int front() 
    {
        if (q.empty()) 
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q.front();
    }

    void display() 
    { 
        if (q.empty()) 
        {
            cout << "No pending tickets" << endl;
            return;
        }
        cout << "The pending tickets: ";

        queue<int> temp = q;

        while (!temp.empty()) 
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    bool isempty() 
    {
        return q.empty();
    }
};

#endif