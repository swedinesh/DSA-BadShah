#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void set(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void show()
    {
        cout << "a= " << a << " b= " << b << endl;
    }

    // Complex operator+(Complex c)
    // {
    //     Complex temp;
    //     temp.a = a + c.a;
    //     temp.b = b + c.b;
    //     return temp;
    // }

    // friend function ka koi caller object nhi hota
    // so hame ek extra argument dena padta hai
    // operator overloading ke compresion mai

    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex);
    friend Complex operator+(int, Complex);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.a = c1.a + c2.a;
    temp.b = c2.b + c2.b;
    return temp;
}

Complex operator-(Complex c)
{
    Complex temp;
    temp.a = -c.a;
    temp.b = -c.b;
    return temp;
}
Complex operator+(int x, Complex c)
{
    Complex temp;
    temp.a = x + c.a;
    temp.b = x + c.b;
    return temp;
}

int main()
{
    Complex c1, c2, c3, c4, c5;
    c1.set(5, 3);
    c2.set(4, 5);

    c3 = c1 + c2;
    c1.show();
    c2.show();
    c3.show();
    c4 = -c3;
    c4.show();
    
    // ham normal value ko without friend function
    // add nhi kar skte because 4 ka koi caller Object nhi ho skta

    c4 = 4 + c4;
    c4.show();

    return 0;
}