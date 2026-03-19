#include <iostream>
#include "abstarct.h"

template <typename T>
class myStack : public AbstractStack<T> 
{
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~myStack() 
    {
        delete[] arr;
    }

    void push(T value) override 
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return T();
        }
        return arr[topIndex--];
    }

    T top() const override
    {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const override
    {
        return topIndex == -1;
    }

    bool isFull() const override {
        return topIndex == capacity - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack elements (Top to Bottom):" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};
