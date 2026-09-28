#include <iostream>
using namespace std;

void insertion(int *arr, int n)
{
    if (n <= 1)
        return;

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
           swap(arr[j], arr[j-1]);
           j--;
        }
    }
}

int main()
{
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(int);
    cout << "Before Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    insertion(arr, n);
    cout << "\nAfter Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}

/*
Insertion Sort
5 4 3 2 1
5 | 4 3 2 1
4 5 | 3 2 1
3 4 5 | 2 1
2 3 4 5 | 1
1 2 3 4 5 | out of bound

Logic is
outer loop start with 1st index
for sorting loop inserting loop means element ko uski shi position par inser karo
inner Loop compare with previous element if greater then previos par move karte jao

sudo:
Outer Loop i=1 to n-1
temp variable j = i
inner loop while(j >0 && arr[j] < arr[j-1])
   swap(arr[j], arr[j-1])
   j--

*/