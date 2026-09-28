#include <iostream>
using namespace std;

void selection(int *arr, int n)
{
    if (n <= 1)
        return;
    
        for(int i=0; i<n-1; i++)
        {
            int mini = i;
            for(int j=i; j<n; j++)
            {
                if(arr[mini] > arr[j])
                  mini = j;
            }
            swap(arr[mini], arr[i]);
        }
   
}

int main()
{
    int arr[] = {17, 5, 9, 19, 55, 7, 43, 2, 3, 22, 4, 10, 6, 9, 9,9 , 10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(int);
    cout << "Before Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    selection(arr, n);
    cout << "\nAfter Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}