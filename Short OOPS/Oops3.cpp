#include <iostream>
using namespace std;
class Vehicles
{
    int mileage;
    int price;

public:
    Vehicles()
    {
        cout << "---------------------------------------" << endl;
        cout << "Mileage  (in mpl) : ";
        cin >> mileage;
        cout << "Price (in lakhs): ";
        cin >> price;
    }
    int getMile()
    {
        return mileage;
    }
    int getPrice()
    {
        return price;
    }
};
class Car : public Vehicles
{
    int store_ownwership_cost;
    int Warranty;
    int seating_capacity;
    string fuel_type;

public:
    Car()
    {
        cout << "Ownership Cost(in lakhs) : ";
        cin >> store_ownwership_cost;
        cout << "Warranty (in years): ";
        cin >> Warranty;
        cout << "Seating Capacity : ";
        cin >> seating_capacity;
        cout << "Fuel Type : ";
        cin >> fuel_type;
    }
    int get_cost()
    {
        return store_ownwership_cost;
    }
    int getWarranty()
    {
        return Warranty;
    }
    int getSeat_cap()
    {
        return seating_capacity;
    }
    string getFuel_type()
    {
        return fuel_type;
    }
};
class Bike : public Vehicles
{

    int no_of_cylinders;
    int no_of_gears;
    string cooling_type;
    string wheel_type;
    float fuel_tank_Size;

public:
    Bike()
    {
        cout << "Number Of cylinder : ";
        cin >> no_of_cylinders;
        cout << "Number Of gears : ";
        cin >> no_of_gears;
        cout << "Cooling type : ";
        cin >> cooling_type;
        cout << "Wheel type : ";
        cin >> wheel_type;
        cout << "Size of Fuel tank (in inches) : ";
        cin >> fuel_tank_Size;
    }
    int get_no_of_cyl()
    {
        return no_of_cylinders;
    }
    int get_no_of_gears()
    {
        return no_of_gears;
    }
    string get_cooltype()
    {
        return cooling_type;
    }
    string get_wheeltype()
    {
        return wheel_type;
    }
    float get_tanksize()
    {
        return fuel_tank_Size;
    }
};
class Audi : public Car
{
    string Model_type;

public:
    Audi()
    {
        cout << "Model Type : ";
        cin >> Model_type;
        cout << "---------------------------------------" << endl;
    }
    void print_info()
    {
        cout << "---------------------------------------" << endl;
        cout << "Information of Audi ";
        cout << "Model Type : " << Model_type << endl;
        cout << "Milage (in mpl): " << getMile() << endl;
        cout << "Price (in lakhs): " << getPrice() << endl;
        cout << "Ownership cost of Car (in lakhs):" << get_cost() << endl;
        cout << "Warranty (in years): " << getWarranty() << endl;
        cout << "Seating Capacity : " << getSeat_cap() << endl;
        cout << "Fuel Type : " << getFuel_type() << endl;
        cout << "---------------------------------------" << endl;
    }
};
class Ford : public Car
{
    string Model_type;

public:
    Ford()
    {
        cout << "Model Type : ";
        cin >> Model_type;
        cout << "---------------------------------------" << endl;
    }
    void print_info()
    {
        cout << "---------------------------------------" << endl;
        cout << "Information of Ford ";
        cout << "Model Type : " << Model_type << endl;
        cout << "Milage (in mpl): " << getMile() << endl;
        cout << "Price (in lakhs): " << getPrice() << endl;
        cout << "Ownership cost of Car (in lakhs):" << get_cost() << endl;
        cout << "Warranty (in years): " << getWarranty() << endl;
        cout << "Seating Capacity : " << getSeat_cap() << endl;
        cout << "Fuel Type : " << getFuel_type() << endl;
        cout << "---------------------------------------" << endl;
    }
};
class Bajaj : public Bike
{
    string type;

public:
    Bajaj()
    {
        cout << "Model Type : ";
        cin >> type;
    }
    void print_info_bike()
    {
        cout << "---------------------------------------" << endl;
        cout << "Information of Bajaj Bike ";
        cout << "Model Type : " << type << endl;
        cout << "Milage (in mpl): " << getMile() << endl;
        cout << "Price (in lakhs): " << getPrice() << endl;
        cout << "Number of Cylinder:" << get_no_of_cyl() << endl;
        cout << "Number of Gears : " << get_no_of_gears() << endl;
        cout << "Cooling Type : " << get_cooltype() << endl;
        cout << "Wheel Type : " << get_wheeltype() << endl;
        cout << "Size of Tank (in inches) : " << get_tanksize() << endl;
        cout << "---------------------------------------" << endl;
    }
};
class TVS : public Bike
{
    string type;

public:
    TVS()
    {
        cout << "Model Type : ";
        cin >> type;
    }
    void print_info_bike()
    {
        cout << "---------------------------------------" << endl;
        cout << "Information of Bajaj Bike ";
        cout << "Model Type : " << type << endl;
        cout << "Milage (in mpl): " << getMile() << endl;
        cout << "Price (in lakhs): " << getPrice() << endl;
        cout << "Number of Cylinder:" << get_no_of_cyl() << endl;
        cout << "Number of Gears : " << get_no_of_gears() << endl;
        cout << "Cooling Type : " << get_cooltype() << endl;
        cout << "Wheel Type : " << get_wheeltype() << endl;
        cout << "Size of Tank (in inches) : " << get_tanksize() << endl;
        cout << "---------------------------------------" << endl;
    }
};

int main()
{
    cout << "Enter info of Audi Car" << endl;
    Audi a;
    cout << "Enter info of Ford Car" << endl;
    Ford f;
    a.print_info();
    f.print_info();
    return 0;
}
