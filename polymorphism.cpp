/* Demonstration of polymorphism */

#include <iostream>

using namespace std;

class Student
{
public:
    string name;

    Student(string name) : name(name) {};
    
    virtual void print()
    {
        cout << name << endl;
    }
};

class MedicalStudent : public Student
{
public:
    string speciality;

    MedicalStudent(string name, string speciality) : 
    speciality(speciality), Student(name) {};
    
    void print()                    // Overriding - Runtime Polymorphism
    {
        cout << name << " : " << speciality << endl;
    } 

};

int main()
{
    Student *students[] = 
    {
        new Student("Nithya"),
        new Student("Durga"),
        new MedicalStudent("Raj", "Radiology"),
        new MedicalStudent("Sheela", "Dentist")
    };

    for(int i=0; i<4; i++)
        students[i]->print();

    for(int i=0; i<4; i++)
        delete students[i];

    /*
    Instead of doing as follows, we can combine in the base class
    MedicalStudent *medical_students[] = 
    {
        new MedicalStudent("Raj", "Radiology"),
        new MedicalStudent("Sheela", "Dentist")
    };

    for(int i=0; i<2; i++)
        medical_students[i]->print();

    for(int i=0; i<2; i++)
        delete medical_students[i];
    */
}

/* 
If we call derived class from base class, it will not class the overrided class in derived class
        to access the overrided class from base class --> include virtual keyword
*/