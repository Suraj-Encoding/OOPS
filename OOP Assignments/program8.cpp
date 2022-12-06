// # Assignment-8 -> Employee Database
// # Using File Handling
// # File Mode : In Binary File Format
#include <iostream>
#include <fstream>
using namespace std;

// # Employee Class
class Employee
{
private:
    string name, age, dept, post;
    int id;
    long long int salary;

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

        // Switch
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
    // system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Employee Data ---------------------------------------------" << endl;
    cin.ignore();
    cout << "\n\t\t\tEnter Name: ";
    getline(cin, name);
    cout << "\t\t\tEnter Age: ";
    cin >> age;
    cout << "\t\t\tEnter Department: ";
    cin >> dept;
    cout << "\t\t\tEnter Post: ";
    cin >> post;
    cout << "\t\t\tEnter Id: ";
    cin >> id;
    cout << "\t\t\tEnter Salary: ";
    cin >> salary;
    file.open("Employee.bin", ios::binary | ios::app | ios::out);
    file << " \t" << name << "\t " << age << "\t " << dept << "\t " << post << "\t " << id << "\t " << salary << "\n";
    file.close();
}

// # Display Record -> Display Employee Data
void Employee ::Display()
{
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Table --------------------------------------------" << endl;
    file.open("Employee.bin", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t# Data Is Not Present...\n"
             << endl;
        file.close();
    }
    else
    {
        int i = 1;
        file >> name >> age >> dept >> post >> id >> salary;
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
            cout << left << setw(13) << name;
            cout << left << setw(10) << age;
            cout << left << setw(10) << dept;
            cout << left << setw(13) << post;
            cout << left << setw(10) << id;
            cout << left << setw(10) << salary;
            cout << endl;
            file >> name >> age >> dept >> post >> id >> salary;
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
    int ID;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Modify Employee Record ------------------------------------------" << endl;
    file.open("Employee.bin", ios::in);
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
        file1.open("NewRecord.bin", ios::binary | ios::app | ios::out);
        file >> name >> age >> dept >> post >> id >> salary;
        while (!file.eof())
        {
            if (ID != id)
                file1 << "\t" << name << " \t" << age << "\t " << dept << " \t" << post << " \t" << id << "\t " << salary << "\n";
            else
            {
                cin.ignore();
                cout << "\n\t\t\tEnter Name: ";
                getline(cin, name);
                cout << "\t\t\tEnter Age: ";
                cin >> age;
                cout << "\t\t\tEnter Department: ";
                cin >> dept;
                cout << "\t\t\tEnter Post: ";
                cin >> post;
                cout << "\t\t\tEnter ID: ";
                cin >> id;
                cout << "\t\t\tEnter Salary: ";
                cin >> salary;
                file1 << " \t" << name << "\t" << age << "\t" << dept << "\t" << post << "\t" << id << "\t" << salary << "\n";
                found++;
            }
            file >> name >> age >> dept >> post >> id >> salary;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t# Employee ID Not Found...\n";
        }
        file1.close();
        file.close();
        remove("Employee.bin");
        rename("NewRecord.bin", "Employee.bin");
    }
}

// # Search Record -> Search Employee Data
void Employee ::Search()
{
    fstream file;
    int found = 0;
    file.open("Employee.bin", ios::in);
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
        file >> name >> age >> dept >> post >> id >> salary;
        while (!file.eof())
        {
            if (ID == id)
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
                cout << left << setw(10) << id;
                cout << left << setw(13) << name;
                cout << left << setw(10) << age;
                cout << left << setw(10) << dept;
                cout << left << setw(13) << post;
                cout << left << setw(10) << id;
                cout << left << setw(10) << salary;
                cout << endl;
                file >> name >> age >> dept >> post >> id >> salary;
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                found++;
            }
            file >> name >> age >> dept >> post >> id >> salary;
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
    int found = 0;
    int ID;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Record ------------------------------------------" << endl;
    file.open("Employee.bin", ios::in);
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
        file1.open("NewRecord.bin", ios::binary | ios::app | ios::out);
        file >> name >> age >> dept >> post >> id >> salary;
        while (!file.eof())
        {
            if (ID != id)
            {
                file1 << "\t" << name << "\t" << age << " \t" << dept << " \t" << post << "\t " << id << " \t" << salary << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\t# Successfully Delete Data...\n"
                     << endl;
            }
            file >> name >> age >> dept >> post >> id >> salary;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t# Employee ID Not Found...\n"
                 << endl;
            ;
        }
        file1.close();
        file.close();
        remove("Employee.bin");
        rename("NewRecord.bin", "Employee.bin");
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