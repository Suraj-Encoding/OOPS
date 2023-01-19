#include <iostream>
using namespace std;
int main()
{
    int i, j, n, count;

    cout << "Array length:";
    cin >> n;

    int set[100];
    cout << "Array input:";
    for (i = 0; i < n; i++)
    {
        cin >> set[i];
    }

    int flag[100] = {0};
    cout << "Output: " << endl
         << "Repeatednumber  Frequency" << endl;
    for (i = n - 1; i >= 0; i--)
    {
        count = 0;
        if (flag[i] != 1)
        {
            for (j = n - 1; j >= 0; j--)
            {
                if (set[i] == set[j])
                {
                    count++;
                    flag[j] = 1;
                }
            }
            if (count > 1)
            {
                cout << "    " << set[i] << "\t\t\t" << count << endl;
            }
        }
    }
    return 0;
}
