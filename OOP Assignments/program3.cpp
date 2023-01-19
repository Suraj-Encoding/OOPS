// # Assignment-3 -> Vehicle System
#include <iostream>
#include <iomanip>
using namespace std;

// # Grandparent Class -> Vehicle
class Vehicle
{
private:
    float mileage;
    float price;

public:
    // setdata function
    void setdata(int i)
    {
        if (i == 1)
        {
            cout << "Enter mileage of car: ";
            cin >> mileage;
            cout << "Enter price of the car: ";
            cin >> price;
        }
        else
        {
            cout << "Enter mileage of bike: ";
            cin >> mileage;
            cout << "Enter price of the bike: ";
            cin >> price;
        }
    }
    // Display function
    void display()
    {
        cout << left << setw(10) << mileage;
        cout << left << setw(10) << price;
    }
};

// # First Parent Class -> Car
class Car : public Vehicle
{
private:
    float ownershipCost;
    int warranty;
    int seatingCapacity;
    string fuelType;

public:
    void setdata()
    {
        Vehicle ::setdata(1);
        cout << "Enter ownership cost: ";
        cin >> ownershipCost;
        cout << "Enter warranty: ";
        cin >> warranty;
        cout << "Enter seating capacity: ";
        cin >> seatingCapacity;
        cout << "Enter fuel type (Diesel or Petrol): ";
        cin >> fuelType;
    }
    void display()
    {
        Vehicle::display();
        cout << left << setw(10) << ownershipCost;
        cout << left << setw(10) << warranty;
        cout << left << setw(12) << seatingCapacity;
        cout << left << setw(8) << fuelType;
    }
};

// # Second Parent Class -> Bike
class Bike : public Vehicle
{
private:
    int numberCylinders;
    int numberGears;
    string coolingType;
    string wheelType;

public:
    void setdata()
    {
        Vehicle ::setdata(2);
        cout << "Enter number of cylinders: ";
        cin >> numberCylinders;
        cout << "Enter number of gears: ";
        cin >> numberGears;
        cout << "Enter cooling type (Air, Liquid or Oil): ";
        cin >> coolingType;
        cout << "Enter Wheel type (Alloys or Spokes): ";
        cin >> wheelType;
    }

    void display()
    {
        Vehicle::display();
        cout << left << setw(13) << numberCylinders;
        cout << left << setw(10) << numberGears;
        cout << left << setw(10) << coolingType;
        cout << left << setw(10) << wheelType;
    }
};

// # Child Class -> Audi
class Audi : public Car
{
private:
    string modeltype;

public:
    void setdata()
    {
        cout << "\n# Enter Audi Car Details: " << endl;
        Car ::setdata();
        cout << "Enter modeltype: ";
        cin >> modeltype;
        cout << endl;
    }

    void display()
    {

        cout << "\n# Car # \n"
             << endl;
        cout << left << setw(10) << "Sr No";
        cout << left << setw(10) << "Car";
        cout << left << setw(10) << "Mileage";
        cout << left << setw(10) << "Price";
        cout << left << setw(10) << "OwCost";
        cout << left << setw(10) << "Warranty";
        cout << left << setw(10) << "SeatingCp";
        cout << left << setw(10) << "  Fuel";
        cout << left << setw(10) << "Model";
        cout << endl;

        cout << left << setw(10) << "1";
        cout << left << setw(10) << "Audi";
        Car::display();
        cout << left << setw(10) << modeltype;
        cout << endl;
    }
};

// # Child Class -> Ford
class Ford : public Car
{
private:
    string modeltype;

public:
    void setdata()
    {
        cout << "\n# Enter Ford Car Details: " << endl;
        Car ::setdata();
        cout << "Enter modeltype: ";
        cin >> modeltype;
        cout << endl;
    }

    void display()
    {

        cout << left << setw(10) << "2";
        cout << left << setw(10) << "Ford";
        Car::display();
        cout << left << setw(10) << modeltype;
        cout << endl;
    }
};

// # child class -> Bajaj
class Bajaj : public Bike
{
private:
    string modeltype;

public:
    void setdata()
    {
        cout << "\n# Enter Bajaj Bike Details: " << endl;
        Bike ::setdata();
        cout << "Enter modeltype: ";
        cin >> modeltype;
        cout << endl;
    }

    void display()
    {
        cout << "\n# Bike # \n"
             << endl;
        cout << left << setw(10) << "Sr No";
        cout << left << setw(10) << "Bike";
        cout << left << setw(10) << "Mileage";
        cout << left << setw(10) << "Price";
        cout << left << setw(10) << "Cylinders";
        cout << left << setw(10) << "  Gears";
        cout << left << setw(10) << "Cooling";
        cout << left << setw(10) << "  Wheel";
        cout << left << setw(10) << "  Model";
        cout << endl;

        cout << left << setw(10) << "1";
        cout << left << setw(10) << "Bajaj";
        Bike::display();
        cout << left << setw(10) << modeltype;
        cout << endl;
    }
};

// # child class -> TVS
class TVS : public Bike
{
private:
    string modeltype;

public:
    void setdata()
    {
        cout << "\n# Enter TVS Bike Details: " << endl;
        Bike ::setdata();
        cout << "Enter modeltype: ";
        cin >> modeltype;
        cout << endl;
    }

    void display()
    {
        cout << left << setw(10) << "2";
        cout << left << setw(10) << "TVS";
        Bike::display();
        cout << left << setw(10) << modeltype;
        cout << endl;
    }
};

// # Main Function
int main()
{
    // Car -> Audi and Ford
    Audi audi;
    Ford ford;

    // Bike -> Bajaj and TVS
    Bajaj bajaj;
    TVS tvs;

    // setdata
    audi.setdata();
    ford.setdata();
    bajaj.setdata();
    tvs.setdata();

    // showdata
    audi.display();
    ford.display();
    bajaj.display();
    tvs.display();

    return 0;
}