// # Assignment-9 -> Part-1
// # STL Stack
// # Binary Addition Using STL Stack
#include <iostream>
#include <stack> //...STL STACK
using namespace std;

// # GLOBAL
int *arr1, *arr2;
int n1, n2;

/* READ BINARY NUMBER */
stack<int> read(int k)
{
    stack<int> s;
    int x, n, i;
    cout << "  Enter Bits: ";
    cin >> n;
    if (k == 1)
    {
        n1 = n;
        arr1 = new int[n1];
    }
    if (k == 2)
    {
        n2 = n;
        arr2 = new int[n2];
    }
    cout << "  Enter Binary Number: ";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
        if (k == 1)
            arr1[i] = x;
        if (k == 2)
            arr2[i] = x;
    }
    return s;
}

/* DISPLAY BINARY NUMBERS */
void display(int k)
{
    if (k == 1)
    {
        for (int i = 0; i < n1; i++)
            cout << arr1[i] << " ";
    }
    if (k == 2)
    {
        for (int i = 0; i < n2; i++)
            cout << arr2[i] << " ";
    }
}

/* DISPLAY BINARY ADDITION */
void display(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

/* ADDITION OF TWO BINARY NUMBERS */
stack<int> add(stack<int> &s1, stack<int> &s2)
{
    stack<int> s;
    int sum, carry = 0, b1, b2;
    while (!s1.empty() || !s2.empty())
    {
        b1 = b2 = 0;
        if (!s1.empty())
        {
            b1 = s1.top();
            s1.pop();
        }
        if (!s2.empty())
        {
            b2 = s2.top();
            s2.pop();
        }
        sum = (b1 + b2 + carry) % 2;
        carry = (b1 + b2 + carry) / 2;
        s.push(sum);
    }
    if (carry == 1)
        s.push(1);
    return s;
}

// # Main Function
int main()
{
    // # STL STACK
    stack<int> s1, s2, s3;
    int ch;
    cout << "\n# Binary Addition #\n";
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1...Read Binary Numbers"
             << "\n2...Display Binary Numbers"
             << "\n3...Display Binary Addition"
             << "\n4...Exit";
        cout << "\nEnter your choice..";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n# Read # " << endl;
            cout << "\n# Read First Binary Number: " << endl;
            s1 = read(1);
            cout << "\n# Read Second Binary Number: " << endl;
            s2 = read(2);
            break;

        case 2:
            cout << "\n# Display # " << endl;
            cout << "\n  Binary-1:  ";
            display(1);
            cout << "\n  Binary-2:  ";
            display(2);
            cout << "\n";
            break;

        case 3:
            cout << "\n# Binary Addition: ";
            cout << "\n  New Binary:  ";
            s3 = add(s1, s2);
            display(s3);
            cout << "\n";
            break;

        case 4:
            cout << "\n* You are exit...!\n\n";
            exit(0);
            break;

        default:
            cout << "\n* Invalid Choice..!" << endl;
            break;
        }
    } while (1);
    return 0;
}
