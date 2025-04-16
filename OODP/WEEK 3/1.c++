#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(std::string number, std::string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " successfully. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 0) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " successfully. New balance: $" << balance << std::endl;
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount." << std::endl;
        } else {
            std::cout << "Insufficient balance. Withdrawal not allowed." << std::endl;
        }
    }

    // Display account details function
    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Getter for account number (optional)
    std::string getAccountNumber() const {
        return accountNumber;
    }

    // Getter for account holder name (optional)
    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    // Getter for balance (optional)
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Demonstrate how an object of BankAccount can be created and used
    BankAccount account1("1234567890", "John Doe", 1000.50);
    std::cout << "Account 1 Details:" << std::endl;
    account1.display();

    account1.deposit(500.00);
    account1.withdraw(200.00);
    account1.withdraw(2000.00); // Attempt to overdraft

    std::cout << "\nAccount 1 Details after transactions:" << std::endl;
    account1.display();

    return 0;
}