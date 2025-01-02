/* Default parameter */

#include <iostream>

void print(int val,int b=10)
{
    std::cout<<"The value is "<<val << "and "<< b<<std::endl;
}

int main()
{
    print(5,3);    //  Function with a default parameter
    print(3);
    std::cout<<"Hello world"; //printing hello world
    /* just single comment // wrong */return 0;
}

/*If we declare a function with default parameter, 
then the remaining parameters must also be a default parameter
    void print(int a, int b = 6, int c = 5)  -->valid
    void print(int a, int b = 6, int c) -->invalid
*/