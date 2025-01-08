/* Matrix multiplication using Intrinsics */
#include <iostream>
#include <immintrin.h>

using namespace std;

void multiply_A_and_B(double a[4][4],double b[4][4],double result[4][4])
{
    __m256d mul_res, one_to_row_A, row_B, out;

    for(int i=0; i<4; i++)
    {
        out = _mm256_setzero_pd ();
        for(int j=0; j<4; j++)
        {
            one_to_row_A = _mm256_set1_pd (a[i][j]);
            row_B = _mm256_loadu_pd (&b[j][0]);

            mul_res = _mm256_mul_pd (one_to_row_A, row_B);
            out = _mm256_add_pd (out, mul_res);
        }
        _mm256_storeu_pd (&result[i][0], out);
    }
}

int main()
{
    double a[4][4],b[4][4],result[4][4];
    cout<<"Enter the elements of Matrix A"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"Enter the elements of Matrix B"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>b[i][j];
        }
    }

    multiply_A_and_B(a,b,result);

    cout<<"Output:" << endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<< result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}