#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;   // hidden: only the class's own functions can change it

public:
    BankAccount(double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

BankAccount::BankAccount(double initialBalance) : balance(initialBalance) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Withdrawal of " << amount << " refused\n";
        return false;
    }
    balance -= amount;
    return true;
}

double BankAccount::getBalance() const {
    return balance;
}

int main() {
    BankAccount b1(100);
    

    b1.deposit(50);
    cout << "After deposit: " << b1.getBalance() << "\n";    // 150

    b1.withdraw(30);
    cout << "After withdraw: " << b1.getBalance() << "\n";   // 120

    b1.withdraw(500);                                          // refused
    cout << "Final balance: " << b1.getBalance() << "\n";    // 120

    // b1.balance = 1000000;   // compile ERROR: balance is private
    return 0;
}
