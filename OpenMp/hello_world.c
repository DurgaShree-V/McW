/* Hello world using Parallel Programming */

#include <omp.h>
#include <stdio.h>


int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
    int ID = omp_get_thread_num();
    printf("Hello(%d)", ID);
    printf("World(%d)", ID);
    }
    return 0;
}