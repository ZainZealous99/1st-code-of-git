#ifndef MYQUEUE2STACK_H
#define MYQUEUE2STACK_H

#include <iostream>
#include <stack>
using namespace std;

template <typename t>
class myqueue2stack 
{
private:
    stack<t> s1;
    stack<t> s2;

    void transfer() 
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(t value) 
    {
        s1.push(value);
        cout << value << "inserted into queue" << endl;
    }

    t dequeue() 
    {
        if (s1.empty() && s2.empty()) 
        {
            cout << "queue underflow" << endl;
            return t();
        }

        if (s2.empty()) 
        {
            transfer();
        }

        t value = s2.top();
        s2.pop();
        return value;
    }

    t front() 
    {
        if (s1.empty() && s2.empty())
        {
            cout << "queue is empty!" << endl;
            return t();
        }

        if (s2.empty()) 
        {
            transfer();
        }

        return s2.top();
    }

    void display() 
    {
        if (s1.empty() && s2.empty())
        {
            cout << "queue is empty!" << endl;
            return;
        }

        stack<t> temp1 = s1;
        stack<t> temp2 = s2;

        if (!temp2.empty()) 
        {
            stack<t> rev;
            while (!temp2.empty())
            {
               cout<< rev.push(temp2.top());
                cout<<temp2.pop();
            }
            while (!rev.empty()) 
            {
                cout << rev.top() << " ";
               cout<< rev.pop();
            }
        }

        stack<t> rev2;
        while (!temp1.empty()) 
        {
            cout<<rev2.push(temp1.top());
            cout<<temp1.pop();
        }
        while (!rev2.empty())
        {
            cout << rev2.top() << " ";
            cout<<rev2.pop();
        }

        cout << endl;
    }
};

#endif#pragma once
