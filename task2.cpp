#include <iostream>
using namespace std;

template <typename t>

class mystack {
private:

    t* arr;
    t* minarr;
    int capacity;
    int topindex;
    int mintopindex;
public:

    mystack(int size) 
    {
        capacity = size;
        arr = new t[capacity];
        minarr = new t[capacity];
        topindex = -1;
        mintopindex = -1;
    }
    ~mystack()
    {
        delete[] arr;
        delete[] minarr;
    }

    void push(t value) 
    {
        if (topindex == capacity - 1) 
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[++topindex] = value;
        if (mintopindex == -1 || value <= minarr[mintopindex]) 
        {
            minarr[++mintopindex] = value;
        }
    }

    t pop() {
        if (topindex == -1) 
        {
            cout << "stack underflow" << endl;
            return t();
        }
        t popped = arr[topindex--];
        if (popped == minarr[mintopindex])
        {
            mintopindex--;
        }
        return popped;
    }

    t top() const 
    {
        if (topindex == -1) 
        {
            cout << "stack is empty" << endl;
            return t();
        }
        return arr[topindex];
    }

    t getmin() const
    {
        if (mintopindex == -1) 
        {
            cout << "stack is empty" << endl;
            return t();
        }
        return minarr[mintopindex];
    }

    bool isempty() const
    {
        return topindex == -1;
    }

    bool isfull() const 
    {

        return topindex == capacity - 1;
    }

    void display() const 
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "stack elements (top to bottom):" << endl;
        for (int i = topindex; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main() 
{
    int size;
    cout << "enter stack size: " << endl;
    cin >> size;

    mystack<int> stack(size);
    int choice, value;

    do {
        cout << endl;
        cout << "............................." << endl;
        cout << "1. push element" << endl;
        cout << "2. pop element" << endl;
        cout << "3. show top element" << endl;
        cout << "4. check if stack is empty" << endl;
        cout << "5. check if stack is full" << endl;
        cout << "6. display stack elements" << endl;
        cout << "7. show minimum element" << endl;
        cout << "8. exit" << endl;
        cout << "enter choice: " << endl;
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "enter value: " << endl;
            cin >> value;
            stack.push(value);
            break;
        case 2:
            cout << "popped element: " << stack.pop() << endl;
            break;
        case 3:
            cout << "top element: " << stack.top() << endl;
            break;
        case 4:
            cout << (stack.isempty() ? "stack is empty" : "stack is not empty") << endl;
            break;
        case 5:
            cout << (stack.isfull() ? "stack is full" : "stack is not full") << endl;
            break;
        case 6:
            stack.display();
            break;
        case 7:
            cout << "minimum element: " << stack.getmin() << endl;
            break;
        case 8:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 8);

    return 0;
}