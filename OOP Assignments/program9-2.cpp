// # Assignment-9 -> Part-2
// # STL Map
// # Store Person Record Using STL Map
// # Operations: 1.Add  2.Display  3.Search  4.Delete  5.Update
#include <iostream>
#include <iomanip>
#include <map> // ...STL MAP
using namespace std;

// # Class Person
class Person
{
private:
    string name;
    string dob;
    long int tel;

public:
    void Input();
    friend ostream &operator<<(ostream &out, const Person &r);
};

// # Operator Overloading for display data of person
ostream &operator<<(ostream &out, const Person &p)
{
    out << left << setw(10) << p.name;
    out << left << setw(13) << p.dob;
    out << left << setw(10) << p.tel;
    return out;
}

// # Read Data
void Person::Input()
{
    cout << "  Enter the name: ";
    cin >> name;
    cout << "  Enter the Date of Birth (Format: DD/MM/YYYY): ";
    cin >> dob;
    cout << "  Enter the telephone number: ";
    cin >> tel;
}

// # Class Map
class Map
{
private:
    map<int, Person> m; // ...Map [key,data] pair
public:
    void add();
    void display();
    void search();
    void del(); // ...Delete Function
    void update();
};

// # Add Data
void Map::add()
{
    int key;
    Person p;
    cout << "\n# Enter the ID: ";
    cin >> key;
    cout << "# Enter the Person Data:\n";
    p.Input();
    m.insert(pair<int, Person>(key, p));
}

// # Display Data
void Map::display()
{
    cout << "\n------------------------------------------------\n";
    cout << left << setw(10) << "ID";
    cout << left << setw(13) << "Name";
    cout << left << setw(10) << "DOB";
    cout << left << setw(10) << "Telephone";
    cout << "\n------------------------------------------------\n";
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        cout << left << setw(10) << i->first;
        cout << i->second;
        cout << "\n------------------------------------------------\n";
    }
}

// # Search Data
void Map::search()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to search: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            cout << "\n* Data Found..!" << endl;
            cout << "\n--------------------------------------\n";
            cout << left << setw(10) << "Name";
            cout << left << setw(13) << "DOB";
            cout << left << setw(10) << "Telephone";
            cout << "\n--------------------------------------\n";
            cout << i->second;
            cout << "\n--------------------------------------\n";
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Delete Data
void Map::del()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to delete: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            cout << "\n# Data deleted Successfully..!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Update Data
void Map::update()
{
    int key, flag = 0;
    cout << "\n# Enter the ID of the person you want to update: ";
    cin >> key;
    // # Iterator
    map<int, Person>::iterator i = m.begin();
    for (i; i != m.end(); ++i)
    {
        if (i->first == key)
        {
            flag = 1;
            m.erase(key);
            Person p;
            cout << "\n# Enter updated data: " << endl;
            p.Input();
            m.insert(pair<int, Person>(key, p));
            cout << "\n# Data updated Successfully..!" << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "\n# Entered ID does not exist in the database..!\n";
}

// # Main Function
int main()
{
    // # STL MAP
    cout << "\n# STL MAP #\n";
    Map t;
    int ch;
    do
    {
        cout << "\n--- MENU ---";
        cout << "\n1.Add Record"
             << "\n2.Display Record"
             << "\n3.Search Record"
             << "\n4.Delete Record"
             << "\n5.Update Record"
             << "\n6.Exit";
        cout << "\nEnter your choice..";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n# Add Record: " << endl;
            t.add();
            break;

        case 2:
            cout << "\n# Display Record: " << endl;
            t.display();
            break;

        case 3:
            cout << "\n# Search Record: " << endl;
            t.search();
            break;

        case 4:
            cout << "\n# Delete Record: " << endl;
            t.del();
            break;

        case 5:
            cout << "\n# Updata Record: " << endl;
            t.update();
            break;

        case 6:
            cout << "\n* You are exit...!\n\n";
            exit(0);
            break;

        default:
            cout << "\n* Invalid Choice..!" << endl;
            break;
        }
    } while (1);
    return 0;
}
