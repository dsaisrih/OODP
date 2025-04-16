#include <iostream>
#include <string>
#include <vector>

class Product {
private:
    int productID;
    std::string productName;
    double price;
    int quantity;

public:
    // Constructor
    Product(int id, std::string name, double p, int qty)
        : productID(id), productName(name), price(p), quantity(qty) {}

    // Function that calculates the total cost based on quantity
    double calculateTotalPrice() const {
        return price * quantity;
    }

    // Function to get the product details
    void displayDetails() const {
        std::cout << "Product ID: " << productID << std::endl;
        std::cout << "Name: " << productName << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total Cost: $" << calculateTotalPrice() << std::endl;
    }

    // Getter for product ID (optional)
    int getProductID() const {
        return productID;
    }

    // Getter for product name (optional)
    std::string getProductName() const {
        return productName;
    }

    // Getter for price (optional)
    double getPrice() const {
        return price;
    }

    // Getter for quantity (optional)
    int getQuantity() const {
        return quantity;
    }
};

int main() {
    // Write the C++ code to show how multiple product objects can be used.
    Product product1(1, "Laptop", 1200.00, 2);
    Product product2(2, "Mouse", 25.00, 5);
    Product product3(3, "Keyboard", 75.00, 3);

    // Create an array (or vector) of Product objects
    std::vector<Product> shoppingCart;
    shoppingCart.push_back(product1);
    shoppingCart.push_back(product2);
    shoppingCart.push_back(product3);

    // Function to display the details of all products in the cart
    auto displayCartDetails = [&](const std::vector<Product>& cart) {
        std::cout << "\n--- Shopping Cart Details ---" << std::endl;
        for (const auto& product : cart) {
            product.displayDetails();
            std::cout << "-----------------------------" << std::endl;
        }
    };

    // Display the details of the products in the cart
    displayCartDetails(shoppingCart);

    return 0;
}