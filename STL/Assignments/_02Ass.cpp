#include<iostream>
using namespace std;

template<class v>
class Array{
  private:
  int *a;
  int n;
  Array(int size);
  void print();
};

template<typename v>
 Array<v>::Array(int size){
     n = size;
     a = new v[n];
 } 

int main(){
    return 0;
}