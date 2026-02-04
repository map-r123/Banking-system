#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;

class account
{
private:
    int accountNumber;
    string name;
    double balance;
public:
    account();
    account(int a, string n, double b);

    void deposit(double amount);
    void withdraw(double amount);
    double checkBalance();
};

#endif // ACCOUNT_H
