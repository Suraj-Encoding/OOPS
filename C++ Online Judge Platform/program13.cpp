// # Assignment-13 -> Frequency Count
// # Using bubble sort
// # O(n2)
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, i, j, temp, count = 0, flag, key;
    cout << "\n# Frequency Count #\n\n";
    cout << "* Enter number of elements in an array: ";
    cin >> n;
    int *arr = new int[n];
    
    // # Enter array
    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // # Sorting array - Bubble Sort
    for (i = 0; i < (n - 1); i++)
    {
        flag = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
   }

    // # main logic
    cout << "Element" <<setw(10) <<"Frequency" << endl;
    flag = -1;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        count = 0;
        for (j = i; j < n; j++)
        {
            if (key == arr[j])
                count++;
        }
        if (flag == key)
        {
        }
        else
        {
            cout << key <<setw(10)<< count << endl;
            flag = key;
        }
    }
    return 0;
}

