#include <iostream>
using namespace std;

class A
{
public:
    int a, b;
    A()
    {
        cout << "Default Constructor is ON\n";
    }
    A(int x)
    {
        a = x;
    }
    A(int x, int y)
    {
        a = x;
        b = y;
    }
    // copy constructor same as default copy constructor
    //  ek bhi constructor banaya then koi bhi defualt constructor
    //  nhi banega

    A(A &c)
    {
        a = c.a;
        b = c.b;
    }
    void show()
    {
        cout << "a= " << a << " b= " << b << endl;
    }
};

int main()
{
    A a1, a2(5), a3(5, 10);

    A s1 = a1;
    A s2 = a2;
    A s3 = a3;

    a1.show();
    a2.show();
    a3.show();

    s1.show();
    s2.show();
    s3.show();
    
    return 0;
}