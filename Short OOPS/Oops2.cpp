#include <iostream>
using namespace std;

class database
{
    friend void display(database);
    int roll_no, telephone;
    string name, blood_gr, contact_add, dob;

public:
    static int std_no;

    database()
    {
        cout << "-------------------------------------" << endl;
        cout << "Name : ";
        cin >> name;
        cout << "Roll no : ";
        cin >> roll_no;
        cout << "Date of Birth : ";
        cin >> dob;
        cout << "blood group : ";
        cin >> blood_gr;
        cout << "Phone number : ";
        cin >> telephone;
        cout << "City : ";
        cin >> contact_add;
        cout << "-------------------------------------" << endl;

        std_no++;
    }

    static void getcount()
    {
        cout << "Total students are " << std_no << endl;
    }
    inline void call()
    {
        cout << "inline function" << endl;
    }
    ~database()
    {
        cout << "destructor invoked " << endl;
    }
};
int database ::std_no = 1;
void display(database a)
{
    cout << endl
         << endl
         << endl;

    cout << "-------------------------------------" << endl;
    cout << "Information " << endl;
    cout << "Name : " << a.name << endl;
    cout << "Roll NO. : " << a.roll_no << endl;
    cout << "Date of Birth : " << a.dob << endl;
    cout << "Blood group : " << a.blood_gr << endl;
    cout << "Phone Number : " << a.telephone << endl;
    cout << "City : " << a.contact_add << endl;
    cout << "-------------------------------------" << endl;
}

int main()
{
    int num;

    cout << "Enter Number of students : ";
    cin >> num;

    database d[num];
    for (int i = 0; i < num; i++)
    {
        display(d[i]);
    }
    cout << "Total students : " << database::getcount << endl;

    return 0;
}