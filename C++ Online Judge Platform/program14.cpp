// # Assignment-14 -> Sorting names in alphabetical order
#include <iostream>
using namespace std;

int main()
{
    // 10 -> names  &  20 -> size
    char names[10][20], original[10][20], str[20];
    int i, j, n;
    cout << "\n\n # Sorting Names # \n";
    cout << "\n* Enter the value of n: ";
    cin >> n;

    // # Enter names
    cout << "\n* Enter " << n << " names: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "  ";
        cin >> names[i];
        strcpy(original[i], names[i]);
    }

    // # Sorting names
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (strcmp(names[j - 1], names[j]) > 0)
            {
                strcpy(str, names[j - 1]);
                strcpy(names[j - 1], names[j]);
                strcpy(names[j], str);
            }
        }
    }

    // # Display
    cout << "\n-------------------------------------\n";
    cout << "Input Names \t| Sorted names\n";
    cout << "-------------------------------------\n";
    for (i = 0; i < n; i++)
    {
        cout << original[i] << "\t\t| " << names[i] << endl;
    }
    cout << "-------------------------------------\n";
    return 0;
}
