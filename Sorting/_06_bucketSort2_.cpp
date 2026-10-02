#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// int max_digit(vector<float> &arr, int n)
// {
//     int max = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if (max < arr[i])
//             max = arr[i];
//     }
//     return max;
// }

void posBucket(vector<float>&A, int pos, int n)
{
    vector<vector<float>> bucket(10);
    for(int i=0; i<n; i++)
    {
         int digit = int(A[i] * pos) % 10;

        bucket[digit].push_back(A[i]);
    }
    
    int k = 0;

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<bucket[i].size(); j++)
        {
            A[k++] = bucket[i][j]; 
        }
    }
    
}

void bucketSort(vector<float>&A, int n)
{
    // int max = max_digit(A,n);
    for(int pos=10; pos<=1000; pos*=10)
    {
        posBucket(A, pos, n);
    }
}


void printF(vector<float> &arr)
{
    cout<<"Array Elements : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<float> A;
    int n;
    cout<<"Enter number of elements :";
    cin>>n;
    cout<<"Enter Array : ";
    for(int i=0; i<n; i++)
    {
        float ele;
        cin>>ele;
        A.push_back(ele);
    
    }
    cout<<"\n";
    printF(A);

    bucketSort(A,n);

    printF(A);

    return 0;
}

