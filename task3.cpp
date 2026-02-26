#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallSub = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallSub])
            {
                smallSub = j;
            }
        }

        if (smallSub != i)
        {
            T temp = arr[i];
            arr[i] = arr[smallSub];
            arr[smallSub] = temp;
        }
    }
}

int main()
{
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intSize = 5;

    cout << "Original integer array: ";
    printArray(intArray, intSize);

    selectionSort(intArray, intSize);

    cout << "Sorted integer array: ";
    printArray(intArray, intSize);

    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    int stringSize = 4;

    cout << "Original string array: "<<endl;
    printArray(stringArray, stringSize);

    selectionSort(stringArray, stringSize);

    cout << "Sorted string array: ";
    printArray(stringArray, stringSize);

    return 0;
}