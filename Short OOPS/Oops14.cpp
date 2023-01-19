#include <iostream>
#include <string.h>
using namespace std;

void Sortselection(char arr[][20], int n);

int main()
{
    int n, i;
    char arr[20][20];

    cout << "enter the number of names:" << endl;
    cin >> n;
    cout << endl
         << "enter the names :" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "Given names are" << endl;
    for (i = 0; i < n; i++)
        cout << i + 1 << ": " << arr[i] << endl;

    Sortselection(arr, n);

    cout << "Sorted names are"<<endl;
    for (i = 0; i < n; i++)
        cout << i + 1 << ": " << arr[i] << endl;

    return 0;
}
void Sortselection(char arr[][20], int n)
{
    int i, j, min;
    char Str1[20];
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        strcpy(Str1, arr[i]);
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(Str1, arr[j]) > 0)
            {
                strcpy(Str1, arr[j]);
                min = j;
            }
        }

        if (min != i)
        {
            char temp[20];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min]);
            strcpy(arr[min], temp);
        }
    }
}