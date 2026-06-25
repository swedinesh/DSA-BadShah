#include<iostream>
using namespace std;

class Obj{
public:
void call(){
    cout<<"Milegi Kya Obj ?..."<<endl;
}
};

int main(){
Obj o;
o.call();
    return 0;
}