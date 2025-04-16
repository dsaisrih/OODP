#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Student {
private:
    int studentID;
    std::string name;
    std::vector<double> marks; // Array to store marks for 5 subjects

public:
    // Constructor
    Student(int id, std::string studentName, const std::vector<double>& studentMarks)
        : studentID(id), name(studentName), marks(studentMarks) {
        if (marks.size() != 5) {
            std::cerr << "Warning: Incorrect number of marks provided for student " << name << ". Expected 5." << std::endl;
            marks.resize(5, 0.0); // Resize to 5 and initialize with 0.0
        }
    }

    // Function to calculate the student's average marks
    double calculateAverage() const {
        if (marks.empty()) {
            return 0.0;
        }
        double sum = std::accumulate(marks.begin(), marks.end(), 0.0);
        return sum / marks.size();
    }

    // Function to display the student's details along with their average marks
    void displayDetails() const {
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: ";
        for (double mark : marks) {
            std::cout << mark << " ";
        }
        std::cout << std::endl;
        std::cout << "Average Marks: " << calculateAverage() << std::endl;
    }
};

int main() {
    // Demonstrate how multiple student objects can be created and their details are displayed
    std::vector<double> marks1 = {85.5, 90.0, 78.0, 92.5, 88.0};
    Student student1(101, "Alice Smith", marks1);

    std::vector<double> marks2 = {76.0, 82.5, 95.0, 79.0, 88.5};
    Student student2(102, "Bob Johnson", marks2);

    std::cout << "Student 1 Details:" << std::endl;
    student1.displayDetails();
    std::cout << "\nStudent 2 Details:" << std::endl;
    student2.displayDetails();

    // You can create more student objects as needed
    return 0;
}