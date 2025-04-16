#include <iostream>

using namespace std;

int main() {
    int num;

    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (num % 2 == 0 && num % 3 == 0) {
            cout << "EXIT" << endl;
            break;
        } else {
            long long cube = static_cast<long long>(num) * num * num;
            cout << "Cube of " << num << " is: " << cube << endl;
        }
    }

    return 0;
}