// # Assignment-13 -> Frequency Count
// # using counting sort
// # O(n+k)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // # Read n and array from user
    int n, i;
    cout << "\n# Enter number of elements in an array: ";
    cin >> n;
    int *a = new int[n];
    cout << "\n# Enter array: " << endl;
    cout<<"  ";
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

    // # Display count
    cout << "key" << setw(10) << "count" << endl;
    for (i = 0; i <= k; i++)
    {    
        if(count[i]!=0)
          cout << i << setw(10) << count[i] << endl;
    }
    cout << "\n";
    return 0;
}
