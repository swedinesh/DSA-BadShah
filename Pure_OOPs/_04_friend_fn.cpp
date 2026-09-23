#include <iostream>
using namespace std;

class Demo
{
    // no restiction for friend function
    // public and private
private:
    void sayHello()
    {
        cout << " Hello, Duniya" << endl;
    }
    // same as member function class ke bahar use kar skta
    // class ke bahar define karo aur main mai as a function call karo

    friend void f1(Demo);
};

class B; // defination
class A
{
private:
    int a, b;

public:
    void setA(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void getA()
    {
        cout << "a= " << a << " & b= " << b << endl;
    }

    void useclassB(B);
};

class B
{
private:
    int a, b;

public:
    void setB(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void getB()
    {
        cout << "a= " << a << " & b= " << b << endl;
    }

    friend void A::useclassB(B);
};

void A::useclassB(B obj)
{
    int sumA = a + obj.a;
    int sumB = b + obj.b;
    cout << "Sum_A is " << sumA << " & Sum_B is " << sumB << endl;
}

void f1(Demo D)
{
    D.sayHello();
}

// two and more classes ke private members and functions ko use karne ke liye
// friend function bhut usefull ho skta because ham kisi other class
// ke private member ko ek sath use kar paa rhe hai

class Q;
class P
{
private:
    int a, b;

public:
    P(int a, int b) : a(a), b(b)
    {
    }

private:
    void show()
    {
        cout << a << " & " << b << endl;
    }

    friend void f1(P, Q);
};

class Q
{
private:
    int a, b;

public:
    Q(int a, int b) : a(a), b(b)
    {
    }

private:
    void show()
    {
        cout << a << " & " << b << endl;
    }

    friend void f1(P, Q);
};

void f1(P o1, Q o2) 
{
    int sum = o1.a + o1.b + o2.a + o2.b;
    o1.show();
    o2.show();
    cout<<" All numbers Sum is "<<sum<<endl;
}

int main()
{

    P o1(5,5);
    Q o2(10,10);

    f1(o1, o2);
    
    // Demo d;
    // f1(d);

    // A a1;
    // a1.setA(10, 10);
    // B b1;
    // b1.setB(5, 5);
    // a1.getA();
    // b1.getB();

    // a1.useclassB(b1);

    return 0;
}