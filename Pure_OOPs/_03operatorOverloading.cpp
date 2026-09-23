/*
Can Not overload

.member access
.*pointer to member access
:: scope resolution
?: conditional operator
sizeof

*/

#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void setData(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void showData()
    {
        cout << "a= " << a << " & b= " << b << endl;
    }

    Complex add(Complex c)
    {
        Complex temp;
        temp.a = a + c.a; // c3.a = c1.a + c2.a
        temp.b = b + c.b;
        return temp;
    }
    // operator overloading

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.a = a + c.a; // c3.a = c1.a + c2.a
        temp.b = b + c.b;
        return temp;
    }
    
    Complex operator-()
    {
         Complex temp;
         temp.a = -a;
         temp.b = -b;
         return temp;
    }
    Complex operator*(Complex c){
        Complex temp;
        temp.a = a * c.a;
        temp.b = b * c.b;
        return temp;
    }
    bool operator==(Complex c){
        if(a == c.a && b == c.b)
          return true;
        else return false; 
    }
};

class Time{
private:
int h,m,s;

public:
void setTime(int h, int m, int s){
this->h = h;
this->m = m;
this->s = s;
}

void showTime(){
    cout<<h<<" : "<<m<<" : "<<s<<endl;
}

bool operator>(Time t)
{
    if(h > t.h) return true;
    else{
        if(m > t.m) return true;
        else if(m == t.m && s > t.s) return true;
        else return false;
    }
}

//pre increament
void operator++()
{
    if(h == 23 && m == 59){
        h = 0;
        m = 0;
        s = 0;
    }
    else if(h < 23 && m == 59 && s==59){
         ++h;
         m=0;
         s=0;
    }
    else if(m<59 && s==59){
        ++m;
        s = 0;
    }
    else ++s;
}

//post increament
void operator++(int)
{
    if(h == 23 && m == 59){
        h = 0;
        m = 0;
        s = 0;
    }
    else if(h < 23 && m == 59 && s==59){
         h++;
         m=0;
         s=0;
    }
    else if(m<59 && s==59){
        m++;
        s = 0;
    }
    else s++;
}

Time operator+(Time t){
   Time l;
   l.h = h + t.h;
   l.m = m + t.m;
   l.s = s + t.s;
   return l;
}

 
};

int main()
{

    Time t1, t2;
    t1.setTime(7,56,58);
    t2.setTime(7, 40, 40);
    t1.showTime();
    t2.showTime();
     
    if(t1>t2){ cout<<"T1 is greatest"<<endl;}
    else {cout<<"T2 is greatest"<<endl;}

    ++t1;
    t1.showTime();

    t2++;
    t2.showTime();

    Time t3;
    t3 = t1 + t2;

    t3.showTime();
    

    //Complex c1, c2, c3, c4;

    // c1.setData(3, 5);
    // c2.setData(5, 7);

    // c3 = c1.add(c2);

    // c1.showData();
    // c2.showData();
    // c3.showData();

    // // c4 = c1.operator+(c2);

    // c4 = c1 + c2; // binary operation
    // c4.showData();
    
    // c4 = -c2; // unarybinary pehle lagate hai like a = -b
    // // c4 = c2.operator-(); 
    // c4.showData();

    // Complex n1, n2, n3;
    // n1.setData(2,3);
    // n2.setData(2,3);

    // n3 = n1 * n2;

    // cout<<"multiplication c1\n";
    // n1.showData();
    // n2.showData();
    // n3.showData();

    // if(n1==n2) cout<<"n1 is equal to n2"<<endl;
    // else cout<<"n1 is not equal to n2"<<endl;



    return 0;
}