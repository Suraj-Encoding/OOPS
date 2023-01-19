// # Assignment-1 -> Bank account system
#include <iostream>
#include <iomanip>
using namespace std;

// # Class Bank
class Bank
{
private:
  string name;
  int ac_no;
  int bal;
  string ac_type;

public:
  void Initial(int i);
  void deposit(int i);
  void withdraw(int i);
  void display(int i);
  Bank();
  ~Bank();
};

// *** Function Definations ***

// # Constructor
Bank ::Bank()
{
  cout << "Constructor.." << endl;
  name = "null";
  ac_no = 0;
  ac_type = "null";
  bal = 0;
}

// # Destructor
Bank ::~Bank()
{
  name = "null";
  ac_no = 0;
  ac_type = "null";
  bal = 0;
  cout << "Object Destroyed.." << endl;
}

// # Initial
void Bank ::Initial(int i)
{
  if (i == 1)
    cout << "\n# Enter details:\n";
  cout << "\n* Enter Customer-" << i << " details: \n";
  cin.ignore();
  cout << "Enter Name: ";
  getline(cin, name);
  cout << "Enter A/c Type: ";
  getline(cin, ac_type);
  cout << "Enter A/c no: ";
  cin >> ac_no;
  cout << "Enter Opening Balance: ";
  cin >> bal;
}

// # Deposit
void Bank ::deposit(int i)
{
  int deposit = 0;
  if (i == 1)
    cout << "\n# Deposit" << endl;
  cout << "\nCustomer-" << i << endl;
  cout << "Enter Deposit Amount: ";
  cin >> deposit;
  cout << "Deposit Balance = " << deposit << endl;
  bal += deposit;
}

// # Withdraw
void Bank ::withdraw(int i)
{
  int withdraw, flag = 0;
  if (i == 1)
    cout << "\n# Withdraw" << endl;
  cout << "\nCustomer-" << i << endl;
  cout << "Balance Amount = " << bal;
  cout << "\nEnter Withdraw Amount: ";
  cin >> withdraw;
  if (withdraw > bal)
  {
    cout << "Insufficient Balance!" << endl;
    flag = 1;
  }
  if (flag == 0)
  {
    bal -= withdraw;
    cout << "After withdrawal account balance is: " << bal << endl;
  }
}

// # Display
void Bank ::display(int i)
{

  if (i == 1)
  {
    cout << "\n# CUSTOMER DETAILS # \n"
         << endl;
    cout << left << setw(10) << "SR No";
    cout << left << setw(10) << "Name";
    cout << left << setw(10) << "A/c Type";
    cout << left << setw(10) << "A/c No";
    cout << left << setw(10) << "Balance";
    cout << endl;
  }
  cout << left << setw(10) << i;
  cout << left << setw(10) << name;
  cout << left << setw(10) << ac_type;
  cout << left << setw(10) << ac_no;
  cout << left << setw(10) << bal;
  cout << endl;
}

// # Main Function
int main()
{
  int ch, n, i;
  cout << "\n ## Smart City Bank ## \n";
  cout << "\nEnter number of customers: ";
  cin >> n;
  Bank *customer = new Bank[n];
  do
  {
    cout << "\n* Bank Menu * \n1.To Assign Initial Value \n2.To Deposit \n3.To Withdraw \n4.To Display All Details \n0.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      for (i = 0; i < n; i++)
        customer[i].Initial(i + 1);
      break;

    case 2:
      for (i = 0; i < n; i++)
        customer[i].deposit(i + 1);
      break;

    case 3:
      for (i = 0; i < n; i++)
        customer[i].withdraw(i + 1);
      break;

    case 4:
      for (i = 0; i < n; i++)
        customer[i].display(i + 1);
      break;

    case 0:
      cout << "\n* You are exit!\n\n";
      exit(0);
      break;

    default:
      cout << "\nInvalid Choice!" << endl;
      break;
    }
  } while (1);
  return 0;
}

/*
        # Note:  obj.read(); -> object 'obj' is implicitly passed as a argument to a current method that is read()
                 and we can use 'a' and 'b' in read function which is nothing but obj.a and obj.b
                 and 'this = obj'
*/