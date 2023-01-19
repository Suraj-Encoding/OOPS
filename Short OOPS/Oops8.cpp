#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class employee
{
public:
    int id;
    string name;
    int age;
    string department, post;
    int salary;
    void employee_data(int q)
    {
        cout << "\n\t\tENTER DETAILS" << endl;
        id=q;
        cout << "\t\tenter name:";
        cin >> name;
        cout << "\t\tenter age:";
        cin >> age;
        cout << "\t\tenter department:";
        cin >> department;
        cout << "\t\tenter post:";
        cin >> post;
        cout << "\t\tenter salary:";
        cin >> salary;
        cout << endl;
    }
    void display()
    {
        cout << "\t\tId:" << id << endl;
        cout << "\t\tName:" << name << endl;
        cout << "\t\tAge:" << age << endl;
        cout << "\t\tDepartment:" << department << endl;
        cout << "\t\tPost:" << post << endl;
        cout << "\t\tSalary:" << salary << endl;
    }
    void insert(int p)
    {
        fstream f;
        f.open("pbl8.dat", ios::in|ios::binary);
        if(!f)
        {
            cout << "\t\terror in opening the file." << endl;
        }
         else
        {
            f.read((char *)this, sizeof(*this));
            while (!f.eof())
            {
                if (id == p)
                {
                    cout<<"\t\tData with given id already exist"<<endl;
                    return ;
                }
                f.read((char *)this, sizeof(*this));
            }
            f.close();
        }
        f.open("pbl8.dat", ios::app|ios::out|ios::binary);
        employee_data(p);
        f.write((char *)this, sizeof(*this));
        f.close();
        cout << "\t\tData inserted" << endl;
    }
    void search()
    {
        int id1, count = 0;
        ifstream f;
        cout << "\t\tEnter id to search data:";
        cin >> id1;
        cout << endl;
        f.open("pbl8.dat", ios::in | ios::binary);
        if (!f)
        {
            
        }
        else
        {
            f.read((char *)this, sizeof(*this));
            while (!f.eof())
            {
                if (id == id1)
                {
                    cout << "\t\tDATA FOUND" << endl;
                    this->display();
                    count++;
                    break;
                }
                f.read((char *)this, sizeof(*this));
            }
            if (count == 0)
            {
                cout << "\t\tDATA NOT FOUND" << endl;
            }
            f.close();
        }
    }
    void removedata()
    {
        int id1, count = 0;
        ifstream f;
        ofstream f1;
        cout << "\t\tEnter id to delete data:";
        cin >> id1;
        cout << endl;
        f.open("pbl8.dat", ios::in | ios::binary);
        f1.open("pbl82.dat", ios::out | ios::binary);
        if (!f)
        {
            cout << "\t\terror in opening the file." << endl;
        }
        else
        {
            f.read((char *)this, sizeof(*this));
            while (!f.eof())
            {
                if (id != id1)
                {
                    f1.write((char *)this, sizeof(*this));
                }
                else
                {
                    count++;
                }
                f.read((char *)this, sizeof(*this));
            }
            f.close();
            f1.close();
            remove("pbl8.dat");
            rename("pbl82.dat", "pbl8.dat");
            if (count)
            {
                cout << "\t\tData deleted " << endl;
            }
            else
            {
                cout << "\t\tData not found" << endl;
            }
        }
    }
    void update()
    {
        int id1, count = 0;
        fstream f, f1;
        cout << "\t\tEnter id to update data:";
        cin >> id1;
        cout << endl;
        f.open("pbl8.dat", ios::in | ios::binary | ios::out);
        f1.open("pbl82.dat", ios::out | ios::binary);
        if (!f)
        {
            cout << "\t\terror in opening the file." << endl;
        }
        else
        {
            f.read((char *)this, sizeof(*this));
            while (!f.eof())
            {
                if (id == id1 && count == 0)
                {
                    this->employee_data(id1);
                    f1.write((char *)this, sizeof(*this));
                    count++;
                    break;
                }
                else
                {
                    f1.write((char *)this, sizeof(*this));
                }
                f.read((char *)this, sizeof(*this));
            }
            f.close();
            f1.close();
            remove("pbl8.dat");
            rename("pbl82.dat", "pbl8.dat");
            if (count == 1)
            {
                cout << "\t\tData updated" << endl;
            }
            else
            {
                cout << "\t\tData not found with given id" << endl;
            }
        }
    }

    void displayall()
    {
        fstream f;
        f.open("pbl8.dat", ios::in | ios::binary | ios::app);
        cout << "\t\tThe data is as follow" << endl<<endl;
        if (!f)
        {
            cout << "\t\terror in opening the file." << endl;
        }
        else
        {
            f.read((char *)this, sizeof(*this));
            while (!f.eof())
            {
                this->display();
                cout << endl;
                f.read((char *)this, sizeof(*this));
            }
            f.close();
        }
    }

    void deletefile()
    {
        remove("pbl8.dat");
        cout << "\t\tFile deleted " << endl;
    }

    int menu()
    {
        int choice = 0,id1;
        while (1)
        {
            cout << "\n\t\tMENU" << endl
                 << "\t\t1)insert" << endl
                 << "\t\t2)search" << endl
                 << "\t\t3)delete" << endl
                 << "\t\t4)update" << endl
                 << "\t\t5)display" << endl
                 << "\t\t6)delete file" << endl
                 << "\t\t7)exit" << endl;
            cout << "\t\tEnter choice:";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout<<"\t\tEnter the id to insert data:";
                cin>>id1;
                insert(id1);
                break;
            case 2:
                search();
                break;
            case 3:
                removedata();
                break;
            case 4:
                update();
                break;
            case 5:
                displayall();
                break;
            case 6:
                deletefile();
                break;
            case 7:
                return 0;
                break;
            default:
                cout << "\t\twrong choice!!!" << endl;
                break;
            }
        }
    }
};

int main()
{
    cout << "\t\t........................." << endl;
    cout << "\t\t|   EMPLOYEE DATABASE   |" << endl;
    cout << "\t\t........................." << endl;
    employee p;
    p.menu();
    return 0;
}
