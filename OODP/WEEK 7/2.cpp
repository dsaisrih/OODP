#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    double price;

public:
    Book(string name, double p) : bookName(name), price(p) {}

    // Declare Library as a friend class
    friend class Library;
};

class Library {
public:
    void book_price(Book& b) {
        cout << "Book Name: " << b.bookName << ", Price: " << b.price << endl;
    }
};

int main() {
    Book book("C++ Programming", 29.99);
    Library library;
    library.book_price(book); // Accessing private members of Book
    return 0;
}