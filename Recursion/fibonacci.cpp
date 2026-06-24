#include<iostream>
using namespace std;

int fobo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int fib1 = fobo(n-1);
    int fib2 = fobo(n-2);
    return fib1 + fib2;
}

void fibSeries(int n){
    
    if(n<0) return;
    fibSeries(n-1);
    cout<<fobo(n)<<" ";
    
}

void advFibo(int a, int b, int n){
  if(n==0) return;
  cout<<a<<" ";
  advFibo(b, a + b, n-1);
}

int main(){
    int n;
    cout<<"enter n th term of series : ";
    cin>>n;

    // cout<<endl<<"N th term is : "<<fobo(n)<<endl;
    // //series
    // fibSeries(n);
    // cout<<endl;

    advFibo(0,1,n);
    cout<<endl;

    return 0;
}