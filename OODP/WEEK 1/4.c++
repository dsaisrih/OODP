#include <iostream>
#include <string>

using namespace std;

// Function to parse a fraction string and return numerator and denominator
bool parseFraction(const string& fractionStr, int& num, int& den) {
    size_t slashPos = fractionStr.find('/');
    if (slashPos == string::npos || slashPos == 0 || slashPos == fractionStr.length() - 1) {
        return false; // Invalid fraction format
    }
    string numStr = fractionStr.substr(0, slashPos);
    string denStr = fractionStr.substr(slashPos + 1);
    try {
        num = stoi(numStr);
        den = stoi(denStr);
        if (den == 0) {
            return false; // Denominator cannot be zero
        }
        return true;
    } catch (const std::invalid_argument& e) {
        return false; // Not a valid integer
    } catch (const std::out_of_range& e) {
        return false; // Integer out of range
    }
}

int main() {
    string fraction1Str, fraction2Str;
    int num1, den1, num2, den2;

    cout << "Enter first fraction (a/b): ";
    cin >> fraction1Str;

    if (!parseFraction(fraction1Str, num1, den1)) {
        cout << "Invalid first fraction format." << endl;
        return 1;
    }

    cout << "Enter second fraction (c/d): ";
    cin >> fraction2Str;

    if (!parseFraction(fraction2Str, num2, den2)) {
        cout << "Invalid second fraction format." << endl;
        return 1;
    }

    int productNum = num1 * num2;
    int productDen = den1 * den2;

    cout << "Product = " << productNum << "/" << productDen << endl;

    return 0;
}