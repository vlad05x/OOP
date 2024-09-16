#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>

using namespace std;

class BankAccount {
private:
    double balance;
    string accountNumber;
    string ownerName;
public:
    // Конструкторы
    BankAccount();
    BankAccount(double initialBalance, const string &accNumber, const string &owner);
    BankAccount(const BankAccount &other);

    // Деструктор
    ~BankAccount();

    // Методы
    void setBalance(double initialBalance);
    double getBalance() const;
    void setAccountNumber(const string &accNumber);
    string getAccountNumber() const;
    void setOwnerName(const string &owner);
    string getOwnerName() const;
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccountInfo() const;
};

#endif
