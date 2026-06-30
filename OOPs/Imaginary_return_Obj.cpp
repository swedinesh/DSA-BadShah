#include<iostream>
using namespace std;

class Image{
private:
int a,b;

public:
Image(){
    a=0;
    b=0;
}

void setData(int, int);
void getData();

//add function take obj return obj
Image add(Image c){
     Image temp;
     temp.a = a + c.a;
     temp.b = b + c.b;
     return temp;
}

//Copy Constructor
Image(Image &c){
    a = c.a;
    b = c.b;
}

};

void Image::setData(int x, int y){
    a=x;
    b=y;
}

void Image::getData(){
    cout<<"a : "<<a<<" b : "<<b<<endl;
}

int main(){
    Image i1,i2,i4;
    i1.setData(3,5);
    i2.setData(4,9);
    i1.getData();
    i2.getData();
    Image i3 = i1;
    i3.getData();
    i3 = i2;
    i3.getData();
     
    i4 = i1.add(i2);
    i4.getData();

    Image i5 = i4;
    i5.getData();
    i5 = i1;
    i5.getData();
    return 0;
}