#include <iostream>
using namespace std;

// Base class Student
class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(string n, int r) : name(n), rollNumber(r) {}

    void displayStudent() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

// Base class SportsPlayer
class SportsPlayer {
protected:
    string sportName;
    int ranking;

public:
    SportsPlayer(string sport, int rank) : sportName(sport), ranking(rank) {}

    void displaySportsPlayer() {
        cout << "Sport: " << sportName << ", Ranking: " << ranking << endl;
    }
};

// Derived class SportStudent
class SportStudent : public Student, public SportsPlayer {
public:
    SportStudent(string n, int r, string sport, int rank)
        : Student(n, r), SportsPlayer(sport, rank) {}

    void displayDetails() {
        displayStudent();
        displaySportsPlayer();
    }
};

int main() {
    SportStudent student("John Doe", 101, "Basketball", 5);
    student.displayDetails(); // Display details of the SportStudent
    return 0;
}