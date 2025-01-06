#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

#define NUM_THREADS 9

int main()
{   
    double p_start = omp_get_wtime();

    int i,nthreads;
    double pi,sum[NUM_THREADS];
    step = 1.0/(double)num_steps;

    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int i, id, no_of_threads;
        double x;
        
        id = omp_get_thread_num();
        no_of_threads = omp_get_num_threads();
        if(id == 0)
            nthreads = no_of_threads;
        
        for(i=id,sum[id]=0.0;i<num_steps;i+=no_of_threads)
        {
            x =(i+0.5) * step;
            sum[id] += 4.0 / (1.0 + x*x);
        }
        
        //printf("%2f\n",pi);   
    }
    for(i=0,pi=0.0;i<nthreads;i++)
    {
        pi = step * sum[i];
    }
    double p_end = omp_get_wtime();
    printf("\nTime taken for parallel prog: %2f\n",p_end - p_start);  


    /*
    double n_start = omp_get_wtime();
    int i;
    double x,pi,sum = 0.0;
    step = 1.0/(double)num_steps;

    for(i=0;i<num_steps;i++)
    {
        x =(i+0.5) * step;
        sum = sum + 4.0 / (1.0 + x*x);
    }
    pi = step * sum;
    //printf("%2f\n",pi);  
    double n_end = omp_get_wtime();
    printf("\nTime taken for normal prog: %2f",n_end - n_start);    
    */
}


/*
int ID = omp_get_thread_num();
int no_of_threads = omp_get_num_threads();
printf("ID: %d\nNo of threads: %d\n",ID,no_of_threads);
*/

