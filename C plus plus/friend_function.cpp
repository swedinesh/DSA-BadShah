/*
Friend Function

-Friend Function is not a member of a class 
to which it is a friend

-function which is friend to a class can access 
any member of the class (private, protect, or public)

-Fumction Need to be declared with friend keyword in the 
class to which we want to make it a friend 

-Friend function is define outside the class without 
membership lebel as it is not a member function

-friend function other class ka member function ho sakta hai
so membership label is required while defining outside ll the classes

*/

#include<iostream>
using namespace std;

class A{
private:
int a,b;
public:
void set(int x, int y){ a = x; b = y;}
void show(){ cout<<"a = "<<a<<"  b = "<<b<<endl;}
//class ke andar khin bhi declare kar skte hai
friend void f1(A);
};

// ye access kar rha private members ko a and b ko
void f1(A i){
int sum = i.a + i.b;
cout<<"sum = "<<sum<<endl;
}

class C;

class B{
public:

void f2(C);

};

class C{

private:
int a,b;
public:
void set(int x, int y){ a = x; b = y;}
void show(){ cout<<"a = "<<a<<"  b = "<<b<<endl;}
friend void B::f2(C);

};

void B::f2(C c){
    int sum = c.a + c.b;
    cout<<"sum = "<<sum<<endl;
}

// do class ka ek sath friend function
class Y;
class X{
friend void fun(X,Y);

};

class Y{
friend void fun(X,Y);
};

void fun(X x, Y y){

}


int main(){

    A i1,i2;
    i1.set(10,20);
    i2.set(30,40);
    
    f1(i1);
    f1(i2);

    C c1;
    c1.set(67, 76);

    B b1;
    b1.f2(c1);

    return 0;
}