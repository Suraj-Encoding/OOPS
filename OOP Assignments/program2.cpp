// # Assignment-2 -> Student database system
#include <iostream>
using namespace std;

// # Class Student
class Student
{
private:
    int roll_no;
    string name, address, Class, dob, blood_gp, div;
    long int phone_no;

public:
    // Static Variable
    static int count; // By default count=0
    // Function Declaration
    void Read(int i);
    void Display(int i);
    // Static Function
    inline static void display_count();
    // Constructor Declaration -> default constructor
    Student();
    // Destructor Declaration -> destructor is only one
    ~Student();
};

// ** Function Definations **

// # Read
void Student ::Read(int i)
{
    cout << "\nEnter data of student-" << (i + 1) << " : " << endl;

    cin.ignore(); // <- Imp step
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter class: ";
    getline(cin, Class);

    cout << "Enter division: ";
    getline(cin, div);

    cout << "Enter D.O.B: ";
    getline(cin, dob);

    cout << "Enter blood group: ";
    getline(cin, blood_gp);

    cout << "Enter Roll No: ";
    cin >> roll_no;

    cout << "Enter phone no: ";
    cin >> phone_no;

    // Increament student count by 1
    count++;
}

// # Display
void Student ::Display(int i)
{
    cout << "\nStudent-" << (i + 1) << " Data: " << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Class: " << Class << endl;
    cout << "Division: " << div << endl;
    cout << "D.O.B: " << dob << endl;
    cout << "Blood Group: " << blood_gp << endl;
    cout << "Roll No: " << roll_no << endl;
    cout << "Phone No: " << phone_no << endl;
}

// # Constructor
Student ::Student()
{
    cout << "Constructor.." << endl;
    name = "null";
    address = "null";
    Class = "null";
    div = "null";
    dob = "null";
    blood_gp = "null";
    roll_no = 0;
    phone_no = 0;
}

// # Destructor
Student ::~Student()
{
    cout << "Destroyed.." << endl;
    name = "null";
    address = "null";
    Class = "null";
    div = "null";
    dob = "null";
    blood_gp = "null";
    roll_no = 0;
    phone_no = 0;
}

// # Static Function -> To use static variable
void Student ::display_count()
{
    cout << "\nThe count of students is: " << count << endl;
}

// # Initialise static variable of class
int Student ::count = 0;

// # Main Function
int main()
{
    int i = 0, j = 0, n, ch;
    cout << "\n # Student Database System # \n\n";
    cout << "Enter number of students: ";
    cin >> n;
    Student *s;
    s = new Student[n];
    do
    {
        cout << "\n# Menu: \n1.Read \n2.Display \n3.Exit \nEnter your choice:  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            while (ch && i != n)
            {
                s[i].Read(i);
                cout << "\n* Want to continue (1.Yes 0.No) : ";
                cin >> ch;
                i++;
            }
            break;

        case 2:
            for (j = 0; j < Student::count; j++)
            {
                s[j].Display(j);
            }
            break;

        case 3:
            goto end;
            break;

        default:
            cout << "\n* Enter correct choice!" << endl;
            break;
        }
    } while (1);
end:
    Student ::display_count();
    return 0;
}
