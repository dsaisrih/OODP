#include <iostream>
#include <string>

class Book {
private:
    std::string bookID;
    std::string title;
    std::string author;
    double price;

public:
    // Default constructor
    Book() : bookID(""), title(""), author(""), price(0.0) {
        std::cout << "Default Book constructor called." << std::endl;
    }

    // Parameterized constructor
    Book(std::string id, std::string t, std::string a, double p)
        : bookID(id), title(t), author(a), price(p) {
        std::cout << "Parameterized Book constructor called for " << title << std::endl;
    }

    // Function to display book details
    void displayBookInfo() const {
        std::cout << "Book ID: " << bookID << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

int main() {
    // Demonstrate multiple book objects
    Book book1; // Using default constructor
    Book book2("ISBN-978-1234567890", "The Great Adventure", "Jane Doe", 19.99); // Using parameterized constructor

    std::cout << "\nBook 1 Details:" << std::endl;
    book1.displayBookInfo();

    std::cout << "\nBook 2 Details:" << std::endl;
    book2.displayBookInfo();

    return 0;
}