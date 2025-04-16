#include <iostream>
#include <cmath>
using namespace std;

// Base class Shape
class Shape {
public:
    virtual void getData() = 0; // Pure virtual function
    virtual double calculateArea() = 0; // Pure virtual function
    virtual void printData() = 0; // Pure virtual function
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    void getData() override {
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
    }

    double calculateArea() override {
        return length * width;
    }

    void printData() override {
        cout << "Rectangle Area: " << calculateArea() << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    void getData() override {
        cout << "Enter radius of the circle: ";
        cin >> radius;
    }

    double calculateArea() override {
        return M_PI * radius * radius; // Using M_PI for π
    }

    void printData() override {
        cout << "Circle Area: " << calculateArea() << endl;
    }
};

int main() {
    Rectangle rect;
    Circle circ;

    rect.getData();
    rect.printData();

    circ.getData();
    circ.printData();

    return 0;
}