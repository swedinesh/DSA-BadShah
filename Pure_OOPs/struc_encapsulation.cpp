#include<iostream>
#include<string.h>
using namespace std;

struct Book{
    // Data Hidding
    private:
    int bookId;
    char bTittle[20];
    int bPrice;
    
    // behaviour
    public:
    
    void setBook(int id, const char ti[], int price){
       bookId = id;
       strcpy(bTittle, ti);
       bPrice = price;
    }
    
    void showBook(){
        cout<<"\nBook_ID : "<<bookId
        <<"\nBooK_Tittle : "<<bTittle
        <<"\nBook_Price : "<<bPrice<<"\n";
    }


};

int main(){
    Book b1;
    b1.setBook(1, "MahaBharat", 1999);
    b1.showBook();

    Book b2;
    // Pass by value hota hai
    b2 = b1;

    b2.showBook();

    b2.setBook(2, "Ramayan", 1899);
    b1.showBook();
    b2.showBook();
    
    return 0;
}