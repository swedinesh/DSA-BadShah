
/*
_____Overloading____

of insertion (<<) and extraction (>>) operator

cout is an object of ostream class
cin is an object of istream class
*/

#include<iostream>
using namespace std;

class Complex
{
    private:
    int a, b;
    public:
    void set(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void show()
    {
        cout<<"a= "<<a<<" & b= "<<b<<endl;
    }
    // object return karne ke pass by reference
    // because multiple input ke liye cin phir se call ho
    // cascading hota
    // Complex pass by reference for original value mai
    // change ho
    friend Complex operator>>(istream&, Complex&);
    friend Complex operator<<(ostream&, Complex);

};
// hme ostream & istrea class ke by reference hi karna hoga


// kuchh bhi le skte cin, din cin global hai 
// loacally name kuchh bhi rkh skte
Complex operator>>(istream& dnex_IN, Complex &C)
{
    dnex_IN>>C.a>>C.b;
    return C;
}

// hmne complex isliye pass by value kia beacuse hme kuch change nhi karna
// only print karna ya read only so 
// karna chaho to kar stke by refernce
Complex operator<<(ostream& dnex_OUT, Complex C)
{
    dnex_OUT<<"a= "<<C.a<<" & b= "<<C.b<<endl;
    return C;
}

int main()
{
    Complex c1;
    cout<<"\nEnter complex Number : ";
    cin>>c1; //operator>>(cin&, complex&)
    cout<<"You entered : ";
    cout<<c1; //operator<<(cout&, complex)
    cout<<endl;

    return 0;
}