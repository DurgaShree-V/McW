/* Maximum number using stdarg.h */

#include <stdio.h>
#include <stdarg.h>

int maximum(int num_of_args, ...)
{
    va_list args;

    va_start(args,num_of_args); //c represents the last argument before ...
    int max = 0;
    for(int i=0;i<num_of_args;i++)
    {
        int x = va_arg(args, int);
        if(i == 0){
            max = x;
        }
        else if(x > max){
            max = x;
        }
    }
    va_end(args);

    return max;
}

int main()
{
    int max_num = maximum(5, 4, 7, 10, 20, 3);
    printf("Maximum value: %d",max_num);
}