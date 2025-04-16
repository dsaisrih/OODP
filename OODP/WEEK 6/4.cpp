#include <iostream>
using namespace std;

// Base class Student
class Student {
protected:
    string name;
    int rollNumber;

public:
    void setDetails(string n, int r) {
        name = n;
        rollNumber = r;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

// Derived class Marks inheriting from Student
class Marks : public Student {
protected:
    int marks[3];

public:
    void setMarks(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    int calculateTotalMarks() {
        return marks[0] + marks[1] + marks[2];
    }

    void displayMarks() {
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
    }
};

// Derived class Sports inheriting from Student
class Sports : public Student {
protected:
    int sportsMarks;

public:
    void setSportsMarks(int sMarks) {
        sportsMarks = sMarks;
    }

    void displaySportsMarks() {
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};

// Final class Result inheriting from both Marks and Sports
class Result : public Marks, public Sports {
public:
    void calculateOverallPerformance() {
        int totalMarks = calculateTotalMarks() + sportsMarks;
        double averageMarks = totalMarks / 4.0; // 3 academic + 1 sports
        cout << "Total Marks: " << totalMarks << ", Average Marks: " << averageMarks << endl;
    }
};

int main() {
    Result student;
    student.setDetails("Alice", 202);
    student.setMarks(85, 90, 78);
    student.setSportsMarks(88);

    student.displayDetails();
    student.displayMarks();
    student.displaySportsMarks();
    student.calculateOverallPerformance();

    return 0;
}