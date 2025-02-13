#include <iostream>
using namespace std;

void transpose(int A[4][4], int res[4][4], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            res[j][i] = A[i][j];
        }
    }
}

void reverse(int res[4][4], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n/2; j++)
        {
            int t = res[i][j];
            res[i][j] = res[i][n-j-1];
            res[i][n-j-1] = t;
        }
    }
}

void print(int A[4][4], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int A[4][4], res[4][4], inc = 1, n = 4;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            A[i][j] = inc++;
        }
    }

    cout << "The input matrix:" << endl;
    print(A,n);

    transpose(A,res,n);
    // print(res,n);
    reverse(res,n);
    
    cout << "Rotation by 90 degrees:" << endl;
    print(res,n);
    return 0;
}
