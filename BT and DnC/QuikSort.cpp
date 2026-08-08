// #include <iostream>
// #include <vector>
// using namespace std;

// int partition(int l, int h, vector<int> &arr)
// {

//     int i = l;
//     int j = h;
//     int pivot = arr[l];

//     while (i < j)
//     {
//         do
//         {
//             i++;
//         } while(i < h && arr[i] <= pivot);

//         do
//         {
//             j--;
//         } while (arr[j] > pivot);
//         if (i < j)
//             swap(arr[i], arr[j]);
//     }

//     swap(arr[l], arr[j]);

//     return j;
// }

// void quickSort(int l, int h, vector<int> &arr)
// {
//     if (l < h)
//     {
//         int j = partition(l, h, arr);
//         quickSort(l, j, arr);
//         quickSort(j + 1, h, arr);
//     }
// }

// int main()
// {
//     vector<int> arr = {10, 9, 8, 7, 4, 2, 1, 5, 19, 34, 3, 17, 13};
//     // {6, 5, 8, 9, 3, 10, 15, 12, 16};
//     int l = 0;
//     int h = arr.size();

//     quickSort(l, h, arr);

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

int partition(vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        // jab tak pivot se bada = element na mile tab tak chalao
        // jab tak arr[i] < hai tab tak aage badao
        do
        {
            i++;
        } while (i < h && arr[i] <= pivot);
        // jab tak pivot se chhota element na mile tab tak chalao
        do
        {
            j--;
        } while (arr[j] > pivot);
        
        // valid number find all of array
        if(i<j) swap(arr[i], arr[j]);
    }
    // at the j is reached original pivot location
    // swap low(pivot) with j index
    swap(arr[l], arr[j]);
    
    // return pivot partition index
    return j;
}

void quickSortNew(vector<int>& arr, int l, int h){
    if(l>=h) return;

    int j = partition(arr, l, h);

    // left ka partition karke pivot ko sort karo
    quickSortNew(arr, l, j);
    
    // right ka partition karke pivot ko sort karo
    quickSortNew(arr, j+1, h);
}

int main(){
    vector<int> arr = {3, 1, 9, 5, 4, 11, 21, 10, 2, 7, 6};
    int l=0;
    int h=arr.size();
    quickSortNew(arr, l, h);

    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}