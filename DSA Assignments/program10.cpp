// # Assignment-10 -> Set Implementation
// # Concept Used: Using Arrays
#include <iostream>
using namespace std;

// # Class Set
class Set
{
private:
    int no;          // no of customers
    string name[30]; // name of customers

public:
    void Read();
    void Display();
    Set Union(Set B);
    Set Inter(Set B);
    Set AB(Set B); // AB means A-B
    Set BA(Set B); // BA means B-A
    Set Compliment(Set U);
    void Number();
};

// ** Function Definations **

// # Read
void Set ::Read()
{
    cout << "\nEnter the number of customers: ";
    cin >> no;
    cout << "Enter customer names in set: " << endl;
    for (int i = 0; i < no; i++)
    {
        cin >> name[i];
    }
}

// # Display
void Set ::Display()
{
    if (no == 0)
    {
        cout << "{}" << endl;
        return;
    }
    for (int i = 0; i < no; i++)
    {
        if (i == 0)
            cout << "{";
        if (i == no - 1)
            break;
        cout << name[i] << ",";
    }
    cout << name[no - 1] << "}" << endl;
}

// # Cardinality -> Number of elements in set
void Set ::Number()
{
    cout << no;
}

// # (A-B)
Set Set::AB(Set B)
{
    Set C;
    string s[30];
    int c = 0, f;

    for (int i = 0; i < no; i++)
    {
        f = 0;
        for (int j = 0; j < B.no; j++)
        {
            if (name[i] == B.name[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            s[c] = name[i];
            c++;
        }
    }
    C.no = c;
    for (int i = 0; i < c; i++)
    {
        C.name[i] = s[i];
    }
    return C;
}

// # (B-A)
Set Set::BA(Set B)
{
    Set C;
    string s[30];
    int c = 0, f;

    for (int i = 0; i < B.no; i++)
    {
        f = 0;
        for (int j = 0; j < no; j++)
        {
            if (B.name[i] == name[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            s[c] = B.name[i];
            c++;
        }
    }
    C.no = c;
    for (int i = 0; i < c; i++)
    {
        C.name[i] = s[i];
    }
    return C;
}

// # (AnB) -> Intersection
Set Set::Inter(Set B)
{
    Set C;
    int v = 0;
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < B.no; j++)
        {
            if (name[i] == B.name[j])
            {
                C.name[v] = name[i];
                v++;
            }
        }
    }
    C.no = v;
    return C;
}

// # (AUB) -> Union
Set Set ::Union(Set B)
{
    Set C;
    int j = 0, f = 0, c;
    string s[30];
    for (int i = 0; i < no; i++)
    {
        s[i] = name[i];
    }
    c = no;
    for (int i = 0; i < B.no; i++)
    {
        f = 0;
        for (j = 0; j < no; j++)
        {
            if (name[j] == B.name[i])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            s[c] = B.name[i];
            c++;
        }
    }
    C.no = c;
    for (j = 0; j < c; j++)
    {
        C.name[j] = s[j];
    }
    return C;
}

// # (AUB)' -> Compliment of Union Set
Set Set::Compliment(Set U)
{
    Set C;
    string s[30];
    int j = 0, f = 0, c = 0, v = 0;

    for (int i = 0; i < no; i++)
    {
        f = 0;
        for (j = 0; j < U.no; j++)
        {
            if (name[i] == U.name[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            s[c] = name[i];
            c++;
        }
    }
    C.no = c;
    for (j = 0; j < c; j++)
    {
        C.name[j] = s[j];
    }
    return C;
}

// # Main
int main()
{
    // Types of Sets
    Set SetU, SetA, SetB, Result, U;

    cout << "\n# SETS CONCEPT #\n";
    cout << "\n  SET A - Customers who like Pizza \n  SET B - Customers who like Burger" << endl;

    cout << "\n# ENTER SETS: " << endl;

    cout << "\n# Enter Universal Set: ";
    SetU.Read();
 
    cout << "\n# Enter Set A: ";
    SetA.Read();

    cout << "\n# Enter Set B: ";
    SetB.Read();

    cout << "\n# DISPLAY ALL SETS # \n";

    cout << "\n# UNIVERSAL SET (U) = ";
    SetU.Display();
    cout << "  * n(U) = ";
    SetU.Number();

    cout << "\n\n# SET A = ";
    SetA.Display();
    cout << "  * n(A) = ";
    SetA.Number();

    cout << "\n\n# SET B = ";
    SetB.Display();
    cout << "  * n(B) = ";
    SetB.Number();

    cout << "\n\n1. Set of customers who like either pizza or burger or both: " << endl;
    cout << "   * Union Set (AUB) = ";
    Result = SetA.Union(SetB);
    Result.Display();
    U = Result;
    cout << "   * n(AUB) = ";
    Result.Number();

    cout << "\n\n2. Set of customers who like both pizza and burger: " << endl;
    cout << "   * Intersection Set (AnB) = ";
    Result = SetA.Inter(SetB);
    Result.Display();
    cout << "   * n(AnB) = ";
    Result.Number();

    cout << "\n\n3. Set of customers who like only pizza, not burger: " << endl;
    cout << "   * (A-B) = ";
    Result = SetA.AB(SetB);
    Result.Display();
    cout << "   * n(A-B) = ";
    Result.Number();

    cout << "\n\n4. Set of customers who like only burger, not pizza: " << endl;
    cout << "   * (B-A) = ";
    Result = SetA.BA(SetB);
    Result.Display();
    cout << "   * n(B-A) = ";
    Result.Number();

    cout << "\n\n5. Set of customers who like neither pizza nor burger: " << endl;
    cout << "   * (AUB)' = "; // n(AUB)' =  n(U) - n(AUB)
    Result = SetU.Compliment(U);
    Result.Display();
    cout << "   * n(AUB)' = ";
    Result.Number();
    cout << "\n\n";

    return 0;
}
// ** Done **