#include <iostream>
using namespace std;

class MyDeque
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    MyDeque(int capacity)
    {
        size = capacity;

        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
            return true;
        else
            return false;
    }

    void pushFront(int val)
    {
        if (front == 0)
        {
            cout << "DeQue Front is overflow!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front++;
            rear++;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }

    void pushBack(int val)
    {
        if (rear == size - 1)
        {
            cout << "DeQue Back is overflow!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "DeQue Front is UnderFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "DeQue Back is UnderFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
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

    MyDeque dq(7);
    dq.print();

    dq.pushFront(10);
    dq.pushBack(12);
    dq.pushBack(14);
    dq.pushBack(16);
    dq.print();

    dq.popFront();
    dq.print();

    dq.popBack();
    dq.print();

    dq.pushFront(100);
    dq.print();

    dq.pushBack(200);
    dq.print();

    return 0;
}