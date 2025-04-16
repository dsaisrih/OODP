#include <iostream>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;

public:
    // Constructor to initialize these attributes
    Car(std::string carBrand, std::string carModel, int carYear)
        : brand(carBrand), model(carModel), year(carYear) {}

    // Function to display car details
    void displayCarDetails() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }

    // Getter for brand (optional)
    std::string getBrand() const {
        return brand;
    }

    // Getter for model (optional)
    std::string getModel() const {
        return model;
    }

    // Getter for year (optional)
    int getYear() const {
        return year;
    }
};

int main() {
    // Demonstrate the Car class
    Car car1("Toyota", "Camry", 2022);
    Car car2("Honda", "Civic", 2023);
    Car car3("Ford", "Mustang", 2024);

    std::cout << "Car 1 Details:" << std::endl;
    car1.displayCarDetails();
    std::cout << "\nCar 2 Details:" << std::endl;
    car2.displayCarDetails();
    std::cout << "\nCar 3 Details:" << std::endl;
    car3.displayCarDetails();

    return 0;
}