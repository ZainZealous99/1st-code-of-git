#include <iostream>
#include <string>
using namespace std;

template <typename t>
int linearsearch(t arr[], int size, t key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

template <typename t>
void printsearchresult(int index, t key)
{
    if (index != -1)
        cout << "value " << key << " found at index: " << index << endl;
    else
        cout << "value " << key << " not found." << endl;
}

int main()
{
    int intarray[5] = { 64, 25, 12, 22, 11 };
    int intkey = 12;
    int intindex = linearsearch(intarray, 5, intkey);
    printsearchresult(intindex, intkey);

    float floatarray[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatkey = 1.62;
    int floatindex = linearsearch(floatarray, 4, floatkey);
    printsearchresult(floatindex, floatkey);

    string stringarray[4] = { "apple", "orange", "banana", "grape" };
    string stringkey = "banana";
    int stringindex = linearsearch(stringarray, 4, stringkey);
    printsearchresult(stringindex, stringkey);

    return 0;
}