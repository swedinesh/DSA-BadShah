#include<iostream>
using namespace std;

class A{
   private:
   int a1, a2;

   public:
   A(){
      cout<<"A-Constructor"<<endl;
   }
   
   A(int x, int y){
    a1 = x;
    a2 = y;
     cout<<"A-Constructor"<<endl;
   }

   ~A(){
    cout<<"A-Destructor"<<endl;
   }
};

class B : public A{
   private:
   int b1, b2;

   public:
   B(){
    cout<<"B-Constructor"<<endl;
   }
   
   B(int w, int q, int x, int y): A(w, q){
    b1 = x; b2 = y;
    cout<<"B-Constructor"<<endl;
   }
   
    ~B(){
    cout<<"B-Destructor"<<endl;
   }
};

int main(){

    B obj(5, 6, 10, 20);
    
    return 0;
}