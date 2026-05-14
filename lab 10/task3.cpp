#include <iostream>
using namespace std;


int maximum(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int maxvalue = maximum(arr, size - 1);

    if (arr[size - 1] > maxvalue)
    {
        return arr[size - 1];
    }

    return maxvalue;
}

int main()
{
    int arr[] = { 12, 5, 18, 7, 3 };
    int size = 5;

    cout << "maximum element :" << maximum(arr, size) << endl;

    return 0;
}