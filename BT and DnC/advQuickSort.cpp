#include <bits/stdc++.h>
using namespace std;

void quickSortAdv(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int i = start - 1;
    int j = start;
    int pivot = end;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    // calling
    quickSortAdv(arr, start, i - 1);
    quickSortAdv(arr, i + 1, end);
}

int main()
{
    vector<int> arr = {1, 7, 3, 9, 5, 2, 8, 10, 6, 4};
      quickSortAdv(arr,0,arr.size()-1);

      for(auto ele : arr){
        cout<<ele<<" ";
      }
      cout<<endl;
    return 0;
}