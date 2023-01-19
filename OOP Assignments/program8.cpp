// # Assignment-8 -> Employee Database
// # Using File Handling
// # File Mode : In Binary File Format
#include <iostream>
#include <fstream>
using namespace std;

// # Structure
struct employee
{
    string name, age, dept, post;
    int id;
    long long int salary;
};

// # Employee Class
class Employee
{
public:
    // Member Functions
    void Menu();
    void Insert();
    void Display();
    void Modify();
    void Search();
    void Delete();
};

//  ** Function Defination **

// # Database Menu
void Employee ::Menu()
{
    // Menu driven program
    int choice;
    char x;
    do
    {
        // Menu
        cout << "\n\t\t\t------------------------" << endl;
        cout << "\t\t\t | EMPLOYEE DATABASE |" << endl;
        cout << "\t\t\t------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Exit\n"
             << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\n # Enter Your Choose: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            do
            {
                Insert();
                cout << "\n\t\t# Add Another Employee Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;

        case 2:
            Display();
            break;

        case 3:
            Modify();
            break;

        case 4:
            Search();
            break;

        case 5:
            Delete();
            break;

        case 6:
            cout << "\n\t\t\t# Program Is Exit\n"
                 << endl;
            exit(0);
            break;

        default:
            cout << "\n\n\t\t\t# Invalid Choice! Please Try Again\n"
                 << endl;
            break;
        }
    } while (1);
}

// # Insert Data -> Add Employee Data
void Employee ::Insert()
{
    fstream file;
    employee em;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Employee Data ---------------------------------------------" << endl;
    cin.ignore();
    cout << "\n\t\t\tEnter Name: ";
    getline(cin, em.name);
    cout << "\t\t\tEnter Age: ";
    cin >> em.age;
    cout << "\t\t\tEnter Department: ";
    cin >> em.dept;
    cout << "\t\t\tEnter Post: ";
    cin >> em.post;
    cout << "\t\t\tEnter Id: ";
    cin >> em.id;
    cout << "\t\t\tEnter Salary: ";
    cin >> em.salary;
    file.open("Employee.txt", ios::binary | ios::app | ios::out);
    file.write((char *)&em, sizeof(em));
    file.close();
}

// # Display Record -> Display Employee Data
void Employee ::Display()
{
    fstream file;
    employee em;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Table --------------------------------------------" << endl;
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t# Data Is Not Present...\n"
             << endl;
        file.close();
    }
    else
    {
        int i = 1;
        file.read((char *)&em, sizeof(em));
        while (!file.eof())
        {
            if (i == 1)
            {
                cout << endl;
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << left << setw(10) << "SR No";
                cout << left << setw(13) << "Name";
                cout << left << setw(10) << "Age";
                cout << left << setw(10) << "Dept";
                cout << left << setw(13) << "Post";
                cout << left << setw(10) << "ID";
                cout << left << setw(10) << "Salary";
                cout << endl;
            }
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << left << setw(10) << i;
            cout << left << setw(13) << em.name;
            cout << left << setw(10) << em.age;
            cout << left << setw(10) << em.dept;
            cout << left << setw(13) << em.post;
            cout << left << setw(10) << em.id;
            cout << left << setw(10) << em.salary;
            cout << endl;
            file.read((char *)&em, sizeof(em));
            i++;
        }
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    }
    file.close();
}

// # Modify Record ->  Modify Employee Data
void Employee ::Modify()
{
    fstream file, file1;
    employee em;
    int ID;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Modify Employee Record ------------------------------------------" << endl;
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t# Data Not Found...\n"
             << endl;
        file.close();
    }
    else
    {
        cout << "\nEnter Id of Employee which you want to Modify: ";
        cin >> ID;
        file1.open("NewRecord.txt", ios::binary | ios::app | ios::out);
        file.read((char *)&em, sizeof(em));
        while (!file.eof())
        {
            if (ID != em.id)
                file1.write((char *)&em, sizeof(em));
            else
            {
                cin.ignore();
                cout << "\n\t\t\tEnter Name: ";
                getline(cin, em.name);
                cout << "\t\t\tEnter Age: ";
                cin >> em.age;
                cout << "\t\t\tEnter Department: ";
                cin >> em.dept;
                cout << "\t\t\tEnter Post: ";
                cin >> em.post;
                cout << "\t\t\tEnter ID: ";
                cin >> em.id;
                cout << "\t\t\tEnter Salary: ";
                cin >> em.salary;
                file1.write((char *)&em, sizeof(em));
                found++;
            }
            file.read((char *)&em, sizeof(em));
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t# Employee ID Not Found...\n";
        }
        file1.close();
        file.close();
        remove("Employee.txt");
        rename("NewRecord.txt", "Employee.txt");
    }
}

// # Search Record -> Search Employee Data
void Employee ::Search()
{
    fstream file;
    employee em;
    int found = 0;
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search Employee Record --------------------------------------------" << endl;
        cout << "\n\t\t\t# Employee Data Not Found...\n"
             << endl;
    }
    else
    {
        int ID;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search Employee Record --------------------------------------------" << endl;
        cout << "\nEnter Id of Employee which you want to search: ";
        cin >> ID;
        file.read((char *)&em, sizeof(em));
        while (!file.eof())
        {
            if (ID == em.id)
            {

                cout << endl;
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << left << setw(10) << "SR No";
                cout << left << setw(13) << "Name";
                cout << left << setw(10) << "Age";
                cout << left << setw(10) << "Dept";
                cout << left << setw(13) << "Post";
                cout << left << setw(10) << "ID";
                cout << left << setw(10) << "Salary";
                cout << endl;
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << left << setw(10) << em.id;
                cout << left << setw(13) << em.name;
                cout << left << setw(10) << em.age;
                cout << left << setw(10) << em.dept;
                cout << left << setw(13) << em.post;
                cout << left << setw(10) << em.id;
                cout << left << setw(10) << em.salary;
                cout << endl;
                file.read((char *)&em, sizeof(em));
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                found++;
            }
            file.read((char *)&em, sizeof(em));
        }
        if (found == 0)
        {
            cout << "\n\t\t\t# Employee ID Not Found...\n"
                 << endl;
        }

        file.close();
    }
}

// # Delete Record -> Delete Employee Data
void Employee ::Delete()
{
    fstream file, file1;
    employee em;
    int found = 0;
    int ID;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Record ------------------------------------------" << endl;
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t# Data Not Found...\n"
             << endl;
        file.close();
    }
    else
    {
        cout << "\nEnter Id of Employee whose data you want delete: ";
        cin >> ID;
        file1.open("NewRecord.txt", ios::binary | ios::app | ios::out);
        file.read((char *)&em, sizeof(em));
        while (!file.eof())
        {
            if (ID != em.id)
            {
                file1.write((char *)&em, sizeof(em));
            }
            else
            {
                found++;
                cout << "\n\t\t\t# Successfully Delete Data...\n"
                     << endl;
            }
            file.read((char *)&em, sizeof(em));
        }
        if (found == 0)
        {
            cout << "\n\t\t\t# Employee ID Not Found...\n"
                 << endl;
            ;
        }
        file1.close();
        file.close();
        remove("Employee.txt");
        rename("NewRecord.txt", "Employee.txt");
    }
}

// # Main Function
int main()
{
    Employee em;
    em.Menu();
    return 0;
}

// ********** Done *********
