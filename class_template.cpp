/* Demonstration of class template */

#include <iostream>
using namespace std;

template <typename T> 
/*If length wants to be mentioned,then add it near typename
template <typename T, int no_of_values>
*/
class Array
{
public:
    T array[10];                // T array[no_of_values]

    void fill(T val)
    {
        for(int i=0; i<10; i++) // i<no_of_values
            array[i] = val;
    }

    T& at(int index)
    {
        return array[index];
    }
};

int main()
{
    Array<int> intArr;          // Ex : Array<int,5> name
    intArr.fill(25);
    cout << "intArray[8] : " << intArr.at(8) << endl;

    Array<string> stringArr;
    stringArr.fill("Prasanna");
    cout << "stringArray[8] : " << stringArr.at(8) << endl;

    return 0;
}

/*
Instead of declaring the same class definition 
and a change in only the datatypes, 
we can you class template 

Program 
---------

class IntArray
{
public:
    int array[20];

    void fill(int val)
    {
        for(int i=0; i<20; i++)
            array[i] = val;
    }

    int& at(int index)
    {
        return array[index];
    }
};

class StringArray
{
public:
    string array[20];

    void fill(string val)
    {
        for(int i=0; i<20; i++)
            array[i] = val;
    }

    string& at(int index)
    {
        return array[index];
    }
};
*/