// # Assignment-13 -> Repeated numbers with their frequency count  in an array in min time complexity
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k = 0, temp, count = 0, flag, key;
    cout << "\n# Frequency Count #\n\n";
    cout << "* Enter number of elements in an array: ";
    cin >> n;

    int *arr = new int[n];
    int *un = new int[n];

    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n# Entered array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // Sort the given arrray
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

    // main logic
    cout << "Element\t| Frequency" << endl;
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
            cout << "  " << key << "\t|    " << count << endl;
            flag = key;
            un[k] = key;
            k++;
        }
    }

    // Display unique elements of array
    cout << "\n# Display unique array: " << endl;
    for (i = 0; i < k; i++)
    {
        cout << un[i] << " ";
    }
    cout << "\n\n";

    delete[] arr;
    return 0;
}
// # Time Complexity: T = n+n+n2+n2+n = 3n+2n2 ==> O(n2)
