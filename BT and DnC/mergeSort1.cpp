// #include <iostream>
// #include <vector>
// using namespace std;

// void mergeTwoArrays(vector<int> &arr, vector<int> &arr1, vector<int> &arr2);

// void mergeSort(vector<int> &arr)
// {
//     int n = arr.size();
//     // base case
//     if(n<=1) return;

//     vector<int> a;
//     a.resize(n/2);
//     vector<int> b;
//     b.resize(n-(n/2));
//     int k=0;
//     for(int i=0; i<a.size(); i++) a[i] = arr[k++];
//     for(int i=0; i<b.size(); i++) b[i] = arr[k++];

//     mergeSort(a);
//     mergeSort(b);
//     mergeTwoArrays(arr, a, b);
// }

// void mergeTwoArrays(vector<int> &arr, vector<int> &arr1, vector<int> &arr2)
// {
//     // old element ko clear taaki har baar new sorted arraye merge ho
//     arr.clear();

//     int i = 0;
//     int j = 0;
//     while (i < arr1.size() && j < arr2.size())
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr.push_back(arr1[i]);
//             i++;
//         }
//         else
//         {
//             arr.push_back(arr2[j]);
//             j++;
//         }
//     }

//     while (i < arr1.size())
//         arr.push_back(arr1[i++]);
//     while (j < arr2.size())
//         arr.push_back(arr2[j++]);
// }

// int main()
// {
//     vector<int> arr = {5, 7, 2, 4, 1, 3, 9, 8};
//     // vector<int> arr1 = {10, 20, 30, 40};
//     // vector<int> arr2 = {15, 25};

//     // mergeTwoArrays(arr, arr1, arr2);

//     mergeSort(arr);

//     for (int ele : arr)
//     {
//         cout << ele << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedArrays(vector<int> &arr, vector<int> &arr1, vector<int> &arr2)
{
    arr.clear();

    int i = 0, j = 0;
    int s1 = arr1.size();
    int s2 = arr2.size();
    // compair & coping

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
            arr.push_back(arr1[i++]);
        else
            arr.push_back(arr2[j++]);
    }

    // jiska size bada hoga usko uske saare element copy ho jayege
    while (i < s1)
        arr.push_back(arr1[i++]);
    while (j < s2)
        arr.push_back(arr2[j++]);
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    // single element always sorted
    if (n <= 1)
        return;

    // Two part mai karne ke liye half size ka two array banaya
    vector<int> arr1;
    arr1.resize(n / 2);
    vector<int> arr2;
    arr2.resize(n - (n / 2));

    int k = 0;
    // main array ka element two parts mai daalo
    for (int i = 0; i < arr1.size(); i++)
        arr1[i] = arr[k++];
    for (int i = 0; i < arr2.size(); i++)
        arr2[i] = arr[k++];

    // first part ko two parts mai divide karo
    mergeSort(arr1);
    // second part ko two parts mai divide karo
    mergeSort(arr2);

    // ab dono parts merge kardo
    mergeTwoSortedArrays(arr, arr1, arr2);
}

int main()
{

    vector<int> arr = {5, 7, 2, 4, 1, 3, 9, 8};

        mergeSort(arr);

        for (int ele : arr)
        {
            cout << ele << " ";
        }
        cout << endl;

    return 0;
}