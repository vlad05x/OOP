#include <iostream>
#include <string>

struct BankAccount {
    double balance;
    std::string accountNumber;
    std::string ownerName;
};

void setBalance(BankAccount &account, double initialBalance) {
    //устанавливает значение balance структуры BankAccount равным значению initialBalance
    account.balance = initialBalance;
}

void setAccountNumber(BankAccount &account, const std::string &accNumber) {
    account.accountNumber = accNumber;
}

void setOwnerName(BankAccount &account, const std::string &owner) {
    //устанавливает значение поля ownerName объекта account равным значению owner
    account.ownerName = owner;
}

double getBalance(const BankAccount &account) {
    return account.balance;
}

std::string getAccountNumber(const BankAccount &account) {
    return account.accountNumber;
}

std::string getOwnerName(const BankAccount &account) {
    return account.ownerName;
}

void deposit(BankAccount &account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        std::cout << "Депозит на " << amount << " успішний.\n";
    } else {
        std::cout << "Помилка депозиту.\n";
    }
}

void withdraw(BankAccount &account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        std::cout << "Вивід суми на " << amount << " успішний.\n";
    } else {
         std::cout << "Помилка виводу.\n";
    }
}

void displayAccountInfo(const BankAccount &account) {
    std::cout << "Номер власника: " << account.ownerName << "\n";
    std::cout << "Номер рахунку: " << account.accountNumber << "\n";
    std::cout << "Баланс: " << account.balance << "\n";
}

int main() {

    // Створення об'єкта класу
    BankAccount acc;
    setBalance(acc, 5000.0);
    setAccountNumber(acc, "54321000");
    setOwnerName(acc, "Vlad");

    displayAccountInfo(acc);

    deposit(acc, 500.0);
    withdraw(acc, 200.0);

    displayAccountInfo(acc);

    return 0;
}
