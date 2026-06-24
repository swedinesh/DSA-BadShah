#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = &a;
    int *q = p;
    int *r = q;

    cout<<p<<endl;
    cout<<q<<endl;
    cout<<r<<endl;
    cout<<&a<<endl;
    cout<<*r<<endl;
    
    return 0;
}