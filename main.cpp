#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    int accountNo, selected, deposit, withdraw;
    string name;
    double balance;


    // This is to get information on the account
    // can be turned into a function
    cout << "***** Simple Banking System *****" << endl;
    cout << "\nAccount No:";
    cin >> accountNo;
    cout << "Account Holder Name: ";
    cin >> name;
    cout << "Current Balance: ";
    cin >> balance;

    account newAccount(accountNo,name,balance);

    do
    {
        cout << "\n***** Simple Banking System *****" << endl;
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> selected;

        switch (selected)
        {
        case 1:
            cout << "\nDeposit Amount: ";
            cin >> deposit;
            newAccount.deposit(deposit);
            cout << "Deposit Successful\n";
            break;
        case 2:
            cout << "\nWithdraw Amount: ";
            cin >> withdraw;
            newAccount.withdraw(withdraw);
            cout << "Deposit Successful\n";
            break;
        case 3:
            cout << "\nYour Balance: " << newAccount.checkBalance();
            break;
        defualt:
            cout << "Invalid choice\n";
            break;
        }

    }while (selected!=4);

    cout << "Thank you " << name << " for using our simple banking system";

    return 0;
}
