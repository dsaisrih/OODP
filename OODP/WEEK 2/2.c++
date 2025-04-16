#include <iostream>
#include <limits>

using namespace std;

class StudentMarks {
private:
    int* marks;
    int numStudents;

public:
    StudentMarks(int n) : numStudents(n) {
        marks = new int[n];
    }

    ~StudentMarks() {
        delete[] marks;
    }

    void enterMarks() {
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter marks for student " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    double calculateAverage() {
        int sum = 0;
        for (int i = 0; i < numStudents; i++) {
            sum += marks[i];
        }
        return static_cast<double>(sum) / numStudents;
    }

    void findHighestLowest() {
        int highest = numeric_limits<int>::min();
        int lowest = numeric_limits<int>::max();
        for (int i = 0; i < numStudents; i++) {
            if (marks[i] > highest) highest = marks[i];
            if (marks[i] < lowest) lowest = marks[i];
        }
        cout << "Highest marks: " << highest << endl;
        cout << "Lowest marks: " << lowest << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    StudentMarks sm(n);
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a. Enter marks of N students\n";
        cout << "b. Calculate average marks\n";
        cout << "c. Find highest and lowest marks\n";
         cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                sm.enterMarks();
                break;
            case 'b':
                cout << "Average marks: " << sm.calculateAverage() << endl;
                break;
            case 'c':
                sm.findHighestLowest();
                break;
            case 'd':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 'd');

    return 0;
}