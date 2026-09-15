#include<iostream>
#include<string.h>
using namespace std;
/*
Book 
properties : id, name, price
behaviour : book create, show book

id, name, price, 
setBook, showBook
*/

struct Book{
int id;
char name[20];
int price;
};

// "Java" - string literral hai so modifie nhi ho skta 
// function ko bhi yhi bolna chahiye ye modifie nhi ho skta so usee cons

Book setBook(int id, const char name[], int price){
    Book b;
    b.id = id;
    strcpy(b.name, name);
    b.price = price;
    return b;
}

void showBook(Book b){
  cout<<"\n"<<b.id<<" "<<b.name<<" "<<b.price<<" "<<"\n";
}

int main(){
    Book b1;
    b1 = setBook(1, "Java", 399);
    showBook(b1);

    return 0;
}