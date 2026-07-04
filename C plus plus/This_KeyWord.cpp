
#include <iostream>
using namespace std;

class Complex
{

private:
    int a, b;

public:
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
    void show() { cout << "a = " << a << "  b = " << b << endl; }

    //  Complex operator+(Complex c){
    //       Complex temp;
    //       temp.a = a + c.a;
    //       temp.b = b + c.b;
    //       return temp;
    //  }

    Complex greater(Complex c)
    {

        if ((a + b) > (c.a + c.b))
            return *this;
        else
            return c;

    }
};

int main()
{
    Complex c1, c2, c3;

    c1.set(70, 15);
    c2.set(20, 25);

    c3 = c1.greater(c2);
    c3.show();

    return 0;
}