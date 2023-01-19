#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i = 0, n, j;
xyz:
    cout
        << "note: the size should be a positive interger and less than 3." << endl
        << "enter the size of matrix:";
    cin >> n;
    try
    {
        if (n >= 4 || n <= 0)
        {
            throw n;
        }
    }
    catch (int p)
    {
        if (p >= 4)
        {
            cout << "\n\t\t !!!exception occurred!!!!" << endl
                 << "\tthe size should not be greater than 3. " << endl
                 << endl;
            goto xyz;
        }
        else
        {
            cout << "\n\t\t !!!exception occurred!!!!" << endl
                 << "\tthe size should not be zero or less than zero." << endl
                 << endl;
            goto xyz;
        }
    }
    int arr1[n][n], arr2[n][n];
    cout << "enter the elements of matrix 1:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "enter the elements of matrix 2:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }

    int choice, sum[n][n], sub[n][n], mult[n][n];
    while (1)
    {
        cout << "enter 1)addition 2)subtraction 3)multiplicatin " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "the addition of matrix 1 and matrix 2 is:" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    sum[i][j] = arr1[i][j] + arr2[i][j];
                    cout << sum[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            cout << "the subtraction of matrix 1 and matrix 2 is:" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    sub[i][j] = arr1[i][j] - arr2[i][j];
                    cout << sub[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            cout << "the multiplication of matrix 1 and matrix 2 is:" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    mult[i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        mult[i][j] = mult[i][j] + (arr1[i][k] * arr2[k][j]);
                    }
                    cout << mult[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
    return 0;
}