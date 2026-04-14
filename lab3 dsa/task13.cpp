#include <iostream>
using namespace std;

template < typename t >
class abstractstack
{
public:
    virtual void push(t value) = 0;
    virtual t pop() = 0;
    virtual t top() const = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractstack() {}
};

template < typename t >
class mystack : public abstractstack < t >
{
private:
    t* arr;
    int topindex;
    int maxsize;

public:
    mystack(int size)
    {
        maxsize = size;
        arr = new t[maxsize];
        topindex = -1;
    }

    void push(t value)
    {
        if (isfull())
        {
            cout << "stack is full" << endl;
            return;
        }

        topindex++;
        arr[topindex] = value;

        cout << "pushed " << value << endl;
    }

    t pop()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return t();
        }

        t value = arr[topindex];
        topindex--;

        return value;
    }

    t top() const
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return t();
        }

        return arr[topindex];
    }

    bool isempty() const
    {
        return topindex == -1;
    }

    bool isfull() const
    {
        return topindex == maxsize - 1;
    }

    void display() const
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return;
        }

        for (int i = topindex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~mystack()
    {
        delete[] arr;
    }
};

int main()
{
    int size;

    cout << "enter stack size ";
    cin >> size;

    mystack < int > s(size);

    int choice;
    int value;

    do
    {
        cout << endl;
        cout << "1 push" << endl;
        cout << "2 pop" << endl;
        cout << "3 top" << endl;
        cout << "4 display" << endl;
        cout << "5 exit" << endl;
        cout << "enter choice ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "popped " << s.pop() << endl;
            break;

        case 3:
            cout << "top " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}