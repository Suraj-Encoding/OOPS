#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> A, B, C;
    char first[10], sec[10];
    int i;
    int a, b;

    cout << "Enter 1st Binary number: ";
    cin >> first;
    for (i = 0; first[i] != '\0'; i++)
    {
        if (first[i] == 0)
            A.push(0);
        else
            A.push(1);
    }

    cout << "Enter 2nd Binary number: ";
    cin >> sec;
    for (i = 0; sec[i] != '\0'; i++)
    {
        if (sec[i] == 0)
            B.push(0);
        else
            B.push(1);
    }

    int sum, carry = 0;
    while (!A.empty() || !B.empty())
    {
        a = 0, b = 0;
        if (!A.empty())
        {
            a = A.top();
            A.pop();
        }
        if (!B.empty())
        {
            b = B.top();
            B.pop();
        }

        sum = (carry + a + b) % 2;
        carry = (a + b + carry) / 2;
        C.push(sum);
    }
    if (carry == 1)
        C.push(1);
    cout << "Addition of binary number is: ";
    while (!C.empty())
    {
        cout << C.top();
        C.pop();
    }
    cout<<endl;
    return 0;
}