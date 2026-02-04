#include "account.h"

account::account() {}
account::account(int a, string n, double b)
{
    accountNumber=a;
    name=n;
    balance=b;
}

void account::deposit(double amount)
{
    balance = balance + amount;
}

void account::withdraw(double amount)
{
    balance = balance - amount;
}

double account::checkBalance()
{
    return balance;
}
