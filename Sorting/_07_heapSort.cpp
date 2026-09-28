#include <iostream>
#include <vector>
using namespace std;

void printF(vector<int> &);

void maxHeapify(vector<int> &A, int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    // while(leftChild <= n && A[largest] < A[leftChild])
    // {
    //     largest = leftChild;
    // }
    // while(rightChild <= n && A[largest] < A[rightChild])
    // {
    //     largest = rightChild;
    // }
    if (leftChild <= n && A[largest] < A[leftChild])
        largest = leftChild;

    if (rightChild <= n && A[largest] < A[rightChild])
        largest = rightChild;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void buildHeap(vector<int> &A, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        maxHeapify(A, n, i);
    }
}

void buildArrayInHeap(vector<int> &A, int n)
{
    cout << " Enter Array of Elements : ";
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;
        A[i] = ele;
    }
    printF(A);
    buildHeap(A, n);
    printF(A);
    cout << endl;
}

void heapSort(vector<int>&A, int n)
{
  for(int i=n; i>0; i--)
  {
    swap(A[1], A[i]);
    maxHeapify(A,i-1,1);
  }
}

void printF(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of Heap : ";
    cin >> n;
    cout << endl;
    vector<int> A(n+1);
    buildArrayInHeap(A, n);
    heapSort(A,n);
    printF(A);
    cout << endl;
    return 0;
}