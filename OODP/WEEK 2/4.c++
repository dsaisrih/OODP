#include <iostream>
#include <typeinfo>

int main() {
    float x = 2.5;
    int y = 3;
    auto result = x / y;

    std::cout << "Type of result: " << typeid(result).name() << std::endl; // Displays the type of result
    std::cout << "Value of result: " << result << std::endl; // Displays the value of result

    return 0;
}