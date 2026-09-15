#include <iostream>
using namespace std;

// Shalow Copy
class Complex
{
public:
    int a;
    int *p;

    Complex()
    {
        cout << "Default Constructor is On" << endl;

        p = new int(0); // ya koi default value
        a = 0;
    }

    Complex(int a, int pointer)
    {
        this->a = a;
        p = new int;
        *p = pointer;
    }

    void show()
    {
        cout << "a = " << a << " & " << "*p = " << (*p) << endl;
    }
    void set(int a, int b)
    {
        this->a = a;
        *p = b;
    }
};

class Deep
{
public:
    int a;
    int *p;

    Deep(){
      cout << "Default Constructor is On" << endl;
      a=0;
      p = new int(0);  
    }

    Deep(int a, int b){
        this->a = a;
        p = new int;
        *p = b;
    }

    void show(){
        cout<<"a= "<<a<<" & "<<"*p= "<<(*p)<<"\n";
    }
    void set(int a, int b){
        this->a = a;
        *p = b;
    }
    Deep(Deep& c){
       p = new int;
      *p = *(c.p);
       this->a = c.a;
    }
};

int main()
{
    // Complex c1, c2(10, 20);
    // Complex s1 = c2;

    cout<<"Shalow\n";
    Complex c1(19,29);
    c1.show();
    Complex s1 = c1;
    *s1.p = 35;
    c1.show();
    // c1.show();
    // s1.show();
    // s1.set(35,75);
    // c2.show();

    cout<<"\nDeep\n";
    Deep d1(81, 99);
    d1.show();
    Deep t1 = d1;
    *t1.p = 90;
    d1.show();


    // c1.show();
    // c2.show();
    // s1.show();

    // c2.set(90, 100);
    // c2.show();
    // s1.show();

    // s1.set(69, 69);
    // c2.show();
    // s1.show();

    // Deep p1,p2(10,20);
    // Deep d1 = p1;
    // Deep d2 = p2;

    // c1.show();
    // c2.show();
    // p1.show();
    // p2.show();


    // c2.set(90,100);
    // p2.show();
    // c2.show();

    // p2.set(69,69);
    // d2.show();

    

    return 0;
}