#include <iostream>
using namespace std;


bool subsetSum(int arr[], int n, int target, int i)
{
    if (target == 0)
    {
        return true;
    }

    if (i == n || target < 0)
    {
        return false;
    }

    return subsetSum(arr, n, target - arr[i], i + 1) ||subsetSum(arr, n, target, i + 1);
}

int findMax(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int maxval = findMax(arr, n - 1);

    return (arr[n - 1] > maxval) ? arr[n - 1] : maxval;
}

int removeMaxRec(int arr[], int n, int maxval, int i, bool removed)
{
    if (i == n)
    {
        return n;
    }

    if (arr[i] == maxval && !removed)
    {
        arr[i] = arr[n - 1];
        return n - 1;
    }

    return removeMaxRec(arr, n, maxval, i + 1, removed);
}

int magicNumber(int arr[], int n)
{
    if (n == 0)
    {
        return -1;
    }

    int maxval = findMax(arr, n);

    if (subsetSum(arr, n, maxval, 0))
    {
        return maxval;
    }

    int newSize = removeMaxRec(arr, n, maxval, 0, false);

    return magicNumber(arr, newSize);
}

int main()
{
    int arr[] = { 2, 3, 5, 8, 13 };
    int n = 5;

    cout << magicNumber(arr, n) << endl;

    return 0;
}