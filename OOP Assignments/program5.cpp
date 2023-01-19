// # Assignment-5 -> Virtual Function
#include <iostream>
using namespace std;

// # Base Class -> Shape
class Shape
{
public:
    double x, y;
    Shape()
    {
        x = 0;
        y = 0;
    }
    void get_data()
    {
        cout << "\n# Enter Dimenssions: " << endl;
        cin >> x >> y;
    }
    virtual void display_area() = 0;
};

// # Child Class -> Triangle
class Triangle : public Shape
{
public:
    void getdata()
    {
        Shape::get_data();
    }
    void display_area()
    {
        double d;
        d = (x * y) / 2;
        cout << "# Area of Triangle: " << d << endl;
    }
};

// # Child Class -> Rectangle
class Rectangle : public Shape
{
    void get_data()
    {
        Shape ::get_data();
    }
    void display_area()
    {
        double c;
        c = x * y;
        cout << "# Area of Rectangle: " << c << endl;
    }
};

// # Main Function
int main()
{
    int ch;
    Shape *ptr;
    Triangle t;
    Rectangle r;
    while (1)
    {
        cout << "\n# Menu: \n1.Triangle\n2.Rectangle \n3.Exit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ptr = &t;
            ptr->get_data();
            ptr->display_area();
            break;

        case 2:
            ptr = &r;
            ptr->get_data();
            ptr->display_area();
            break;

        case 3:
            cout << "\n# You are exit!\n"
                 << endl;
            exit(0);
            break;

        default:
            cout << "\n# Invalid Choice!" << endl;
            break;
        }
    }
    return 0;
}

// ** Done **