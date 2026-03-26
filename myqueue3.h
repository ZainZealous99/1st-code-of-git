#ifndef MYQUEUE3_H
#define MYQUEUE3_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename t>
class myqueue3 
{
private:
    queue<t> q;

public:
    void enqueue(t value) 
    {
        q.push(value);
    }

    t dequeue() {
        if (q.empty()) 
        {
            cout << "queue underflow!" << endl;
            return t();
        }
        t value = q.front();
        q.pop();
        return value;
    }

    t front() 
    {
        if (q.empty()) 
        {
            cout << "queue is empty!" << endl;
            return t();
        }
        return q.front();
    }

    bool isempty() 
    {
        return q.empty();
    }

    int size() 
    {
        return q.size();
    }

    void display()
    {
        queue<t> temp = q;
        while (!temp.empty()) 
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void reversek(int k) 
    {
        if (k <= 1 || q.empty()) 
        {
            return;
        }

        int n = q.size();
        if (k > n) 
        {
            k = n;
        }

        stack<t> s;

        for (int i = 0; i < k; i++)
        {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) 
        {
            q.push(s.top());
            s.pop();
        }

        for (int i = 0; i < n - k; i++) 
        {
            q.push(q.front());
            q.pop();
        }
    }
};

#endif#pragma once
