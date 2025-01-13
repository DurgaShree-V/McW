#include <iostream>
#include <omp.h>

int main()
{
    double *A, sum, run_time;
    int numthreads,flag=0,N=2;
    A =(double *)malloc(N*sizeof(double));
    #pragma omp parallel sections
    {
        #pragma omp section    //Producer
        {
            fill_rand(N,A);   
            #pragma omp flush //Make the values of array A to be visible to all threads
            flag = 1;         //Shared variable
            #pragma atomic write
                flag=1;
            #pragma omp flush(flag)
        }
        #pragma omp section //Consumer
        {
            while(1)
            {
                #pragma omp flush(flag)
                #pragma omp atomic read
                    fig_tmp = flag;
                if(fig_tmp == 1)
                    break;
            }
            #pragma omp flush
            sum = Sum_array(N,A);
        }
    }
}
/*
The actions of Flush is to guarantee that:
    1) All R,W that overlaps with the flush set
    and occur prior to the flush complete 
    before the flush executes 
    2) All R,W that overlaps with the flush set
    and occur after to the flush complete 
    after the flush executes 
*/