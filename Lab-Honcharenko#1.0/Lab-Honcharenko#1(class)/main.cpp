#include "BankAccount.h"
#include <iostream>

int main() {
    system("chcp 1251 & cls");
    // ��������� ��'���� �����
    BankAccount account;
    // ������������ ������������ ��'����
    account.setOwnerName("Vlad");
    account.setAccountNumber("555444333222111");
    account.setBalance(5000);

    account.displayAccountInfo();

    account.deposit(1000);
    account.displayAccountInfo();

    account.withdraw(500.0);
    account.displayAccountInfo();

    return 0;
}
