
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;

class BankAccount {
    private:
        double balance;
        string accountNumber;
        string ownerName;
    public:
        BankAccount();
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
