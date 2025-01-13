#include <iostream>
#include <omp.h>

#define MAX 50

void demo_of_private()
{
    int tmp = 0;
    #pragma omp parallel for private(tmp)
    {
        for(int j=0;j<1000;j++)
        {
            tmp += j;
        }
        printf("%d\n",tmp); //Provide the value of global variable tmp
    }
}
void demo_of_firstprivate()
{
    int incr = 0,i,A[10];
    #pragma omp parallel for firstprivate(incr) //Intializes the variable incr to global declaration
    {
        for(i=0;i<=MAX;i++)
        {
            if((i%2)==0)
                incr++;
            A[i] = incr;
        }
    }
}

int main()
{
    demo_of_private();
    demo_of_firstprivate();
}
/*
Private keyword creates a private variable to each threads and unintialized

firstprivate keyword creates a private variable to each threads and intialize with the global value to that variable

lastprivate keyword assigns the last iteration's value given to that thread
*/

/*
variables: A=1, B=1, C=1
#pragma omp parallel private(B) firstprivate(C)


--> Here B is uninitialized
         C is initialized to global declaration C=1

         Both B and C are local to each of the threads
            where A is shared variable.
*/