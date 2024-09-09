#include <iostream>
#include <string>

struct BankAccount {
    double balance;
    std::string accountNumber;
    std::string ownerName;
};

void setBalance(BankAccount &account, double initialBalance) {
    //������������� �������� balance ��������� BankAccount ������ �������� initialBalance
    account.balance = initialBalance;
}

void setAccountNumber(BankAccount &account, const std::string &accNumber) {
    account.accountNumber = accNumber;
}

void setOwnerName(BankAccount &account, const std::string &owner) {
    //������������� �������� ���� ownerName ������� account ������ �������� owner
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
        std::cout << "������� �� " << amount << " �������.\n";
    } else {
        std::cout << "������� ��������.\n";
    }
}

void withdraw(BankAccount &account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        std::cout << "���� ���� �� " << amount << " �������.\n";
    } else {
         std::cout << "������� ������.\n";
    }
}

void displayAccountInfo(const BankAccount &account) {
    std::cout << "����� ��������: " << account.ownerName << "\n";
    std::cout << "����� �������: " << account.accountNumber << "\n";
    std::cout << "������: " << account.balance << "\n";
}

int main() {
    system("chcp 1251 & cls");
    // ��������� ��'���� �����
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
