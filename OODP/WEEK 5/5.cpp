#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double pricePerDay;
    bool isAvailable;

public:
    // Default constructor
    Car() : model("Unknown"), pricePerDay(0.0), isAvailable(true) {}

    // Parameterized constructor
    Car(string m, double price, bool available) : model(m), pricePerDay(price), isAvailable(available) {}

    // Copy constructor
    Car(const Car& other) : model(other.model), pricePerDay(other.pricePerDay), isAvailable(other.isAvailable) {}

    // Function to book a car by specifying the number of days
    double book(int days) {
        if (isAvailable) {
            isAvailable = false;
            return days * pricePerDay;
        } else {
            cout << "Car is not available for booking." << endl;
            return 0.0;
        }
    }

    // Function to book a car with a discount
    double book(int days, double discount) {
        double total = book(days);
        return total - (total * discount / 100);
    }

    // Function to book a car with extra insurance
    double book(int days, double insuranceAmount) {
        double total = book(days);
        return total + insuranceAmount;
    }

    // Operator overloading to combine rental prices of two cars
    double operator+(const Car& other) {
        return pricePerDay + other.pricePerDay;
    }

    // Operator overloading to compare car prices
    bool operator>(const Car& other) {
        return pricePerDay > other.pricePerDay;
    }

    void display() {
        cout << "Car Model: " << model << ", Price per Day: " << pricePerDay << ", Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
};

int main() {
    Car car1("Toyota", 50.0, true);
    Car car2("Honda", 60.0, true);

    car1.display();
    car2.display();

    double totalCost1 = car1.book(3);
    cout << "Total cost for car1: " << totalCost1 << endl;

    double totalCost2 = car2.book(2, 10); // 10% discount
    cout << "Total cost for car2 with discount: " << totalCost2 << endl;

    double combinedPrice = car1 + car2;
    cout << "Combined rental price of car1 and car2: " << combinedPrice << endl;

    if (car1 > car2) {
        cout << "Car1 is more expensive to rent per day." << endl;
    } else {
        cout << "Car2 is more expensive to rent per day." << endl;
    }

    return 0;
}