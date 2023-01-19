// # Assignment-14 -> Sorting names in alphabetical order
#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    // 10 -> names  &  20 -> size
    char names[10][20],str[20];
    int i, j, n;
    cout << "\n\n # Sorting Names # \n";
    cout << "\n* Enter number of names: ";
    cin >> n;
    
    // # Enter names
    cout << "\n* Enter " << n << " names: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "  ";
        cin >> names[i];
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
    cout<<"\n# Sorted Names: \n  ";
    for (i = 0; i < n; i++)
    {
        cout<<names[i]<<" ";
    }
    cout<<"\n\n";
    return 0;
}
