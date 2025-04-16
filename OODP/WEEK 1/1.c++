#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to count the number of digits in an integer
int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    long long num = abs(static_cast<long long>(n)); // Handle negative numbers
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int num1, num2;

    cout << "Enter the first integer: ";
    cin >> num1;

    cout << "Enter the second integer: ";
    cin >> num2;

    int product = num1 * num2;
    int digitCount = countDigits(product);

    cout << "Product - " << product << endl;
    cout << "Count of digits - " << digitCount << endl;

    return 0;
}