/*
=========================================
DESTRUCTOR
=========================================

Definition

Destructor ek special function hai
jo object destroy hone par automatically call hota hai.

Syntax

~ClassName()

Rules

1. No Return Type
2. No Arguments
3. Sirf ek Destructor hota hai
4. Automatically Call Hota Hai

Use

Dynamic Memory Free Karna

Files Close Karna

Database Connection Close Karna

Network Connection Close Karna

Real Life Example

Constructor = Ghar Banana

Destructor = Ghar Todna aur Safai Karna

*/

#include <iostream>
using namespace std;

class Student
{
public:
    int *marks;

    Student(int m)
    {
        marks = new int(m);
        cout << "Constructor Called\n";
    }

    void display()
    {
        cout << "Marks = " << *marks << endl;
    }

    ~Student()
    {
        delete marks;
        cout << "Destructor Called\n";
    }
};

int main()
{
    Student s1(90);

    s1.display();

    cout << "Main Function End\n";
}