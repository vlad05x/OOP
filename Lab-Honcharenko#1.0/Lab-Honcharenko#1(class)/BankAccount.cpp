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
        std::cout << "������� �� " << amount << " �������.\n";
    } else {
        std::cout << "������� ��������.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "���� ���� �� " << amount << " �������.\n";
    } else {
        std::cout << "������� ������.\n";
    }
}

void BankAccount::displayAccountInfo() const {
    std::cout << "����� ��������: " << ownerName << "\n";
    std::cout << "����� �������: " << accountNumber << "\n";
    std::cout << "������: " << balance << "\n";
}
