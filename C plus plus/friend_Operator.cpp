#include<iostream>
using namespace std;

class Complex{

    private:
    int a, b;
    public:
    void set(int x, int y){ a = x; b = y;}
    void show(){ cout<<"a = "<<a<<"  b = "<<b<<endl;}

    //  Complex operator+(Complex c){
    //       Complex temp;
    //       temp.a = a + c.a;
    //       temp.b = b + c.b;
    //       return temp;
    //  }

     friend Complex operator+(Complex, Complex);
     friend Complex operator-(Complex);
     friend Complex operator+(int, Complex);
    
};

Complex operator+(Complex x, Complex y){

    Complex temp;
    temp.a = x.a + y.a;
    temp.b = x.b + y.b;
    return temp;

}

Complex operator-(Complex c){

    Complex temp;
    temp.a = -c.a;
    temp.b = -c.b;
    return temp;
}

Complex operator+(int x, Complex c){

    Complex temp;
    temp.a = x + c.a;
    temp.b = x + c.b;
    return temp;

}




int main(){

    Complex c1, c2, c3, c4, c5;

    c1.set(10,20);
    c2.set(30,40);

    c3 = c1+c2; // c3 = c1.operator+(c2);
    c3.show();
    
    c4 = -c3;
    c4.show();
    
    //real example of why use friend function
     c5 = 9 + c4;
     c5.show();
     
    return 0;
}