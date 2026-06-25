
// class Hello{
//     public static void main(String[] args) {
//         System.out.println("\nHello Dinesh!..");
//     }
// }


class Vehicle {

    protected String name;
    protected String model;
    protected int noOfTyres;

    // Constructor
    Vehicle(String name, String model, int noOfTyres) {
        System.out.println("\nVehicle Constructor is on");
        this.name = name;
        this.model = model;
        this.noOfTyres = noOfTyres;
    }

    void startEngine() {
        System.out.println("Engine is started -> " + name + " " + model);
    }

    void stopEngine() {
        System.out.println("Engine is stopping -> " + name + " " + model);
    }
}

class Car extends Vehicle {

    int noOfDoor;
    String transmissionType;

    // Constructor
    Car(String name, String model, int noOfTyres,
        int noOfDoor, String transmissionType) {

        super(name, model, noOfTyres);   // Parent constructor call

        System.out.println("Car Constructor is on\n");

        this.noOfDoor = noOfDoor;
        this.transmissionType = transmissionType;
    }

    void startAC() {
        System.out.println("\nCar AC is ON " + name);
    }
}

public class Main {

    public static void main(String[] args) {

        Car A = new Car(
                "TATA Sierra",
                "Accomplished 1.5L Petrol",
                4,
                5,
                "Manual");

        A.startAC();
        A.startEngine();
        A.stopEngine();
    }
}