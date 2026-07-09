/*
Dynamic Memory mai by default ZERO pada hota (garbage nhi hota).
*/

#include <iostream>
using namespace std;

class Stack
{

    int size;
    int *arr;
    int top;

public:
    // memory allocation
    Stack(int capacity)
    {
        size = capacity;
        arr = new int[size];
        top = -1;
    }

    // push
    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack is Overflow...Sorry!" << endl
                 << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    // pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is UndreFlow...Sorry!" << endl
                 << endl;
            return;
        }
        else
        {
            arr[top] = -1;
            top--;
        }
    }

    // display
    void display()
    {

        if (top == -1)
        {
            cout << "Stack is UndreFlow...Sorry!" << endl;
            return;
        }

        for (int i = size-1; i >= 0; i--)
        {
            if (top == i)
                cout << "          [    " << arr[i] << "    ]" << " -->top" << endl;
            else if (i == 0)
                cout << "Bottom--> " << "[    " << arr[i] << "    ]" << endl;
            else
                cout << "          [    " << arr[i] << "    ]" << endl;
        }
    }

    // stack size
    int getSize()
    {
        return top + 1;
    }

    // check empty
    bool isEmpty()
    {

        if (top == -1)
            return true;
        else
            false;
    }

    // hame top dedo
    int getTop()
    {
        if (top == -1)
        {
            cout << "There is no element at the top, as stack is Empty!..";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{

    Stack *s = new Stack(5);

    s->display();
    cout << endl
         << endl;

    s->push(10);
      s->display();
    cout << endl
         << endl;
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);

    s->display();
    cout << endl
         << endl;

    s->pop();
    s->display();
    cout << endl
         << endl;

    s->pop();
    s->display();
    cout << endl
         << endl;

    s->pop();
    s->display();
    cout << endl
         << endl;

    s->pop();
    s->display();
    cout << endl
         << endl;

    s->pop();
    // s->display();
    cout << endl
         << endl;

    s->pop();

    // cout<<s->isEmpty()<<endl;

    s->push(10);
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);

    s->display();
    cout << endl
         << endl;

    s->push(70);

    cout << s->getSize() << endl;
    cout << s->getTop() << endl;

    return 0;
}