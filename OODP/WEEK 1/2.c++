#include <iostream>

using namespace std;

int main() {
    int temp;

    cout << "Enter the current temperature: ";
    cin >> temp;

    if (temp >= 80) {
        cout << "Suggested activity: swimming" << endl;
    } else if (temp >= 60) {
        cout << "Suggested activity: tennis" << endl;
    } else if (temp >= 40) {
        cout << "Suggested activity: golf" << endl;
    } else {
        cout << "Suggested activity: skiing" << endl;
    }

    return 0;
}