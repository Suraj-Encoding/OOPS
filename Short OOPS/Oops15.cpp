#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i = 0, a;
    char b, choice;
    do
    {
        cout << endl
             << "enter a character to check :" << endl;
        cin >> b;
        a = ((int)b);
        if ((a >= 32 && a <= 47) || (a >= 60 && a <= 64) || (a >= 91 && a <= 96) || (a >= 123 && a <= 126))
        {
            cout << "character " << b << " is a special character." << endl;
        }
        else if ((a > 64 && a < 91) || (a > 96 && a < 123))
        {
            cout << "character " << b << " is a alphabate." << endl;
        }
        else if (a >= 48 && a <= 57)
        {
            cout << "character " << b << " is a number." << endl;
        }
        else
        {
            cout << "not a valid character." << endl;
        }
        cout << "want to continue:y)yes" << endl;
        cin >> choice;
    } while (choice == 'y');

    return 0;
}