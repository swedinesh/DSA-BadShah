#include<iostream>
using namespace std;

template<typename V>

class Array{
private:
int capacity;
int lastIndex;
V *ptr;

public:
Array(int);
V get(int index);
void insert(int index, V data);
void append(V data);
};

template<typename V>
 Array<V>::Array(int cap){
   capacity = cap;
   lastIndex = -1;
   ptr = new V[cap];
 }

 template<typename V>
 V Array<V>::get(int index){
    return ptr[index];
 }

 int main(){
    Array<int> a1(5);
    return 0;
 }
//Function template
// template <class or typename name>
/*
template<typename X>

X big(X a, X b){
    if(a>b) return a;
    else return b;
}

int main(){
    
    cout<<big(3,5)<<endl;
    cout<<big(3.9,4.9)<<endl;
    cout<<big(3.0009,5.344)<<endl;
    cout<<big('j', 't' )<<endl;

    return 0;
}
*/