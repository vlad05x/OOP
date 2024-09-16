#include "BankAccount.h"

BankAccount::BankAccount() : balance(0.0), accountNumber(""), ownerName("") {
    cout << "Конструктор за замовчуванням викликано\n";
}

BankAccount::BankAccount(double initialBalance, const string &accNumber, const string &owner)
    : balance(initialBalance), accountNumber(accNumber), ownerName(owner) {
    cout << "Конструктор з параметрами викликано\n";
}

BankAccount::BankAccount(const BankAccount &other)
    : balance(other.balance), accountNumber(other.accountNumber), ownerName(other.ownerName) {
    cout << "Копіюючий конструктор викликано\n";
}

BankAccount::~BankAccount() {
    cout << "Деструктор викликано. Об'єкт знищено\n";
}

// Методи класу BankAccount
void BankAccount::setBalance(double initialBalance) {
    balance = initialBalance;
}

void BankAccount::setAccountNumber(const string &accNumber) {
    accountNumber = accNumber;
}

void BankAccount::setOwnerName(const string &owner) {
    ownerName = owner;
}

double BankAccount::getBalance() const {
    return balance;
}

string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Депозит на " << amount << " успішний.\n";
    } else {
        cout << "Помилка депозиту.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Вивід суми на " << amount << " успішний.\n";
    } else {
        cout << "Помилка виводу.\n";
    }
}

void BankAccount::displayAccountInfo() const {
    cout << "Номер власника: " << ownerName << "\n";
    cout << "Номер рахунку: " << accountNumber << "\n";
    cout << "Баланс: " << balance << "\n";
}
