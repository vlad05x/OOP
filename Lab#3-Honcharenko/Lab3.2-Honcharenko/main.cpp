#include <iostream>
#include <string>
#include "BankAccount.h"
#include "BankAccount.cpp"
using namespace std;

class Person {
private:
    BankAccount bankAccount;
    string name;
public:
    Person(const string &personName, const string &accNumber, double initialBalance) {
        name = personName;
        bankAccount.setOwnerName(personName);
        bankAccount.setAccountNumber(accNumber);
        bankAccount.setBalance(initialBalance);
    }

    void displayPersonInfo() const {
        cout << "Ім'я: " << name << endl;
        bankAccount.displayAccountInfo();
    }
};

class Company {
private:
    BankAccount &bankAccount;
    string companyName;
public:
    Company(BankAccount &account, const string &name) : bankAccount(account) {
        companyName = name;
    }

    void displayCompanyInfo() const {
        cout << "Назва компанії: " << companyName << endl;
        bankAccount.displayAccountInfo();
    }
};

class VipPerson : public Person {
private:
    double bonusBalance;
public:
    VipPerson(const string &personName, const string &accNumber, double initialBalance, double bonus)
        : Person(personName, accNumber, initialBalance), bonusBalance(bonus) {}

    void displayVIPInfo() const {
        displayPersonInfo();
        cout << "Бонусний баланс: " << bonusBalance << endl;
    }
};

int main() {
    BankAccount companyAccount;
    companyAccount.setOwnerName("Owner Company");
    companyAccount.setAccountNumber("10987654321");
    companyAccount.setBalance(50000.0);

    Person person1("Vlad Honcharenko", "987654321", 10000.0);
    person1.displayPersonInfo();

    Company company1(companyAccount, "TechCorp");
    company1.displayCompanyInfo();

    VipPerson vipPerson1("Mark Zuck", "1122334455", 5000.0, 200.0);
    vipPerson1.displayVIPInfo();

    return 0;
}
