#include <iostream>
using namespace std;

class Stack
{

private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    Stack(int capacity)
    {
        size = capacity;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int val)
    {
        if ((top1 == size - 1) || (top2 - top1 == 1))
        {
            cout << endl<<"Stack 1 is Overflow" <<"& Top1 : "<<top1<<endl<< endl;
            return;
        }
        top1++;
        arr[top1] = val;
    }

    void push2(int val)
    {
        if ((top2 == 0) || (top2 - top1 == 1))
        {
            cout << "Stack 2 is Overflow" <<"& Top2 : "<<top2<<endl<< endl;
            return;
        }
        top2--;
        arr[top2] = val;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is Underflow" << endl;
            return;
        }

        arr[top1] = -1;
        top1--;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack 1 is Underflow" << endl;
            return;
        }

        arr[top2] = -1;
        top2++;
    }

    void display()
    {

        for (int i = size - 1; i >= 0; i--)
        {
            if (top1 == i)
                cout << "          [    " << arr[i] << "    ]" << " -->top1" << endl;
            else if (top2 == i)
                cout << "          [    " << arr[i] << "    ]" << " -->top2" << endl;

            else
                cout << "          [    " << arr[i] << "    ]" << endl;
        }
    }
};

int main()
{

    Stack *s = new Stack(8);

    s->push1(10);
    s->push2(1);
    s->push1(20);
    s->push2(2);
     s->push1(30);
    s->push2(3);
     s->push1(40);
    s->push2(4);
     s->push1(50);
    s->push2(5);

    s->pop1();
    s->pop2();

    s->pop1();
    s->pop2();

    s->pop1();
    s->pop2();

    s->display();
     
    return 0;
}