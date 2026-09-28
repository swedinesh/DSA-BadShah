#include <iostream>
using namespace std;

void bubble(int *arr, int n)
{
    
for(int i=0; i<n-1; i++)
{
    bool flag = true;
    for(int j=0; j<n-i-1; j++)
    {
       if(arr[j] > arr[j+1])
       {
        swap(arr[j], arr[j+1]);
        flag = false;
       }
    }
    if(flag) break;
}
}
int main()
{
    int arr[] = {5, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << "Before Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    bubble(arr, n);
    cout << "\nAfter Sorting" << endl;
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout<<endl;

    return 0;
}

/*
i = 0
5 4 3 2 1 , j = 0
4 5 3 2 1 , j = 1
4 3 5 2 1 , j = 2
4 3 2 5 1 , j = 3
4 3 2 1 5

i = 1
4 3 2 1 5 , j = 0
3 4 2 1 5 , j = 1
3 2 4 1 5 , j = 2
3 2 1 4 5 , 

i = 2
3 2 1 4 5 , j = 0
2 3 1 4 5 , j = 1
2 1 3 4 5

i = 3
2 1 3 4 5 , j = 0
1 2 3 4 5

*/