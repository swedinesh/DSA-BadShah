#include<iostream>
using namespace std;

// int fun(int x, int y)
// {
// if (x == 0)
// return y;
// return fun(x - 1, x + y);
// }


// int main()
// {
// cout << fun(5, 2) << endl;
// return 0;
// }

int f(int);
int g(int);

int main(){
cout << f(4) << endl;
return 0;
}

int f(int x){
if(x < 1) return 1;
else return (f(x-1) + g(x));
}

int g(int x){
if(x < 2) return 2;
else return (f(x-1) + g(x/2));
}