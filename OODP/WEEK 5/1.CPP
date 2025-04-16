#include <iostream>
using namespace std;

class Example {
    int x;
public:
    // Constructor that takes an integer argument
    Example(int a) { 
        x = a; 
    }
    
    // Method to display the value of x
    void show() { 
        cout << "Value: " << x << endl; 
    }
};

int main() {
    // Create an object of Example with an integer argument
    Example obj(10); // Provide an integer argument to the constructor
    obj.show(); // This will now work correctly
    return 0;
}