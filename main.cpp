#include <iostream>
#include "account.h"
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int selected =0;
    string name;
    account newAccount;
    map<int,account> accountList;

    while (selected!=6)
    {
        cout << "\n***** Simple Banking System *****" << endl;
        cout << "\n1. Create Account" << endl;
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Check Balance\n";
        cout << "5. Login\n";
        cout << "6. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> selected;
        cin.ignore();

        switch (selected)
        {
        case 1:
            newAccount.createAccount();
            accountList[newAccount.getAccountNumber()] = newAccount;
            break;
        case 2:
            newAccount.withdraw();
            accountList[newAccount.getAccountNumber()]=newAccount;
            break;
        case 3:
            newAccount.deposit();
            accountList[newAccount.getAccountNumber()]=newAccount;
            break;
        case 4:
            cout << "\nYour Balance: " << fixed << setprecision(2) << newAccount.checkBalance() ;
            break;
        case 5:
            int acc,pin;
            cout << "\n***** Login *****" << endl;
            cout << "\nAccount No: ";
            cin >> acc;
            cout << "Pin: ";
            cin >> pin;

            if(accountList[acc].getPin()==pin)
            {
                newAccount=accountList[acc];
                cout << "Welcome " <<newAccount.getName() << endl;
            }
            else
            {
                cout << "Login Fail (Incorret Account Number or Pin)\n";
            }
            break;
        case 6:
            cout << "Thank you " << newAccount.getName() <<
                " for using our simple banking system";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }

    }

    return 0;
}


