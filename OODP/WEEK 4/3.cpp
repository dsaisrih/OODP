#include <iostream>
#include <string>

class MovieTicket {
private:
    std::string movieName;
    int seatNumber;
    double price;
    bool isBooked;

public:
    // Constructor to initialize ticket details
    MovieTicket(std::string name, int seat, double p)
        : movieName(name), seatNumber(seat), price(p), isBooked(false) {
        std::cout << "Ticket created for " << movieName << ", Seat " << seat << std::endl;
    }

    // Function to book the ticket
    bool bookTicket() {
        if (!isBooked) {
            isBooked = true;
            std::cout << "Ticket for " << movieName << ", Seat " << seat << " booked successfully." << std::endl;
            return true;
        } else {
            std::cout << "Ticket for " << movieName << ", Seat " << seat << " is already booked." << std::endl;
            return false;
        }
    }

    // Function to cancel the ticket
    bool cancelTicket() {
        if (isBooked) {
            isBooked = false;
            std::cout << "Ticket for " << movieName << ", Seat " << seat << " cancelled." << std::endl;
            return true;
        } else {
            std::cout << "Ticket for " << movieName << ", Seat " << seat << " is not booked, cannot cancel." << std::endl;
            return false;
        }
    }

    // Function to display ticket details
    void displayTicketDetails() const {
        std::cout << "Movie: " << movieName << std::endl;
        std::cout << "Seat Number: " << seatNumber << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Booked: " << (isBooked ? "Yes" : "No") << std::endl;
    }

    // Destructor
    ~MovieTicket() {
        std::cout << "Ticket for " << movieName << ", Seat " << seat << " is being deleted." << std::endl;
    }
};

int main() {
    // Demonstrate ticket booking and cancellation with multiple objects
    MovieTicket ticket1("Avengers: Endgame", 15, 12.50);
    MovieTicket ticket2("Spider-Man: No Way Home", 22, 14.00);

    std::cout << "\nTicket 1 Details:" << std::endl;
    ticket1.displayTicketDetails();
    ticket1.bookTicket();
    ticket1.displayTicketDetails();
    ticket1.bookTicket(); // Try to book again
    ticket1.cancelTicket();
    ticket1.displayTicketDetails();
    ticket1.cancelTicket(); // Try to cancel again

    std::cout << "\nTicket 2 Details:" << std::endl;
    ticket2.displayTicketDetails();
    ticket2.bookTicket();
    ticket2.displayTicketDetails();

    return 0; // Destructors will be called when the objects go out of scope
}