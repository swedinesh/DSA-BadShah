#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    int index;
    int size;
    int *A;
    Heap(int size)
    {
        this->size = size;
        A = new int[size];
        index = 0;
    }

    void heapify(int* A, int n, int i)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int largest = i;

        if(left <= n && A[largest] < A[left])
        largest = left;
        if(right <= n && A[largest] < A[right])
        largest = right;

        if(largest != i)
        {
            swap(A[largest], A[i]);
            heapify(A, n, largest);
        }
        else{
            return;
        }
    }

    void insert(int data)
    {
        if(index == size-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
        ++index;
        A[index] = data;

        // int child = index; // corrent node child and parent
        
        // while(child > 1)
        // {
        //     int parent = child/2;
        //     if(A[child] > A[parent])
        //     swap(A[child], A[parent]);

        //     child = parent;
        // }
    }

    void buildHeap()
    {
        for(int i=index/2; i>=1; i--)
        {
            heapify(A, index, i);
        }
    }

    void popH()
    {
     
     swap(A[1],A[index]);
     --index;
     heapify(A, index, 1);

    }

   void heapSort()
   {
    for(int i=index/2; i>=1; i--)
        {
            heapify(A, index, i);
        }
    for(int i=size-1; i>=1; i--)
    {
       swap(A[i], A[1]);
       heapify(A, i-1, 1); 
    }
    
   }

    void printF()
    {
        for(int i=0; i<size; i++)
        {
            if(i==0) cout<<"X ";
           else cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Heap h(6);
   
    h.insert(5);
    h.insert(20);
    h.insert(10);
    h.insert(15);
    h.insert(30);
    h.buildHeap();
    h.printF();
    h.heapSort();
    h.printF();

    // h.popH();
    // h.printF();
    // h.popH();
    // h.printF();
    //  h.popH();
    // h.printF();

    return 0;
}