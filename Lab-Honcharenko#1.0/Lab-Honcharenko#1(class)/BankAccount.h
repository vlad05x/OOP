#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
    private:
        double balance;
        std::string accountNumber;
        std::string ownerName;
    public:
        BankAccount();
        void setBalance(double initialBalance);
        double getBalance() const;
        void setAccountNumber(const std::string &accNumber);
        std::string getAccountNumber() const;
        void setOwnerName(const std::string &owner);
        std::string getOwnerName() const;
        void deposit(double amount);
        void withdraw(double amount);
        void displayAccountInfo() const;
};

#endif
