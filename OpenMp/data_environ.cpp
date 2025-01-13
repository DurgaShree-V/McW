#include <iostream>
#include <omp.h>
double A[10];
int main()
{
    int index[10];
    #pragma omp parallel
    {
        work(index);
    }
    printf("%d\n",index[0]); 
    
}
extern double A[10];
void work(int *index)
{
    double temp[10];
    static int count;
}

/*
Here shared variables are 
        --> A,index,count
    private variables to the each thread are
        --> temp[10]
        
Scope variables, static decides the variable is shared or private
*/