#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>
using namespace std;

class Account {
    int accNumber;
    char name[50];
    char type;
    double balance;
    char mobile[15];
    char address[100];
public:
    // Create a new account
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);

        cout << "Enter Account Type (C/S): ";
        cin >> type;
        type = toupper(type);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Mobile Number: ";
        cin.getline(mobile, 15);

        cout << "Enter Address: ";
        cin.getline(address, 100);

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        cout << "\n✅ Account Created Successfully!\n";
    }

    // Display account details
    void showAccount() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number : " << accNumber << endl;
        cout << "Account Holder : " << name << endl;
        cout << "Account Type   : " << type << endl;
        cout << "Mobile Number  : " << mobile << endl;
        cout << "Address        : " << address << endl;
        cout << "Balance        : $" << fixed << setprecision(2) << balance << endl;
    }

    // Modify account details
    void modify() {
        cout << "Modify Account Holder Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(name, 50);

        cout << "Modify Account Type (C/S): ";
        cin >> type;
        type = toupper(type);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Modify Mobile Number: ";
        cin.getline(mobile, 15);

        cout << "Modify Address: ";
        cin.getline(address, 100);

        cout << "Modify Balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount!\n";
    }

    void withdraw(double amount) {
        if (amount <= 0)
            cout << "Invalid withdrawal amount!\n";
        else if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance!\n";
    }

    void report() const {
        cout << left << setw(10) << accNumber
             << setw(20) << name
             << setw(8)  << type
             << setw(15) << mobile
             << setw(15) << fixed << setprecision(2) << balance
             << setw(20) << address << endl;
    }

    int getAccNumber() const { return accNumber; }
};

// Function Prototypes
void writeAccount();
void displayAccount(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAll();
void depositWithdraw(int, int);

int main() {
    int choice;
    int accNo;

    do {
        cout << "\n=========== BANK MANAGEMENT SYSTEM ===========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. All Account Holder List\n";
        cout << "6. Close An Account\n";
        cout << "7. Modify An Account\n";
        cout << "8. Exit\n";
        cout << "=============================================\n";
        cout << "Select Your Option (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeAccount();
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                depositWithdraw(accNo, 1);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                depositWithdraw(accNo, 2);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                displayAccount(accNo);
                break;
            case 5:
                displayAll();
                break;
            case 6:
                cout << "Enter Account Number: ";
                cin >> accNo;
                deleteAccount(accNo);
                break;
            case 7:
                cout << "Enter Account Number: ";
                cin >> accNo;
                modifyAccount(accNo);
                break;
            case 8:
                cout << "\nThank you for using the Bank Management System!\n";
                break;
            default:
                cout << "Invalid Option! Try again.\n";
        }
        cin.ignore();
        cin.get();
    } while (choice != 8);

    return 0;
}

// Function Definitions

void writeAccount() {
    Account acc;
    ofstream outFile("account.dat", ios::binary | ios::app);
    acc.createAccount();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(Account));
    outFile.close();
}

void displayAccount(int accNo) {
    Account acc;
    bool found = false;
    ifstream inFile("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!\n";
        return;
    }

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccNumber() == accNo) {
            acc.showAccount();
            found = true;
        }
    }
    inFile.close();
    if (!found)
        cout << "Account Not Found.\n";
}

void modifyAccount(int accNo) {
    Account acc;
    bool found = false;
    fstream file("account.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File could not be opened!\n";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccNumber() == accNo) {
            acc.showAccount();
            cout << "\nEnter New Details:\n";
            acc.modify();

            streampos pos = file.tellg();
            file.seekp(pos - static_cast<streamoff>(sizeof(Account)));
            file.write(reinterpret_cast<char*>(&acc), sizeof(Account));

            cout << "\nAccount Updated Successfully.\n";
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Account Not Found.\n";
}

void deleteAccount(int accNo) {
    Account acc;
    ifstream inFile("account.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    if (!inFile) {
        cout << "File could not be opened!\n";
        return;
    }

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccNumber() != accNo)
            outFile.write(reinterpret_cast<char*>(&acc), sizeof(Account));
    }

    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("temp.dat", "account.dat");
    cout << "Account Deleted Successfully.\n";
}

void displayAll() {
    Account acc;
    ifstream inFile("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!\n";
        return;
    }

    cout << "\n\n*** ACCOUNT HOLDER LIST ***\n";
    cout << left << setw(10) << "Acc No"
         << setw(20) << "Name"
         << setw(8) << "Type"
         << setw(15) << "Mobile"
         << setw(15) << "Balance"
         << setw(20) << "Address" << endl;
    cout << "---------------------------------------------------------------\n";

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        acc.report();
    }
    inFile.close();
}

void depositWithdraw(int accNo, int option) {
    Account acc;
    fstream file("account.dat", ios::binary | ios::in | ios::out);
    bool found = false;
    double amount;

    if (!file) {
        cout << "File could not be opened!\n";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccNumber() == accNo) {
            acc.showAccount();
            if (option == 1) {
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                acc.deposit(amount);
            } else {
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                acc.withdraw(amount);
            }

            streampos pos = file.tellg();
            file.seekp(pos - static_cast<streamoff>(sizeof(Account)));
            file.write(reinterpret_cast<char*>(&acc), sizeof(Account));

            cout << "Transaction Completed Successfully.\n";
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Account Not Found.\n";
}