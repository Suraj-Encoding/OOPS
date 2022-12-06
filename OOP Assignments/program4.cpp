// # Assignment-4 -> Operator Overloading [Complex Number]
#include <iostream>
using namespace std;

class complex
{
private:
    float real, img;

public:
    // constructor
    complex()
    {
        real = 0;
        img = 0;
    }
    // Function declaration
    complex operator+(complex);
    complex operator-(complex);
    complex operator*(complex);
    friend istream &operator>>(istream &in, complex &c)
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.img;
        return in;
    }
    friend ostream &operator<<(ostream &out, complex &c)
    {
        out << c.real;
        if (c.img >= 0)
        {
            cout << " + ";
            out << c.img << "i";
        }
        else
        {
            cout << " - ";
            out << c.img << "i";
        }
        cout << endl;
        return out;
    }
};

int main()
{
    cout << "\n# Complex Arithmetic #\n";
    complex c, c1, c2;
    int ch;
    do
    {
        cout << "\n# Menu: \n1.Setdata \n2.Getdata \n3.Addition  \n4.Subtraction \n5.Multiplicaton  \n6.Exit \nEnter your choice:  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter Complex number-1: " << endl;
            cin >> c1;
            cout << "\nEnter Complex number-2: " << endl;
            cin >> c2;
            break;

        case 2:
            cout << "\nComplex number-1: ";
            cout << c1;
            cout << "\nComplex number-2: ";
            cout << c2;
            break;

        case 3:
            c = c1 + c2;
            cout << "Addition: ";
            cout << c;
            break;

        case 4:
            c = c1 - c2;
            cout << "Subtraction: ";
            cout << c;
            break;

        case 5:
            c = c1 * c2;
            cout << "Multiplication: ";
            cout << c;
            break;

        case 6:
            cout << "\n* You are exit!\n";
            cout << endl;
            exit(0);
            break;

        default:
            cout << "\n* Invalid choice!" << endl;
            break;
        }
    } while (1);
}

// ** Function definations **

complex complex ::operator+(complex c3)
{
    complex c;
    c.real = real + c3.real;
    c.img = img + c3.img; //  real = c1.real and c3=c2
    return c;
}

complex complex ::operator-(complex c3)
{
    complex c;
    c.real = real - c3.real;
    c.img = img - c3.img;
    return c;
}

complex complex ::operator*(complex c3)
{
    complex c;
    c.real = (real * c3.real - img * c3.img);
    c.img = (real * c3.img + img * c3.real);
    return c;
}