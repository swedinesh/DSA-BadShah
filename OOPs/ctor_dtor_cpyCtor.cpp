#include<iostream>
using namespace std;

class Student{
    public:
    int id;
    string name;
    int nsub;
    string clg;
    int *mark;
    //constructor
    Student(){
        cout<<this->name<<" Constructor is On"<<endl;
        mark =  new int(0);
    }
    Student(int id, string name, int nsub, string clg){
      this->id = id;
      this->name = name;
      this->nsub = nsub;
      this->clg = clg;
      mark = new int(100);
        cout<<endl<<" === Student Details ==="<<endl;
        cout<<"\nId : "<<this->id<<"\nName : "<<this->name<<"\nCollege Name : "<<this->clg<<"\nNumber of Subjects : "<<this->nsub<<endl<<endl;

     }

    void study(){
        cout<<this->name<<" is studying..."<<endl;
    }
    void sleep(){
        cout<<this->name<<" is sleeping"<<endl;
    }
    ~Student(){
        cout<<this->name<<" Today Work END"<<endl;
        delete mark;
    }
    Student(const Student &m){
          cout << "Copy Constructor Called\n";

        id = m.id;
        name = m.name;
        clg = m.clg;
        nsub = m.nsub;
        mark = new int;
        *mark = *m.mark;

    }
};

int main(){
    // Student A(2026,"Dhruvi",0,"AndiBadi"), B(2017, "Gabbu", 10, "Primary");
    // A.study();
    // B.study();
    // A.sleep();
    // B.sleep();

    Student *p = new Student(2000, "Dinux", 90, "IIIT Vadodara");
    Student *x = new Student(*p);
    delete p;
    delete x;

    // A.name = "Dhruvi";
    // A.id = 2026;
    // A.clg = "AndiBadi";
    // A.nsub = 0;
    // A.study();
    // A.sleep();

    // B.name = "Gabbu";
    // B.id = 2017;
    // B.clg = "Primary";
    // B.nsub = 10;
    // B.study();
    // B.sleep();

    return 0;
}