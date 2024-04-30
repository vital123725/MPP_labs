#include <iostream>
#include <string>
using namespace std;

class transport
{
public:

    void starting()
    {
        cout << "car is starting" << endl;
    }

    void drive()
    {
        cout << "car is moving" << endl;
    }

    void brake()
    {
        cout << "car is braking" << endl;
    }

    void stalling()
    {
        cout << "car is stalling" << endl;
    }
};

class Car : public transport
{
public:
    string brand = "toyota";
    string name = "Camry";
    string color = "black";
    int year = 2010;

    void displayInfo()
    {
        cout << "brand: " << brand << endl;
        cout << "name: " << name << endl;
        cout << "year: " << year << endl;
        cout << "color: " << color << endl;
    }
};

int main()
{
    Car car;

    car.drive();
    car.starting();
    car.stalling();
    car.brake();

    car.displayInfo();

    return 0;
}
