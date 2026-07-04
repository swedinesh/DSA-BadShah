#include<iostream>
using namespace std;

class A{
    int a,b,c;
    const int k=b;
    int &y;
    public:
    // initiazer - preference bhi jyada hoti initilizer ki
    // A(int a, int b, int c) : a(a), b(b), c(c), k(a), y(b) 
    // {
    // yha y(b) bo jo constructor ka  b hai use point kar rha
    // construct khatam hote hi b lost y is dagling pointer
    // }

    // A(int a1, int b1, int c1) : a(a1), b(b1), c(c1), k(c), y(c)
    // {

    // }
          
    // initialize order mai karenge taaki use kar paye yha this corrent 
    // object ka c refer karega ab dagling nhi hoga 
       A(int a, int b, int c) : a(a), b(b), c(c), k(a), y(this->c) {}

    void showData(){
        cout<<"a, b & c : "<<a<<" "<<b<<" "<<c<<endl;
    }
    void showk(){
        cout<<"k : "<<k<<endl;
    }
    void showy(){
        cout<<"y : "<<y<<endl;
    }
};

int main(){
    A a1(5,6,8);
    a1.showData();
    a1.showk();
    a1.showy();
    return 0;
}