// # Map
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

struct data
{ 
    string name,dob;
};

int main()
{
    map<int,struct data> Person;
    struct data s;
    int choice, tel;
    char name[20];
    while (1)
    {
        cout << "\nMENU" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Name: ";
            cin >> s.name;
            cout << "DOB: ";
            cin >> s.dob;
            cout << "Telephone no.: ";
            cin >> tel;
            Person.insert(pair<int,struct data>(tel,s));
            break;
        }
        case 2:
        {
            cout << "Enter tel: ";
            cin >> tel;
           map<int,struct data> ::iterator it = Person.find(tel);
            if (it==Person.end())
            {
                cout << "Data Not found..\n";
                break;
            }
            cout << "Data found: \n";
            cout << it->first << "  " << it->second.name << " "<< it->second.dob<<endl;;
            break;
        }
        case 3:
        {
            for ( map<int,struct data> ::iterator it = Person.begin(); it != Person.end(); ++it)
               cout << it->first << "  " << it->second.name << " "<< it->second.dob<<endl;;
            if(Person.empty())
               cout<<"Data not present...\n";
            break;
        }
        case 4:
        {
            cout << "Enter tel: ";
            cin >> tel;
            map<int,struct data> ::iterator it = Person.find(tel);
            if(it==Person.end())
            {
                cout<<"Data bot found..\n";
                break;
            }
            Person.erase(it);
            cout<<"Deleted..\n";
            break;
        }
        case 5:
            cout << "Exit..\n";
            break;
        default:
            cout << "Wrong input..\n";
            break;
        }
    }
    return 0;
}