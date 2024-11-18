#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : balance(0.0), accountNumber(""), ownerName("") {}

void BankAccount::setBalance(double initialBalance) {
    balance = initialBalance;
}

void BankAccount::setAccountNumber(const std::string &accNumber) {
    accountNumber = accNumber;
}

void BankAccount::setOwnerName(const std::string &owner) {
    ownerName = owner;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Депозит на " << amount << " успішний.\n";
    } else {
        std::cout << "Помилка депозиту.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Вивід суми на " << amount << " успішний.\n";
    } else {
        std::cout << "Помилка виводу.\n";
    }
}

void BankAccount::displayAccountInfo() const {
    std::cout << "Номер власника: " << ownerName << "\n";
    std::cout << "Номер рахунку: " << accountNumber << "\n";
    std::cout << "Баланс: " << balance << "\n";
}
