// # Assignment-15 -> Program to Check Character is Uppercase, Lowercase, Digit or Special Character
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "\n\n# Character Detector # \n\n";
    cout << "# Enter character: ";
    cin >> ch;
    cout << "\n# Character = " << ch << endl;
    // By Using ASCI Values 
    if (ch >= 65 && ch <= 90)
        cout << "\n* You entered an UPPERCASE character..!";
    else if (ch >= 97 && ch <= 122)
        cout << "\n* You entered a LOWERCASE character..!";
    else if (ch >= 48 && ch <= 57)
        cout << "\n* You entered a DIGIT..!";
    else
        cout << "\n* You entered a SPECIAL character..!";
    cout << "\n\n";
    return 0;
}