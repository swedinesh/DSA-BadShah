#include<iostream>
using namespace std;

int main(){
    char ch[100] = "Babbar";
    char *ctr = ch;

    cout<<endl<<ch<<endl;
    cout<<ch[0]<<endl;
    cout<<&ctr<<endl;
    cout<<*ctr<<endl;
    cout<<*(ctr+3)<<endl;
    cout<<ctr<<endl;
    //Base address but print all string with cout

    cout<<endl<<"<--- Base Address Condition --->"<<endl;
    cout<<ch<<endl;
    cout<<&ch[0]<<endl;
    cout<<ctr<<endl;
    //address print hoga
    cout<<&ch<<endl;
    //pointer location move
    cout<<ctr+2<<endl; // bbar
    cout<<ctr+4<<endl;
    return 0;
}