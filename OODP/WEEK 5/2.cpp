#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor for initializing account with account number and balance
    BankAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    // Overloaded constructor for creating an account with just an account number (default balance 0)
    BankAccount(string accNum) : accountNumber(accNum), balance(0.0) {}

    // Function to deposit money (overloaded for double)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to deposit money (overloaded for int)
    void deposit(int amount) {
        deposit(static_cast<double>(amount)); // Call the double version
    }

    // Function to withdraw money (overloaded for double)
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to withdraw money (overloaded for int)
    void withdraw(int amount) {
        withdraw(static_cast<double>(amount)); // Call the double version
    }

    // Operator overloading to compare two accounts based on balance
    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    // Function to display account details
    void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account1("12345", 1000.0);
    BankAccount account2("67890", 500.0);

    account1.deposit(200);
    account1.withdraw(150);
    account1.display();

    account2.deposit(300);
    account2.withdraw(100);
    account2.display();

    if (account1 > account2) {
        cout << "Account 1 has a higher balance." << endl;
    } else {
        cout << "Account 2 has a higher balance." << endl;
    }

    return 0;
}