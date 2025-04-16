#include <iostream>
#include <vector>
using namespace std;

class Ticket {
private:
    string movieName;
    int seatNumber;
    bool booked;

public:
    Ticket(string name, int seat) : movieName(name), seatNumber(seat), booked(false) {}

    void book() {
        if (!booked) {
            booked = true;
            cout << "Ticket booked for " << movieName << " at seat " << seatNumber << endl;
        } else {
            cout << "Ticket already booked!" << endl;
        }
    }

    void cancel() {
        if (booked) {
            booked = false;
            cout << "Ticket cancelled for " << movieName << " at seat " << seatNumber << endl;
        } else {
            cout << "No booking to cancel!" << endl;
        }
    }

    void display() {
        cout << "Movie: " << movieName << ", Seat: " << seatNumber << ", Status: " << (booked ? "Booked" : "Available") << endl;
    }
};

int main() {
    vector<Ticket> tickets;
    tickets.emplace_back("Movie A", 1);
    tickets.emplace_back("Movie B", 2);
    tickets.emplace_back("Movie C", 3);

    // Book tickets
    tickets[0].book();
    tickets[1].book();
    tickets[0].book(); // Attempt to book again

    // Display ticket status
    for ( auto& ticket : tickets) {
        ticket.display();
    }

    // Cancel a ticket
    tickets[0].cancel();
    tickets[0].cancel(); // Attempt to cancel again

    // Display ticket status after cancellation
    for (auto& ticket : tickets) {
        ticket.display();
    }

    return 0;
}