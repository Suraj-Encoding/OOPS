#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void print_vector(vector<int> p[])
{
    cout << endl
         << "the data in the vector is as follow" << endl;
    vector<int>::iterator it;
    it = p->begin();
    while (it != p->end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void insert_vector(vector<int> p[])
{
    int n;
    vector<int>::iterator it;
    it = p->end();
    cout << endl
         << "enter the element to be inserted:" << endl;
    cin >> n;
    p->insert(it, n);
}

void update_vector(vector<int> p[])
{
    int n, pos;
    vector<int>::iterator it;
    it = p->begin();
    cout << endl
         << "enter the position of element to be updated" << endl;
    cin >> pos;
    cout << "enter the new element to be inserted:" << endl;
    cin >> n;
    p->erase(it + pos);
    p->insert(it + pos, n);
}

void multiply_vector(vector<int> p[])
{
    int n, temp;
    vector<int>::iterator it;
    cout << endl
         << "enter the scaler to multiply whole vector:" << endl;
    cin >> n;
    for (it = p->begin(); it != p->end(); it++)
    {
        temp = *it;
        p->erase(it);
        p->insert(it, (temp * n));
    }
}

int main()
{
    int i = 0, n, choice;
    vector<int> v[20];
    vector<int>::iterator it;
    while (1)
    {
        cout << endl
             << "MENU" << endl
             << "1)insert" << endl
             << "2)update" << endl
             << "3)multiply a scaler" << endl
             << "4)display" << endl
             << "5)exit" << endl;
        cout << "enter choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert_vector(v);
            break;
        case 2:
            update_vector(v);
            break;
        case 3:
            multiply_vector(v);
            break;
        case 4:
            print_vector(v);
            break;
        case 5:
            cout << "Exit...";
            return 0;
            break;
        default:
            cout << "wrong choice..." << endl;
            break;
        }
    }
    return 0;
}