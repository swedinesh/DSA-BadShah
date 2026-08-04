#include <iostream>
using namespace std;

class Cqueue
{
private:
    int *arr;
    int size;
    int front;
    int rear;
    int len;

public:
    Cqueue(int cap)
    {
        size = cap;
        arr = new int[size];
        front = rear = -1;
        len = 0;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        // overflow normal + circular
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Circular Queue is Overflow!.." << endl;
        }
        // empty queue
        else if (isEmpty())
        {
            rear++;
            front++;
            arr[rear] = val;
            len++;
        }
        // circular insertion
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = val;
            len++;
        }
        // normal insert
        else
        {
            rear++;
            arr[rear] = val;
            len++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is Underflow!.." << endl;
        }
        // last ele normal way pop
        else if (rear == front)
        {
            arr[front] = -1;
            rear = front = -1;
            len--;
        }
        // circular way pop
        else if (rear < front && front == size - 1)
        {
            arr[front] = -1;
            front = 0;
            len--;
        }
        else
        {
            arr[front] = -1;
            front++;
            len--;
        }
    }

    // int getSize()
    // {
    //     return len;
    // }
    
    int getSize(){
    
        /*
        1. empty  gsize = 0;
        2. normal front <= rear  gsize = rear - front + 1;
        3. circular rear<front  gsize = size-front+rear+1;
        */
        
      if(isEmpty())
      return 0;

      else if(front<=rear)
      return rear - front + 1;

      else{
        return size - front + rear + 1;
      }
    }
    
    void getFront()
    {
        cout << "Front element and index is : " << arr[front] << " & " << front << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Cqueue cq(5);

    cout << "CQueue size : " << cq.getSize() << endl;
    cq.push(10);
    cq.print();
    cq.push(20);
    cq.print();
    cq.push(30);
    cq.print();
    cq.push(40);
    cq.print();
    cq.push(50);
    cq.print();
    cq.push(10);

    cq.getFront();
    cout << "CQueue size : " << cq.getSize() << endl;
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();

    cq.getFront();
    cout << "CQueue size : " << cq.getSize() << endl;
    cq.push(60);
    cq.print();
    cq.push(70);
    cq.print();

    cq.getFront();
    cout << "CQueue size : " << cq.getSize() << endl;
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();

    cq.getFront();
    cout << "CQueue size : " << cq.getSize() << endl;
    return 0;
}
