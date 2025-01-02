/* Explore new and delete operator */

#include <iostream>

using namespace std;

class Student{
public:
    string name;
    void print()
    {
        cout << "My name is " << name << endl;
    }
};

int main()
{
    int x = 4;

    int *ptr_to_int = new int; //Allocating space in heap
    *ptr_to_int = 15;          //Assign value to the pointed address

    /*int *ptr_to_int = new int(15);*/

    cout<< "ptr_to_int : "<< ptr_to_int << endl;
    cout<< "*ptr_to_int : "<< *ptr_to_int << endl;
    
    delete ptr_to_int;         //Free the space alloacted

    double *array = new double[3];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    for(int i=0;i<3;i++){
        cout << "array[" << i << "] = " << array[i] << endl;
    }
    delete[] array;

    Student *s1 = new Student;
    s1->name = "Nithya";
    s1->print();

    (*s1).name = "Durga";
    (*s1).print();
    return 0;
}

/*

Stack is used to store the data during compile time
Heap is used to store the data during run time 

new -> dynamically allocating data in Heap area
delete -> free the space allocated in Heap area 

 */

/*
STACK 
--------------
Variable     Memory_address    Value
x            0x0001            4
ptr_to_int   0x0002            0x9901
             0x0003
             ...
             ...
 

HEAP
--------------
             0x9901            15
             0x9902
             0x9903
             ...

*/