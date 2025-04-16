#include <iostream>
#include <string>

class Employee {
private:
    int empID;
    std::string name;
    double salary;
    std::string designation;

public:
    // Parameterized constructor
    Employee(int id, std::string n, double sal, std::string desig)
        : empID(id), name(n), salary(sal), designation(desig) {
        std::cout << "Parameterized Employee constructor called for " << name << std::endl;
    }

    // Copy constructor
    Employee(const Employee& other)
        : empID(other.empID), name(other.name), salary(other.salary), designation(other.designation) {
        std::cout << "Copy constructor called for " << name << std::endl;
    }

    // Function to display employee details
    void displayDetails() const {
        std::cout << "Employee ID: " << empID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
        std::cout << "Designation: " << designation << std::endl;
    }
};

int main() {
    // Demonstrate creating multiple employee objects
    Employee employee1(101, "Alice Smith", 60000.00, "Software Engineer");
    std::cout << "\nEmployee 1 Details:" << std::endl;
    employee1.displayDetails();

    // Create a copied object using the copy constructor
    Employee employee2 = employee1;
    std::cout << "\nEmployee 2 (copied from Employee 1) Details:" << std::endl;
    employee2.displayDetails();

    // Modify the copied object (note: the original remains unchanged for shallow copy)
    // For deep copy, you would need to handle pointer members differently if they existed.
    // Since there are no pointer members here, it's a shallow copy, but the primitive types are independent.
    // Let's just demonstrate the creation.

    return 0;
}