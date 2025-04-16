#include <iostream>
class Library {
private:
    static int totalBooks;
    int books;
public:
    Library() : books(0) {}
    int addBook(int number_of_books) {
        books += number_of_books; 
        totalBooks += number_of_books; 
        return totalBooks; 
    }
    static int getTotalBooks() {
        return totalBooks; 
    }
};
int Library::totalBooks = 0;
int main() {
    Library library1;
    int booksToAdd1;

    std::cout << "Enter the number of books to add to library1: ";
    std::cin >> booksToAdd1; 

    int newTotal1 = library1.addBook(booksToAdd1); 
    std::cout << "Total books after adding to library1: " << newTotal1 << std::endl;

    Library library2;
    int booksToAdd2;

    std::cout << "Enter the number of books to add to library2: ";
    std::cin >> booksToAdd2; 
    
    int newTotal2 = library2.addBook(booksToAdd2); 
    std::cout << "Total books after adding to library2: " << newTotal2 << std::endl;
    int total = Library::getTotalBooks();
    std::cout << "Total number of books: " << total << std::endl;

    return 0;
}