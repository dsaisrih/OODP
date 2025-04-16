#include <iostream>
using namespace std;

// Inline functions for basic arithmetic operations
inline int add(int a, int b) {
    return a + b;
}

inline int subtract(int a, int b) {
    return a - b;
}

inline int multiply(int a, int b) {
    return a * b;
}

inline double divide(int a, int b) {
    if (b != 0) {
        return static_cast<double>(a) / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0; // Return 0 if division by zero
    }
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Subtraction: " << subtract(num1, num2) << endl;
    cout << "Multiplication: " << multiply(num1, num2) << endl;
    cout << "Division: " << divide(num1, num2) << endl;

    return 0;
}