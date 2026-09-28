// Object pointer 
// How class member access p-> 

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
        cout << "a= " << a << " & b= " << b << endl;
    }
};

int main()
{
    Complex c;
    c.set(5,7);
    
    // jiss type ka pointer usi type ka address conten karta
    // so int a; int *p = &a; char ch ='n'; char *cp = &ch; so ...on
    
    // basically class bhi ek data type but uska type hmne decide jo class name hai
    // so pointer ka type usedefine type hoga
    

    Complex *p;
    p = &c;

    // p.show(); not allow
    // *p.show(); // because . operator ki predence jyada hota
    // so pehle call ho jayega but convert nhi ho payega means scope resolution
    // *p convert nhi ho payega c mai 
    // pehle ham scope resolution hone dete () se seperate karke
    // then . operator ko karte

    (*p).show();

    // and iska short cut hai
    // arrow use skte hai ->

    p->set(9,5);
    p->show();

    return 0;
}