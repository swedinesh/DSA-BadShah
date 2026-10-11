#include <iostream>
using namespace std;

// dimond of death problem
// class A
// {
// public:
//     void f1()
//     {
//         cout << "F1 class A" << endl;
//     }
// };
// class B1 : public A
// {
// public:
//     void f2()
//     {
//         cout << "F2 class B1" << endl;
//     }
// };
// class B2 : public A
// {
// public:
//     void f3()
//     {
//         cout << "F3 class B2" << endl;
//     }
// };
// class C : public B1, public B2
// {
// public:
//     void f4()
//     {
//         cout << "F4 class C" << endl;
//     }
// };

class A
{
public:
    void f1()
    {
        cout << "F1 class A" << endl;
    }
};
class B1 : virtual public A
{
public:
    void f2()
    {
        cout << "F2 class B1" << endl;
    }
};
class B2 : virtual public A
{
public:
    void f3()
    {
        cout << "F3 class B2" << endl;
    }
};
class C : public B1, public B2
{
public:
    void f4()
    {
        cout << "F4 class C" << endl;
    }
};

int main()
{
    C obj;
    obj.f4();
    obj.f2();
    obj.f3();
    //obj.f1(); // two path are B1 ans B2 then samjh 
    //nhi paya kis path bala f1 select karu

    // use virtual class parent class of same level class

    obj.f1();


    return 0;
}