#include <iostream>
using namespace std;

class BankAccount {

    float balance;

public:
    BankAccount() {
        balance = 0;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    int choice;
    float amount;

    while (true) {
        cout << "1. Deposit\n2. Withdraw\n3. Show Balance\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
        }
        else if (choice == 2) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
        }
        else if (choice == 3) {
            acc.showBalance();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
