#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    if (size == 0)
        return;
    print(arr, size - 1);
    cout << arr[size - 1] << " ";
}

void printRe(int *arr, int size)
{
    if (size == 0)
        return;
    cout << arr[size - 1] << " ";

    printRe(arr, size - 1);
}

int searchInArray(int *arr, int size, int target, int index)
{
    if (index >= size)
        return -1;
    else if (arr[index] == target)
        return index;
    return searchInArray(arr, size, target, index + 1);
}

int minimum(int *arr, int size, int index, int min)
{
    if (index >= size)
        return min;
    if (min > arr[index])
        min = arr[index];
    return minimum(arr, size, index + 1, min);
}

int maximum(int *arr, int size, int index, int max)
{
    if (index >= size)
        return max;
    if (max < arr[index])
        max = arr[index];
    return maximum(arr, size, index + 1, max);
}

int main()
{
    int arr[] = {10, 20, 30, 40, -6};
    // print(arr,5);
    // cout<<endl;
    // printRe(arr,5);
    // cout<<endl;
    cout << "target : " << searchInArray(arr, 5, 40, 0);
    cout << endl;
    cout << "Minimum : " << minimum(arr, 5, 0, arr[0]) << endl;
    cout << "Maximum : " << maximum(arr, 5, 0, arr[0]) << endl;
    return 0;
}