#include <iostream>
using namespace std;

class Vehicles
{
public:
    string name;
    int model;
    int noOftyres;

    Vehicles(string, int, int);
    void start_engine();
    void stop_engine();
};
Vehicles::Vehicles(string name, int model, int noOftyres)
{
    this->name = name;
    this->model = model;
    this->noOftyres = noOftyres;
}
void Vehicles::start_engine()
{
    cout << this->name << " Engine is Started" << endl;
}
void Vehicles::stop_engine()
{
    cout << this->name << " Engine is Stoped" << endl;
}

class Car : public Vehicles
{
public:
    int noOfDoors;
    string transmissionType;

    Car(string, int, int, int, string);
    void start_AC();
    void specs();
};

Car::Car(string name, int model, int noOftyres,
         int noOfDoors, string transmissionType)
    : Vehicles(name, model, noOftyres)
{
    this->noOfDoors = noOfDoors;
    this->transmissionType = transmissionType;
}

void Car::start_AC()
{
    cout << this->name << " AC is On" << endl;
}

void Car::specs()
{
    cout << "========== CAR ==========" << endl;
    cout << "Name : " << this->name << endl;
    cout << "Model : " << this->model << endl;
    cout << "No of Tyres : " << this->noOftyres << endl;
    cout << "No of Doors : " << this->noOfDoors << endl;
    cout << "Transmission Type : " << this->transmissionType << endl;
}

class MotorCycle : public Vehicles
{
public:
    string handleBarStyle;
    string suspentionType;

    MotorCycle(string, int, int, string, string);
    void wheeli();
    void specs();
};

MotorCycle::MotorCycle(string name, int model, int noOftyres,
                       string handleBarStyle, string suspentionType)
    : Vehicles(name, model, noOftyres)
{
    this->handleBarStyle = handleBarStyle;
    this->suspentionType = suspentionType;
}

void MotorCycle::wheeli()
{
    cout << this->name << " is Wheeli" << endl;
}

void MotorCycle::specs()
{
    cout << "========== Motor Cycle ==========" << endl;
    cout << "Name : " << this->name << endl;
    cout << "Model : " << this->model << endl;
    cout << "No of Tyres : " << this->noOftyres << endl;
    cout << "Handle Bar Style : " << this->handleBarStyle << endl;
    cout << "Suspention Type : " << this->suspentionType << endl;
}

int main()
{
    Car c1("BMW", 2026, 4, 4, "Automatic");
    MotorCycle m1("Royal Enfield", 1990, 2, "Aluminium", "Socker");

    c1.specs();
    cout<<endl;
    m1.specs();
    c1.start_engine();
    c1.start_AC();
    c1.stop_engine();
    m1.start_engine();
    m1.wheeli();
    m1.stop_engine();

        return 0;
}