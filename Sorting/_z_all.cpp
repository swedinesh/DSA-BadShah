#include <iostream>
#include <vector>
using namespace std;

class AllinSort
{
    // counting sort
    /*
    Algorithm
    1. find largest element for range of count array
    2. create count size of K and initial all zero
    3. traverse array and count[arr->element]++
    4. count ka cumulative frequency nikalo count+=count start index with 1
    why findind c.f. because hame element ka position find karna hai
    like jiske bah desire position par pahunch posi is greater then index
    so pehle position ko 1 minus karo then move store
    5. create temp array for temperay sorted using positio method array traverse
    n to 0 jisse stable rhe
    6. temp ko original mai copy karo
    # T.C. = O(n+k);
    # space = O(n+k)
    */
public:
    void countingSort(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n <= 1)
            return;

        // create count array
        vector<int> count(k, 0);

        // store frequence of elements
        for (int i = 0; i < n; i++)
        {
            ++count[arr[i]];
        }

        // cumulative fequency for element ki location
        for (int i = 1; i < k; i++)
        {
            count[i] += count[i - 1];
        }

        // temp mai copy at position index
        vector<int> temp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            temp[--count[arr[i]]] = arr[i];
        }

        // copy to original array
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }

};

int main()
{
    AllinSort s;
    vector<int> arr = {4,1,1,3,4,5,2,2,7,8,9,9,8};
    int k = 9 + 1;
    s.countingSort(arr,k);
    for(auto ele : arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}