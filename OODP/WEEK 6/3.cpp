#include <iostream>
using namespace std;

// Base class Person
class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }

    void displayName() {
        cout << "Name: " << name << endl;
    }
};

// Derived class Teacher
class Teacher : public Person {
protected:
    string subject;

public:
    void setSubject(string sub) {
        subject = sub;
    }

    void displaySubject() {
        cout << "Subject: " << subject << endl;
    }
};

// Further derived class Professor
class Professor : public Teacher {
protected:
    string department;

public:
    void setDepartment(string dept) {
        department = dept;
    }

    void displayDepartment() {
        cout << "Department: " << department << endl;
    }
};

int main() {
    Professor prof;
    prof.setName("Dr. Smith");
    prof.setSubject("Computer Science");
    prof.setDepartment("Engineering");

    prof.displayName();
    prof.displaySubject();
    prof.displayDepartment();

    return 0;
}