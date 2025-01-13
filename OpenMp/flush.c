#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N        10000
#define SEED       2531
#define RAND_MULT  1366
#define RAND_ADD   150889
#define RAND_MOD   714025
#define NTHREADS 2 
int randy = SEED;
void fill_rand(int length, double *a)
{
   int i; 
   for (i=0;i<length;i++) {
     randy = (RAND_MULT * randy + RAND_ADD) % RAND_MOD;
     *(a+i) = ((double) randy)/((double) RAND_MOD);
   }   
}

/* function to sum the elements of an array */
double Sum_array(int length, double *a)
{
   int i;  double sum = 0.0;
   for (i=0;i<length;i++)  sum += *(a+i);  
   return sum; 
}

int main()
{
    double *A, sum, run_time;
    int numthreads,flag=0,flg_tmp;
    omp_set_num_threads(NTHREADS);
    A =(double *)malloc(N*sizeof(double));
    #pragma omp parallel
    {
        #pragma omp master
        {
        run_time = omp_get_wtime();
        }
        #pragma omp barrier
        #pragma omp sections
        {
        #pragma omp section    //Producer
        {
            fill_rand(N,A);   
            #pragma omp flush //Make the values of array A to be visible to all threads
            #pragma atomic write
                flag=1;
            #pragma omp flush(flag)
        }
        #pragma omp section //Consumer
        {
            #pragma omp flush(flag)
            while(1)
            {
                #pragma omp flush(flag)
                #pragma omp atomic read
                flg_tmp = flag;
                if(flg_tmp == 1) break;
            }
            #pragma omp flush
            sum = Sum_array(N,A);
        }
        }
        #pragma omp master
        {
            run_time = omp_get_wtime() - run_time;
        }
    }
    printf(" with %d threads and %lf seconds, The sum is %lf \n",numthreads,run_time,sum);
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
