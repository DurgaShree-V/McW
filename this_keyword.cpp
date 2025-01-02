/* Use of this keyword */

#include <iostream>
using namespace std;

class Student;

void create_report(Student *s);

class Student 
{
    public:
        string name;
        int age;

        Student(string name, int age)
        {
            this->name = name;
            this->age = age;
            cout << "Memory address of this: " << this << endl;
        }

        void increase_age()
        {
            this->age = this->age + 1;
        }

        void increase_and_output_age()
        {
            this->increase_age();
            cout << "Name : "<< this->name << endl;
            cout << "Age : "<< this->age << endl;
        }

        void graduate()
        {
            cout << "\nCongrats!" << endl;
            create_report(this);
        }

        Student& set_name(string name)
        {
            this->name = name;
            return *this;
        }

        Student& set_age(int age)
        {
            this->age = age;
            return *this;
        }
};

void create_report(Student *s)
{
    cout << "student report\n-------------\nName : "<< s->name << "\nAge : "<< s->age << endl;
}

int main()
{
    Student s1("Nithya",24);
    cout << "Memory address of s1 object: " << &s1 << endl;
    s1.increase_and_output_age();
    s1.graduate();
    s1.set_name("Durga").set_age(21);
    //create_report(&s1);
    return 0;
}