/* Use of friend function */

#include <iostream>
using namespace std;

class MyClass
{
    friend void double_x(MyClass &obj);

private:
    int x;
    void add(int n)
    {
        x += n;
    }

public:
    MyClass(int x)
    {
        this->x = x;
    }
    //MyClass(int x) : x(x) {};
    void print()
    {
        cout << "x : " << x << endl;
    }
};

void double_x(MyClass &obj)
{
    obj.x *= 2;
    cout << "x : " << obj.x << endl;
    obj.add(4);
    obj.print();
}

class Costs;

class Revenue
{
    friend bool profit(Revenue rev, Costs cos);

private:
    int revenue;

public:
    Revenue(int revenue) : revenue(revenue) {}
};

class Costs
{
    friend bool profit(Revenue rev, Costs cos);

private:
    int costs;

public:
    Costs(int costs) : costs(costs) {}
};

bool profit(Revenue rev, Costs cos)
{
    if(rev.revenue > cos.costs)
        return true;
    else
        return false;
}

int main()
{
    MyClass myobj(25);
    myobj.print();
    //myobj.add(4); /*Error: Private member function cannot be accessed outside class without friend function*/
    double_x(myobj);

    Revenue revenue(1000);
    Costs cost(500);

    if(profit(revenue, cost))
        cout << "Profit!" << endl;
    else
        cout << "No Profit!" << endl;
    return 0;
}

/*
Friend functions --> can access both private and protected members of a class
*/