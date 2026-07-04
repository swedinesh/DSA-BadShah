/*
Can Not Overload

.member
.* pointer to member access
:: scope resolution
?: conditinal operator
sizeof

*/

#include<iostream>
using namespace std;

class Complex{
public: 
int a, b;

Complex(){

}

Complex add(const Complex c){
     Complex temp;
     temp.a = a + c.a;
     temp.b = b + c.b;
     return temp;
}

Complex operator+(const Complex c){
     Complex temp;
     temp.a = a + c.a;
     temp.b = b + c.b;
     return temp;
}

Complex operator-(){
     Complex temp;
      temp.a = -a;
      temp.b = -b;
     return temp;
}

void set(int a, int b){
    this->a = a;
    this->b = b;
}
void show(){
    cout<<"a : "<<a<<" &  b : "<<b<<endl;
}



};

int main(){
    Complex c1,c2,c3;
    c1.set(5,6);
    c2.set(5,4);
    c3 = c1.add(c2);

    c1.show();  
    c2.show();
    c3.show();

    Complex c4 = c2 + c3;
    // Complex c4 = c2.operator+(c3);
    c4.show();
    
    Complex c5 =-c4;

    c5.show();
    
    return 0;
}