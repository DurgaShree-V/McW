/* Demonstration of inheritance */

#include <iostream>
using namespace std;

class MenuItem
{
public:
    string  name;
    double calories;

    void print()
    {
        cout << name << "( "<< calories << " cal )" << endl;
    }
};
//Derived class : Base class
class Drink : public MenuItem
{
public:
    double ounce;

    void cal_per_ounce()
    {
        cout << "cal / ounce = " << calories / ounce << endl;
    }
};
int main()
{
    MenuItem french_fries;
    french_fries.name = "French Fries";
    french_fries.calories = 300;
    french_fries.print();

    Drink hot_chocolate;
    hot_chocolate.name = "Hot Chocolate";
    hot_chocolate.calories = 500;
    hot_chocolate.ounce = 100;
    hot_chocolate.print();
    hot_chocolate.cal_per_ounce();

    MenuItem *ptr = &hot_chocolate;
    ptr->print();
    return 0;
}