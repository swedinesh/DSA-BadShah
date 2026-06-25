#include<iostream>
using namespace std;


class Vehicle{

protected:
string name;
string model;
int noOfTyres;

public:
//Vehicle constructor
Vehicle(string _name, string _model, int _noOfTyres){
    cout<<"\nVehicle Constructor is on"<<endl;
    this->name = _name;
    this->model = _model;
    this->noOfTyres = _noOfTyres;
}

public:

void start_engine(){
    cout<<" Engine is started -> "<<name<<" "<<model<<endl;
}

void stop_engine(){
    cout<<" Engine is stopping -> "<<name<<" "<<model<<endl;
}

~Vehicle(){
  cout<<"Vehicle is OFF!"<<endl;
}
};

class Car : public Vehicle{
   public:
   int noOfDoor;
   string transmissionType;

   Car(string _name, string _model, int _noOfTyres, int _noOfDoor, string _transmissionType):Vehicle(_name, _model, _noOfTyres){

     cout<<"Car Constructor is on\n"<<endl;
     
     this->noOfDoor = _noOfDoor;
     this->transmissionType = _transmissionType;
   }

   void startAC(){
   cout<<"\n Car AC is ON "<<name<<endl;
   }

~Car(){
    cout<<"\nCar is OFF!"<<endl;
}

};


int main(){

    Car A("TATA Sierra", "Accomplished 1.5L Petrol ", 4, 5, "Manual");
    A.startAC();
    A.start_engine();
    A.stop_engine();

    return 0;
}


