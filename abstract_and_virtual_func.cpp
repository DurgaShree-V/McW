/* Demonstration of abstract and virtual function */

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

class Square : public Shape
{
public:
    double side;

    Square(double side) : side(side) {}

    double area()
    {
        return side*side;
    }
};

class Triangle : public Shape
{
public:
    double base,height;

    Triangle(double base, double height) 
        : base(base) , height(height) {}

    double area()
    {
        return 0.5 * base *height;
    }
};

int main()
{
    Shape *shapes[] = 
    {
        new Square(2),
        new Triangle(2,3),
        new Square(3),
        new Triangle(4,5)
    };

    for(int i=0; i<4; i++)
    {
        cout<< "Shape " << i << ": " << shapes[i]->area() << endl;
    }
}

/*
Note
----------
1)If you mention a pure virtual function in a base class, 
    it becomes an abstract class
2)If you create a base class with a pure virtual function
    and you do not implement that function in the derived class, 
    that derived class would also become an abstract class
*/