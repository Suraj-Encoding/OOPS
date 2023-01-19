#include <iostream>
#include <string>
using namespace std;
class bank
{
    int acc_no;
    string name, type;
    float balance;

public:
    bank() {}
    bank(int a, string b, string c, float d)
    {
        acc_no = a;
        name = b;
        type = c;
        balance = d;
    }
    void deposit(float a)
    {
        balance = balance + a;
    }
    void withdraw(float b)
    {
        if (balance >= b)
        {
            balance = balance - b;
            display(0, b);
        }
        else
        {
            cout << endl
                 << "*INSUFFICIENT BALANCE*" << endl
                 << endl;
            display(0, 0);
        }
    }
    void display(float depo, float withdr)
    {
        cout << "NAME : " << name << endl;
        cout << "ACCOUNT NUMBER : " << acc_no << endl;
        cout << "AMOUNT WITHDRAW : " << withdr << endl;
        cout << "AMOUNT DEPOSIT : " << depo << endl;
        cout << "UPDATED BALANCE : " << balance << endl;
    }
};
int main()
{
    string s, type;
    int accno, choice;
    float bal, depo, withdr;
    cout << "ENTER NAME : ";
    cin >> s;
    cout << "ENTER ACCOUNT NO. : ";
    cin >> accno;
    cout << "ENTER TYPE : ";
    cin >> type;
    cout << "ENTER BALANCE : ";
    cin >> bal;
    bank b1(accno, s, type, bal);
    while (choice != 3)
    {
        cout << "ENTER CHOICE:" << endl;
        cout << "1.DEPOSIT" << endl
             << "2.WITHDRAW" << endl
             << "3.EXIT" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "AMOUNT TO DEPOSIT : ";
            cin >> depo;
            b1.deposit(depo);
            b1.display(depo, 0);
        }
        else if (choice == 2)
        {
            cout << "AMOUNT TO WITHDRAW : ";
            cin >> withdr;
            b1.withdraw(withdr);
        }
    }
}
