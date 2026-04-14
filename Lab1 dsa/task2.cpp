#include <iostream>
using namespace std;

template <class t>
void printarray(t arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class t>
void selectionsort(t arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallsub = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallsub])
            {
                smallsub = j;
            }
        }

        t temp = arr[i];
        arr[i] = arr[smallsub];
        arr[smallsub] = temp;
    }
}

int main()
{
    int intarray[5] = { 64 , 25 , 12 , 22 , 11 };

    cout << "original integer array: ";
    printarray(intarray, 5);

    selectionsort(intarray, 5);

    cout << "sorted integer array: ";
    printarray(intarray, 5);

    string stringarray[4] = { "apple" , "orange" , "banana" , "grape" };

    cout << endl << "original string array: ";
    printarray(stringarray, 4);

    selectionsort(stringarray, 4);

    cout << "sorted string array: ";
    printarray(stringarray, 4);

    return 0;
}