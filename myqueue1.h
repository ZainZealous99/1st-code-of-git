#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "t1.h"
using namespace std;

template <typename t>
class myqueue : public abstractqueue<t> 
{
private:

    t* arr;
    int frontindex;
    int rearindex;
    int capacity;

public:
    myqueue(int size) 
    {
        capacity = size;
        arr = new t[capacity];
        frontindex = -1;
        rearindex = -1;
    }

    ~myqueue() 
    {
        delete[] arr;
    }

    bool isempty() const override 
    {
        return (frontindex == -1 || frontindex > rearindex);
    }

    bool isfull() const override 
    {
        return (rearindex == capacity - 1);
    }

    void enqueue(t value) override 
    {
        if (isfull()) 
        {
            cout << "queue overflow" << endl;
            return;
        }

        if (frontindex == -1)
            frontindex = 0;

        arr[++rearindex] = value;
        cout << value << " inserted into queue." << endl;
    }

    t dequeue() override 
    {
        if (isempty()) 
        {
            cout << "queue underflow" << endl;
            return t();
        }

        t value = arr[frontindex];
        frontindex++;
        return value;
    }

    t front() const override 
    {
        if (isempty()) 
        {
            cout << "queue is empty!" << endl;
            return t();
        }
        return arr[frontindex];
    }

    void display() const
    {
        if (isempty()) 
        {
            cout << "queue is empty!" << endl;
            return;
        }

        cout << "queue elements: ";

        for (int i = frontindex; i <= rearindex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif#pragma once
