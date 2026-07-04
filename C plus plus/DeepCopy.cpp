/*
=========================================
DEEP COPY
=========================================

Definition

Deep Copy actual data ki NEW memory banata hai.

Har object ki apni memory hoti hai.

Isliye ek object change karne se
dusra object affect nahi hota.

Real Life Example

Original Book ki photocopy.

Ab dono ke pages alag hain.

Ek book par likhoge
to dusri book change nahi hogi.

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

    // Deep Copy Constructor
    Student(const Student &obj)
    {
        marks = new int;
        *marks = *obj.marks;
    }

    void display()
    {
        cout << "Marks = " << *marks << endl;
    }

    ~Student()
    {
        delete marks;
    }
};

int main()
{
    Student s1(90);

    Student s2 = s1;

    *s2.marks = 45;

    cout << "Student 1\n";
    s1.display();

    cout << "Student 2\n";
    s2.display();
}