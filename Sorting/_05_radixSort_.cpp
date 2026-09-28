#include <bits/stdc++.h>
using namespace std;


/*
T.C. = O(d*(n+k)) ; d is number of digits
Space = O(10+n) = O(n);

*/
void countingSortRadixVersion(vector<int>& arr, int pos, int n)
{
    vector<int> count(10,0);
   
    for(int i=0; i<n; i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    // cumulative
    for(int i=1; i<10; i++)
    {
        count[i]+=count[i-1];
    }
    // temp array
    vector<int> temp(n);

    // store element
    for(int i=n-1; i>=0; i--)
    {
        temp[--count[(arr[i]/pos)%10]] = arr[i];
    }
     
    // copy
    for(int i=0; i<n; i++)
    {
        arr[i] = temp[i];
    }
}

int max_digit(vector<int> &arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void radixSort(vector<int> &arr)
{
    int n = arr.size();
    int max = max_digit(arr, n);
    
    for(int pos=1; max/pos > 0; pos*=10)
    {
        countingSortRadixVersion(arr, pos, n);
    }
}

int main()
{
    vector<int> arr = {432,8,530,90,88,231,11,45,677,199};
    radixSort(arr);

    for(auto ele : arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
