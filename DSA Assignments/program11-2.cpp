// # Assignment-11 -> Ticket Booking System
#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

class cinema
{
public:
    node *h[15][10];
    cinema()
    {
        int i, j;
        for (i = 0; i < 15; i++)
        {
            h[i][0] = new node;
            h[i][0]->data = 0;
            h[i][0]->next = h[i][1];
            h[i][0]->prev = NULL;
        }
        for (i = 0; i < 15; i++)
        {
            for (j = 1; j < 10; j++)
            {
                h[i][j] = new node;
                h[i][j]->data = 0;
                if (j < 9)
                    h[i][j]->next = h[i][j + 1];
                else
                    h[i][j]->next = NULL;
                h[i][j]->prev = h[i][j - 1];
            }
        }
    }

    int check(int row, int seat)
    {
        return (h[row][seat]->data);
    }

    void book()
    {
        int row, seat, check_seat, ch;
    xyz:
        cout << "\nEnter the row number (1-15): ";
        cin >> row;
        cout << "Enter seat number(1-10): ";
        cin >> seat;
        check_seat = check(row - 1, seat - 1);
        if (check_seat == 0)
        {
            h[row - 1][seat - 1]->data = 1;
            cout << "\nSuccesfully booked" << endl;
            cout << "want to book more (1.yes): ";
            cin >> ch;
            if (ch == 1)
                goto xyz;
        }
        else
        {
            cout << "Seat not available try different seat" << endl;
            goto xyz;
        }
    }

    void cancel()
    {
        int row, seat, check_seat;
        cout << "\nEnter the row number (1-15): ";
        cin >> row;
        cout << "Enter seat number(1-10): ";
        cin >> seat;
        check_seat = check(row - 1, seat - 1);
        if (check_seat == 1)
        {
            h[row - 1][seat - 1]->data = 0;
            cout << "Succesfully cancelled" << endl;
        }
        else
        {
            cout << "Seat is not booked yet" << endl;
        }
    }

    void display()
    {
        cout << "\n\n# Status: \n1 = Seat booked \n0 = Seat available\n\n";
        cout << "        ";
        for (int j = 1; j <= 10; j++)
        {
            cout << j << " ";
        }
        cout << endl;
        for (int i = 0; i < 15; i++)
        {
            cout << "Row " << setw(2) << (i + 1) << "|";
            for (int j = 0; j < 10; j++)
            {
                cout << " " << h[i][j]->data;
            }
            cout << endl;
        }
    }
};

int main()
{
    int i = 0, ch;
    cinema p;
    while (1)
    {
        cout << "\n Menu" << endl
             << "1.Booking" << endl
             << "2.Canceling" << endl
             << "3.Display Status" << endl
             << "4.Exit" << endl
             << "Enter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.book();
            break;
        case 2:
            p.cancel();
            break;
        case 3:
            p.display();
            break;
        case 4:
            cout << "\nExit...." << endl;
            exit(0);
            break;
        default:
            cout << "\nWrong choice." << endl;
            break;
        }
    }
    return 0;
}