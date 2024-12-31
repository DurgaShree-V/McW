/* Example - how to use assert method and how to avoid it */
#include <stdio.h>

#define NDEBUG              //To avoid assert in program, define ndebug
#include <assert.h>


int main()
{
    int x=5;
    assert(x>5);              // O/P : Assertion failed: x>5, file std_library.c, line 12
    printf("%d is greater than 5",x);
}