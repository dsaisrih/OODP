#include <iostream>
using namespace std;

// Abstract class Student
class Student {
public:
    virtual void study() = 0; // Pure virtual function
};

// Derived class Undergraduate
class Undergraduate : public Student {
public:
    void study() override {
        cout << "Undergraduate student studies general subjects." << endl;
    }
};

// Derived class Postgraduate
class Postgraduate : public Student {
public:
    void study() override {
        cout << "Postgraduate student studies specialized subjects." << endl;
    }
};

int main() {
    Student* student1 = new Undergraduate();
    Student* student2 = new Postgraduate();

    student1->study(); // Calls Undergraduate's study()
    student2->study(); // Calls Postgraduate's study()

    delete student1;
    delete student2;

    return 0;
}