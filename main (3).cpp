#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& name, double initialBalance) 
        : accountHolder(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void displayBalance() const {
        std::cout << "Account Holder: " << accountHolder << "\n";
        std::cout << "Current Balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount account("John Doe", 1000.0);

    int choice;
    double amount;

    do {
        std::cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayBalance();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
