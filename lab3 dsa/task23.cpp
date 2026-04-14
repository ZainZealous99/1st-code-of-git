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
    t* minarr;
    int topindex;
    int mintop;
    int maxsize;

public:
    mystack(int size)
    {
        maxsize = size;
        arr = new t[maxsize];
        minarr = new t[maxsize];
        topindex = -1;
        mintop = -1;
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

        if (mintop == -1 || value <= minarr[mintop])
        {
            mintop++;
            minarr[mintop] = value;
        }

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

        if (value == minarr[mintop])
        {
            mintop--;
        }

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

    t getmin() const
    {
        if (mintop == -1)
        {
            cout << "stack is empty" << endl;
            return t();
        }

        return minarr[mintop];
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
        delete[] minarr;
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
        cout << "1 push element" << endl;
        cout << "2 pop element" << endl;
        cout << "3 show top element" << endl;
        cout << "4 check empty" << endl;
        cout << "5 check full" << endl;
        cout << "6 display stack" << endl;
        cout << "7 show minimum element" << endl;
        cout << "8 exit" << endl;
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
            if (s.isempty())
                cout << "stack is empty" << endl;
            else
                cout << "stack is not empty" << endl;
            break;

        case 5:
            if (s.isfull())
                cout << "stack is full" << endl;
            else
                cout << "stack is not full" << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "minimum " << s.getmin() << endl;
            break;

        case 8:
            cout << "exiting" << endl;
            break;

        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 8);

    return 0;
}