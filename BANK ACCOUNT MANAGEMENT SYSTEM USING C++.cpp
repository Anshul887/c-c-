#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    static int accountCounter;
    int accountNumber;
    string name;
    string contact;
    double balance;

public:
    Account(string name, string contact, double initialBalance) {
        this->accountNumber = ++accountCounter;
        this->name = name;
        this->contact = contact;
        this->balance = initialBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void showDetails() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Balance: ₹" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "₹" << amount << " deposited successfully.\n";
        cout << "Updated Balance: ₹" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
            cout << "Updated Balance: ₹" << balance << endl;
        }
    }
};

// Initialize static member
int Account::accountCounter = 1000; // Starting account number

// Bank to store multiple accounts
class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        string name, contact;
        double initialBalance;

        cout << "\nEnter Full Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Contact Info: ";
        getline(cin, contact);

        cout << "Enter Initial Balance: ₹";
        cin >> initialBalance;

        Account newAcc(name, contact, initialBalance);
        accounts.push_back(newAcc);
        cout << "Account created successfully! Account No: " << newAcc.getAccountNumber() << endl;
    }

    Account* searchAccount(int accNo) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                return &acc;
            }
        }
        return nullptr;
    }

    void showAccountDetails() {
        int accNo;
        cout << "Enter Account Number to search: ";
        cin >> accNo;

        Account* acc = searchAccount(accNo);
        if (acc) {
            acc->showDetails();
        } else {
            cout << "Account not found.\n";
        }
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* acc = searchAccount(accNo);
        if (acc) {
            cout << "Enter amount to deposit: ₹";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* acc = searchAccount(accNo);
        if (acc) {
            cout << "Enter amount to withdraw: ₹";
            cin >> amount;
            acc->withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n====== Bank Account Management System ======\n";
        cout << "1. Create New Account\n";
        cout << "2. Show Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.showAccountDetails();
            break;
        case 3:
            bank.depositMoney();
            break;
        case 4:
            bank.withdrawMoney();
            break;
        case 5:
            cout << "Thank you for using the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
