#include <iostream>
using namespace std;
void display1(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= 1 && arr[i] <= 3)
            cout << i + 1 << " ";
    }
    cout << endl;
}
void display2(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cout << i + 1 << " ";
    }
    cout << endl;
}
void display3(int arr[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 2)
            cout << i + 1 << " ";
    }
    cout << endl;
}
void display4(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 3)
            cout << i + 1 << " ";
    }
    cout << endl;
}
void display5(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 4)
            cout << i + 1 << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100], choice, i = 0, n;
    cout << "enter the number of customers:" << endl;
    cin >> n;
    cout << endl
         << "ented the choice" << endl
         << "1)only burger" << endl
         << "2)only pizza" << endl
         << "3)both" << endl
         << "4)none" << endl;
    cout << "enter the choice per customer:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "for custoner " << i + 1 << ":";
        cin >> arr[i];
    }
    while (1)
    {
        cout << "menu" << endl
             << "1)display customer with choice burger or pizza or both"
             << endl
             << "2)only burger" << endl
             << "3)only pizza" << endl
             << "4)both pizza and burger"
             << endl
             << "5)none " << endl
             << "6)exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "the customers are :" << endl;
            display1(arr, n);
            break;
        case 2:
            cout << "the customers arr :" << endl;
            display2(arr, n);
            break;
        case 3:
            cout << "the customers are :" << endl;
            display3(arr, n);
            break;
        case 4:
            cout << "the customers are :" << endl;
            display4(arr, n);
            break;
        case 5:
            cout << "tge customers are :" << endl;
            display5(arr, n);
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
    return 0;
}