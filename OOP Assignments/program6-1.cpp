// # Assignment-6 -> Matrix Arithmetic
// # Using Operator Overloading
#include <iostream>
using namespace std;

#define N 4
int flag = 0;

// # Matrix Class
class Matrix
{
private:
    int rows, col;
    int arr[N][N];
    int k;

public:
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    friend istream &operator>>(istream &in, Matrix &m);
    friend ostream &operator<<(ostream &out, Matrix &m);
    Matrix(int k)
    {
        this->k = k;
        rows = 0;
        col = 0;
    }
    ~Matrix()
    {
        rows = 0;
        col = 0;
        k = 0;
    }
};

// *** Function Definations ***

Matrix Matrix ::operator+(Matrix m2)
{
    // Resultant matrix is
    int i, j;
    Matrix m3(3);
    if (flag == 1 || flag == 0)
    {
    }
    else
    {
        try
        {
            if (rows != m2.rows | col != m2.col)
            {
                throw 1;
            }
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < col; j++)
                    {
                        m3.arr[i][j] = arr[i][j] + m2.arr[i][j];
                    }
                }
                m3.rows = rows;
                m3.col = col;
            }
        }

        catch (int e)
        {
            cout << "\n* Matrix order should be same.." << endl;
        }
    }
    return m3;
}

Matrix Matrix ::operator-(Matrix m2)
{
    // Resultant matrix is
    int i, j;
    Matrix m3(3);
    if (flag == 1 || flag == 0)
    {
    }
    else
    {
        try
        {
            if (rows != m2.rows | col != m2.col)
            {
                throw 1;
            }
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < col; j++)
                    {
                        m3.arr[i][j] = arr[i][j] - m2.arr[i][j];
                    }
                }
                m3.rows = rows;
                m3.col = col;
            }
        }
        catch (int e)
        {
            cout << "\n* Order should be same.." << endl;
        }
    }
    return m3;
}

Matrix Matrix ::operator*(Matrix m2)
{
    int i, j, k, sum;
    Matrix m3(3);
    if (flag == 1 || flag == 0)
    {
    }
    else
    {
        try
        {
            if (col != m2.rows)
            {
                throw 1;
            }
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < m2.col; j++)
                    {
                        sum = 0;
                        for (k = 0; k < col; k++)
                        {
                            sum = sum + (arr[i][k] * m2.arr[k][j]);
                        }
                        m3.arr[i][j] = sum;
                    }
                }
                m3.rows = rows;
                m3.col = m2.col;
            }
        }
        catch (int e)
        {
            cout << "\n* You can't multiply.." << endl;
        }
    }
    return m3;
}

istream &operator>>(istream &in, Matrix &m)
{
    int i, j;
    flag = 2;
    cout << "\n# Matrix-" << m.k << " : " << endl;
    cout << "Enter rows: ";
    in >> m.rows;
    cout << "Enter columns: ";
    in >> m.col;
    try
    {
        if (m.rows == 0 || m.col == 0 || m.rows > N || m.col > N)
        {
            throw 1;
        }
        {
            cout << "\n* Enter matrix-" << m.k << " : " << endl;
            for (i = 0; i < m.rows; i++)
            {
                for (j = 0; j < m.col; j++)
                {
                    in >> m.arr[i][j];
                }
            }
        }
    }
    catch (int e)
    {
        cout << "\n* Size Overflow.." << endl;
        flag = 1;
    }
    return in;
}

ostream &operator<<(ostream &out, Matrix &m)
{
    int i, j;
    if (m.k == 3)
    {
        cout << "\n# Resultant matrix is: " << endl;
    }
    else
    {
        cout << "\n# Matrix-" << m.k << " is: " << endl;
    }
    if (flag == 1 || flag == 0)
    {
        cout << "* Please Enter matrix first..." << endl;
    }
    else
    {
        for (i = 0; i < m.rows; i++)
        {
            for (j = 0; j < m.col; j++)
            {
                out << m.arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return out;
}

// # Main Function
int main()
{
    cout << endl;
    Matrix m1(1), m2(2), m(3);
    cout << "\n # Matrix Arithmetic #\n";
    int ch;
    do
    {
        cout << "\n# Menu: \n1.Set Matrix \n2.Get Matrix \n3.Addition \n4.Subtraction \n5.Multiplication \n6.Exit \nEnter your choice:  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> m1;
            cin >> m2;
            break;

        case 2:
            cout << m1;
            cout << m2;
            break;

        case 3:
            m = m1 + m2;
            cout << m;
            break;

        case 4:
            m = m1 - m2;
            cout << m;
            break;

        case 5:
            m = m1 * m2;
            cout << m;
            break;

        case 6:
            cout << "\n* You are exit!\n";
            cout << endl;
            exit(0);
            break;

        default:
            cout << "\n* Invalid choice!" << endl;
            break;
        }
    } while (1);
    return 0;
}
// *** Done ***