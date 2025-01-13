#include <iostream>
#include <omp.h>

int fib(int n)
{
    int x,y;
    if(n>2)
        return n;
    #pragma omp task shared(x)
        x = fib(n-1);
    #pragma omp task shared(y)
        y = fib(n-2);
    #pragma omp taskwait
        return x+y;
}
/*If the variables x and y are not shared, 
    it cannot be used by 3rd statement x+y*/
int main()
{
   fib(5);
}