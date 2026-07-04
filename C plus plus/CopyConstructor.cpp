/*
=========================================
COPY CONSTRUCTOR
=========================================

Definition:
Copy Constructor ek special constructor hota hai jo ek object ki values
ko dusre object me copy karta hai.

Syntax:
ClassName(const ClassName &obj)

Compiler khud bhi copy constructor bana deta hai.
Lekin agar hame apna custom behavior chahiye to hum khud likhte hain.

Kab Call Hota Hai?

1. Object initialization
Student s2 = s1;

2. Object pass by value

3. Object return by value

Real Life Example

Original Book = s1
Photocopy of Book = s2

Book ka content same hai,
lekin dono books alag objects hain.

*/

#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;

    // Parameterized Constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    // Copy Constructor
    Student(const Student &obj)
    {
        cout << "Copy Constructor Called\n";

        name = obj.name;
        age = obj.age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

int main()
{
    Student s1("Dinesh",22);

    Student s2 = s1;

    cout << "\nObject 1\n";
    s1.display();

    cout << "\nObject 2\n";
    s2.display();
}
