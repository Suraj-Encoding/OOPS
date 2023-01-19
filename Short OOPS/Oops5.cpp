#include <iostream>
#include <iomanip>
using namespace std;

class shape
{
public:
double length,breadth;
    shape()
    {
    }
    void get_data()
    {
        cout << "enter dimension:" << endl;
        cin >> length >> breadth;
    }
    virtual void area()
    {
    }
};
class triangle : public shape
{
public:
    triangle()
    {
    }
    void area()
    {
        cout << "the area of triangle with dimension " << length << " unit and " << breadth << " unit is " << (0.5 * length * breadth) << " sq.units" << endl;
    }
};
class rectangle : public shape
{
public:
    rectangle()
    {
    }

    void area()
    {
        cout << "the area of rectangle with dimension " << length << " unit and " << breadth << " unit is " << (length * breadth) << " sq.units" << endl;
    }
};
int main()
{
    shape *s;
    int choice;
    while (1)
    {
        cout << "menu" << endl
             << "1)triangle" << endl
             << "2)rectangle" << endl
             << "3)exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            triangle t;
            t.get_data();
            s = &t;
            s->area();
        }
        else if (choice == 2)
        {
            rectangle r;
            r.get_data();
            s = &r;
            s->area();
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            cout << "wrong input" << endl;
        }
    }
    return 0;
}