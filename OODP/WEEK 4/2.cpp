#include <iostream>
#include <string>
#include <vector>

class Product {
private:
    std::string productID;
    std::string productName;
    double price;
    int quantity;

public:
    // Default constructor
    Product() : productID("DEFAULT_ID", "DEFAULT_NAME", 0.0, 0) {
        std::cout << "Default Product constructor called for " << productName << std::endl;
    }

    // Parameterized constructor
    Product(std::string id, std::string name, double p, int qty)
        : productID(id), productName(name), price(p), quantity(qty) {
        std::cout << "Parameterized Product constructor called for " << productName << std::endl;
    }

    // Function to calculate total price
    double calculateTotalPrice() const {
        return price * quantity;
    }

    // Function to display product details
    void displayProductInfo() const {
        std::cout << "Product ID: " << productID << std::endl;
        std::cout << "Name: " << productName << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
    }

    // Destructor
    ~Product() {
        std::cout << "Product " << productName << " is being removed." << std::endl;
    }
};

int main() {
    // Create an array of Product objects
    std::vector<Product> cart;
    cart.emplace_back("PROD-101", "Laptop", 1200.00, 1);
    cart.emplace_back("PROD-102", "Mouse", 25.00, 2);
    cart.emplace_back(); // Using default constructor

    std::cout << "\nProducts in the cart:" << std::endl;
    for (const auto& product : cart) {
        product.displayProductInfo();
        std::cout << "Total cost for this item: $" << product.calculateTotalPrice() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }

    return 0; // Destructors will be called when the cart vector goes out of scope
}