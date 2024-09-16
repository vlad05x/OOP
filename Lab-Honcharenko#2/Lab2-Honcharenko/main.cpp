#include "BankAccount.h"
#include <iostream>

int main() {
    system("chcp 1251 & cls");

    BankAccount account1;
    account1.setOwnerName("Vlad");
    account1.setAccountNumber("555444333222111");
    account1.setBalance(5000);
    account1.displayAccountInfo();

    BankAccount account2(3000, "111222333444555", "Alex");
    account2.displayAccountInfo();

    BankAccount account3(account1);
    account3.displayAccountInfo();

    return 0;
}
