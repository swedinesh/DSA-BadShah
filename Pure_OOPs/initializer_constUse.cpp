#include<iostream>
using namespace std;

class A{
public:
int a,b,c;
// bnega tabhi initialize kar skte hai
// ya initializer ki help se initialize kar skte const and reference
const int k;
int &y;

A(int a, int b, int c, int k): a(a), b(b), c(c), k(k),y(a) 
{

}
void show()
{
    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
void show_k(){
    cout<<"const k = "<<k<<endl;
}
void show_y(){
    cout<<"&y = "<<y<<endl;
}

};

void f1(){
    A obj = {1,2,3,4};
    obj.show();
    obj.show_k();
    obj.show_y();

}

int main(){
    f1();
    return 0;
}