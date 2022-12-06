// # Assignment-11 -> Ticket Booking System
// # Concept Used: Doubly Linked List
#include <iostream>
using namespace std;

// Node
class node
{
public:
    node *next;
    node *prev;
    int seat;
    string id;
    int status;
};

// Class
class cinemax
{
public:
    node *head, *tail, *temp;
    cinemax()
    {
        head = NULL;
    }
    void create_list();
    void display();
    void book();
    void cancel();
    void Available();
};

// ** Function Definations **

// # Create List
void cinemax::create_list()
{
    node *newnode;
    for (int i = 1; i <= 150; i++)
    {
        newnode = new node;
        newnode->seat = i;
        newnode->status = 0;
        newnode->id = "null";
        if (head == NULL)
        {
            tail = head = newnode;
            head->prev = NULL;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        tail->next = NULL;
    }
}

void cinemax::display()
{
    temp = head;
    int count = 0, flag = 1;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t## Seat Status ##\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    while (temp != NULL)
    {
        {
            if (flag == 1)
                cout << "| ";
            if (temp->seat >= 1 && temp->seat <= 9)
                cout << "S00" << temp->seat << " :";
            else if (temp->seat >= 10 && temp->seat <= 99)
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";

            if (temp->status == 0)
                cout << "|___| ";
            else
                cout << "|_B_| ";

            count++;
            flag = 0;
            if (count % 10 == 0)
            {
                flag = 1;
                cout << "|";
                cout << endl;
            }
            temp = temp->next;
        }
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
}

void cinemax::book()
{
    int x;
    string y;
    cout << "\n\n# Book Seat: " << endl;
label:
    cout << "Enter seat number to be booked: ";
    cin >> x;
    cout << "Enter your ID number: ";
    cin >> y;
    if (x < 1 || x > 150)
    {
        cout << "\n* Enter correct seat number to book (1-70)\n";
        goto label;
    }

    temp = head;
    while (temp->seat != x)
    {
        temp = temp->next;
    }

    if (temp->status == 1)
        cout << "\n* Seat is already booked!\n";
    else
    {
        temp->status = 1;
        temp->id = y;
        cout << "\n# Seat " << x << " is booked!" << endl;
    }
}

void cinemax::cancel()
{
    int x;
    string y;
    cout << "\n\n# Cancel Seat: " << endl;
label:
    cout << "\nEnter seat number to cancel booking: ";
    cin >> x;
    cout << "Enter you ID: ";
    cin >> y;
    if (x < 1 || x > 150)
    {
        cout << "\n* Enter correct seat number to cancel (1-70)\n";
        goto label;
    }

    temp = head;
    while (temp->seat != x)
    {
        temp = temp->next;
    }

    if (temp->status == 0)
    {
        cout << "\n* Seat is not booked yet..!\n";
    }
    else
    {
        if (temp->id == y)
        {
            temp->status = 0;
            cout << "\n* Seat is Cancelled..!\n";
        }
        else
            cout << "\n* Wrong User ID !!! Seat cannot be cancelled!!!\n";
    }
}

void cinemax::Available()
{
    int r = 1;
    temp = head;
    int count = 0, flag = 1;
    cout << "\n\n\n\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t## Seat Available Status ##\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    while (temp != NULL)
    {
        {
            if (flag == 1)
                cout << "| ";
            if (temp->seat >= 1 && temp->seat <= 9)
                cout << "S00" << temp->seat << " :";
            else if (temp->seat >= 10 && temp->seat <= 99)
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";

            if (temp->status == 0)
                cout << "|___| ";
            else if (temp->status == 1)
                cout << "| - | ";

            count++;
            flag = 0;
            if (count % 10 == 0)
            {
                cout << "|";
                cout << endl;
                flag = 1;
                r++;
            }
        }
        temp = temp->next;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------\n";
}

// # Main
int main()
{
    cinemax obj;
    obj.create_list();
    int ch;
    while (1)
    {
        cout << "\n\n**************************************\n";
        cout << " ## CINEMAX MOVIE THEATRE ##\n";
        cout << "**************************************\n";
        cout << "\n# Menu: \n1.Current Seat Status \n2.Book Seat \n3.Availableable Seat \n4.Cancel Seat \n5.Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.display();
            break;
        case 2:
            obj.book();
            break;
        case 3:
            obj.Available();
            break;
        case 4:
            obj.cancel();
            break;
        case 5:
            cout << "\n* You are exit \n\n";
            exit(0);
            break;
        default:
            cout << "\n* Invalid Choice \n";
            break;
        }
    }
    return 0;
}

// *** Done ***