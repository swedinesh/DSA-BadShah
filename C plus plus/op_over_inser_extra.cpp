/*
Overloading of insertion(<<) and extraction(>>) operator
*/

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

    friend ostream& operator<<(ostream&, Complex);
    // rememeber paas by reference object in cin
    friend istream& operator>>(istream&, Complex&);

    
};

ostream& operator<<(ostream& out, Complex C){
    out<<"a="<<C.a<<" b="<<C.b<<endl;
    return out;
}

istream& operator>>(istream& in, Complex &C){
    in>>C.a>>C.b;
    return in;
}

int main(){
    Complex c1;
    
    cout<<"Enter a Complex Number ->>"<<endl;
    cin>>c1;
    cout<<"You entered ..."<<endl;
    cout<<c1;

    return 0;
}
