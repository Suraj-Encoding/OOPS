// # Counting Sort
#include <iostream>
using namespace std;

int main()
{
    // # Read n and array from user
    int n, i;
    cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; i++)
        cin >> a[i];

    // # Max Element
    int k = a[0];
    for (i = 0; i < n; i++)
        if (a[i] >= k)
            k = a[i];

    // # Count array
    int *count = new int[k + 1];
    for (i = 0; i <= k; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        ++count[a[i]];

    int *temp = new int[k + 1];
    for (i = 0; i <= k; i++)
        temp[i] = count[i];

    for (i = 1; i <= k; i++)
        count[i] += count[i - 1];

    // # Sorting
    int *b = new int[n];
    for (i = 0; i < n; i++)
        b[--count[a[i]]] = a[i];

    // # Display
    int key = -1;
    for (i = 0; i < n; i++)
    {
        if (b[i] != key)
            cout << b[i] << "-" << temp[b[i]] << " ";
        key = b[i];
    }
    cout << "\n";
    return 0;
}
