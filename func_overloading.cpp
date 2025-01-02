/*Example of function Overloading*/

#include <iostream>

void display(int val)
{
    std::cout<<"The favourite value is "<< val <<std::endl;
}

void display(char c)
{
    std::cout<<"The favourite character is "<< c <<std::endl;
}

void display(char *str)
{
    std::cout<<"My name is "<< str <<std::endl;
}

int main()
{
    display("Durga");
    display(3);
    display('d');
}