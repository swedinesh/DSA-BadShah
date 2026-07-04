/*
=========================================
SHALLOW COPY
=========================================

Definition

Shallow Copy sirf pointer ki value copy karta hai.

Actual memory copy nahi hoti.

Result:
Dono objects SAME memory ko point karte hain.

Problem

Ek object agar memory change kare
to dusre object me bhi change dikhega.

Aur delete karne par Double Delete Error aa sakta hai.

Real Life Example

Ek hi ghar ki do chabiyan nahi...

Balki dono log ek hi original chabi pakde hue hain.

Chabi ek hi hai.

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
    }

    void display()
    {
        cout << "Marks = " << *marks << endl;
    }
};

int main()
{
    Student s1(95);

    // Default Copy Constructor
    Student s2 = s1;

    *s2.marks = 50;

    cout << "Student 1\n";
    s1.display();

    cout << "Student 2\n";
    s2.display();

    // Destructor intentionally omitted
}