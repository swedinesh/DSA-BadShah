#include<iostream>
#include<string.h>
using namespace std;

class Person{
 private:
 int age;
 char name[20];

 protected:
 void setName(char n[]){ strcpy(name, n);}
 void setAge(int a){ age = a;}

 public:
 int getAge(){ return age; }
 char* getName(){ return name;}
 
};

class Student : public Person{
  private:
  char rollno[20];

  protected:
  void setRoll(char roll[]){
    strcpy(rollno, roll);
  }

  public:
  void setStudent(char r[], char n[], int a){
    strcpy(rollno, r);
    setAge(a);
    setName(n);
  }

  void showStudent(){
    cout<<"Roll No. : "<<rollno<<endl;
    cout<<"Name     : "<<getName()<<endl;
    cout<<"Age      : "<<getAge()<<endl;
  }

};

int main(){

 char r[20] ="20251651035";
 char name[30] = "Dinesh Kushwaha";

Student s1;
cout<<endl;

s1.setStudent(r , name , 22);
s1.showStudent();

    return 0;
}