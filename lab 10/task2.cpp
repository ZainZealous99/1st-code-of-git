#include <iostream>
#include <string>
using namespace std;

bool palindrome(string str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }
    return palindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    cout << "enter a string";
    cin >> str;

    if (palindrome(str, 0, str.length() - 1))
    {
        cout << "string is palindrome" << endl;
    }
    else
    {
        cout << "string is not palindrome" << endl;
    }
    return 0;
}