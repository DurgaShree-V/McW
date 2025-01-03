/* Demonstration of reference variable */

#include <iostream>
using namespace std;

void increment(int &x)
{
    x++;
}

int &max(int array[], int length)
{
    int max_index = 0;
    for(int i=0; i<length; i++)
        if(array[i] > array[max_index])
            max_index = i;
    return array[max_index];
}

int func(int x)
{
    return 3 * x;
}

int (&triple)(int) = func;

int main()
{
    int a = 2;
    int &b = a; // Reference variable must be intialized with a variable and by NULL
    b++; //If reference var is modified, change will be on variable a
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    int c = 5;
    b = c;   // only the value of c is passed and the reference of c
    b++;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << "c : " << c << endl;

    int array[] = {1,2,3,4,5};
    int &ref = array[2];
    ref += 5;
    for(int i=0; i<5; i++)
    {
        cout << "array["<< i <<"] : " << array[i] << endl;
    }

    int m=4;
    increment(m);   //Pass by reference
    cout << "m : "<< m << endl;

    int &max_val = max(array,5);
    cout << "max: "<< max_val << endl;
    max_val ++;
    for(int i=0; i<5; i++)
        cout << "array["<< i <<"] : " << array[i] << endl;
    
    cout << func(5) << endl;
    cout << triple(5) << endl;
    return 0;
}