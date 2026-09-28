#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countSort(int *arr, int n, int k)
{
    // count array
    int c[k] = {0};
    // element frequence insert at index
    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }

    // cumulative frequence for position
    for (int i = 1; i < k; i++)
    {
        c[i] += c[i - 1];
    }

    // element push in temperary array in sorted way
    int temp[n];

    for (int i = n - 1; i >= 0; i--)
    {
        temp[--c[arr[i]]] = arr[i];
        /*
        last element or original array arr[i]
        arr[i] element postion c[arrarr[i]]
        position is greater then 1 of index --c[arrarr[i]]
        sstore element in original position temp[--c[arrarr[i]]] =  arr[i]

        */
    }

    // copy in original array

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int k = INT_MIN;

    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        if (k < arr[i])
            k = arr[i];
    }

    cout << "Before Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    // range k is 0 to 9 total 10
    countSort(arr, n, k+1);
    cout << "\nAfter Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}

