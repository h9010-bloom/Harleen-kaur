#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>  
using namespace std;

bool getValidatedInt(const string &prompt, int &value) {
    cout << prompt;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number: ";
        } else {
            cin.ignore(1000, '\n');
            return true;
        }
    }
}

bool getValidatedDouble(const string &prompt, double &value) {
    cout << prompt;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a numeric value: ";
        } else {
            cin.ignore(1000, '\n');
            return true;
        }
    }
}

class Employee {
public:
    int id;
    string name;
    string department;
    string address;
    string phone;
    double basicSalary;
    int totalWorkingDays;
    int daysPresent;

    Employee(int empId, string empName, string dept, string empAddress, string empPhone, double salary) {
        id = empId;
        name = empName;
        department = dept;
        address = empAddress;
        phone = empPhone;
        basicSalary = salary;
        totalWorkingDays = 30;
        daysPresent = 0;
    }

    double calculateSalary() {
        // Full salary if 1 or 0 leaves, else reward one extra day for 2+ leaves
        if (daysPresent >= 29)
            return basicSalary;
        else
            return (basicSalary / totalWorkingDays) * (daysPresent + 1);
    }

    void markAttendanceByLeaves(int leaves) {
        if (leaves <= totalWorkingDays)
            daysPresent = totalWorkingDays - leaves;
        else
            cout << "Invalid number of leaves entered!\n";
    }

    void generatePaySlip() {
        cout << "\n----- Pay Slip -----\n";
        cout << fixed << setprecision(2); 
        cout << "Employee ID  : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Address      : " << address << endl;
        cout << "Phone        : " << phone << endl;
        cout << "Basic Salary : " << basicSalary << endl;
        cout << "Days Present : " << daysPresent << "/" << totalWorkingDays << endl;
        cout << "Net Salary   : " << calculateSalary() << endl;
        cout << "--------------------\n";
    }

    void saveToFile() {
        ofstream fout("employees.txt", ios::app);
        fout << id << "|" << name << "|" << department << "|"
             << address << "|" << phone << "|"
             << basicSalary << "|" << daysPresent << "\n";
        fout.close();
    }

    static bool employeeExists(int empId) {
        ifstream fin("employees.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string temp;
            getline(ss, temp, '|');
            if (!temp.empty() && stoi(temp) == empId) {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }

    static bool loadEmployeeFromFile(int empId, Employee &emp) {
        ifstream fin("employees.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string idStr, name, dept, addr, phone, salaryStr, daysStr;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, dept, '|');
            getline(ss, addr, '|');
            getline(ss, phone, '|');
            getline(ss, salaryStr, '|');
            getline(ss, daysStr, '|');

            if (!idStr.empty() && stoi(idStr) == empId) {
                emp = Employee(stoi(idStr), name, dept, addr, phone, stod(salaryStr));
                emp.daysPresent = stoi(daysStr);
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }

    static void showAllFromFile() {
        ifstream fin("employees.txt");
        string line;
        cout << "\n===== All Employees Information =====\n";
        if (!fin) {
            cout << "No employee records found.\n";
            return;
        }
        bool empty = true;
        while (getline(fin, line)) {
            if (!line.empty()) {
                cout << line << endl;
                empty = false;
            }
        }
        if (empty) cout << "No employee records found.\n";
        fin.close();
    }
};

int main() {
    cout << fixed << setprecision(2); 
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n===== Employee Payroll Management =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Generate Pay Slip\n";
        cout << "4. Show All Employees\n";
        cout << "5. Exit\n";

        getValidatedInt("Enter your choice: ", choice);

        if (choice == 1) {
            int id;
            string name, dept, address, phone;
            double salary;

            getValidatedInt("Enter Employee ID: ", id);

            if (Employee::employeeExists(id)) {
                cout << "Employee already exists!\n";
                continue;
            }

            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Phone: ";
            getline(cin, phone);
            getValidatedDouble("Enter Basic Salary: ", salary);

            Employee emp(id, name, dept, address, phone, salary);
            employees.push_back(emp);
            emp.saveToFile();

            cout << "Employee Added & Saved Successfully!\n";
        }

        else if (choice == 2) {
            int id, leaves;
            getValidatedInt("Enter Employee ID: ", id);
            bool found = false;

            for (auto &emp : employees) {
                if (emp.id == id) {
                    getValidatedInt("Enter number of leaves: ", leaves);
                    emp.markAttendanceByLeaves(leaves);
                    cout << "Attendance Updated!\n";

                    vector<string> lines;
                    ifstream fin("employees.txt");
                    string line;
                    while (getline(fin, line)) {
                        stringstream ss(line);
                        string idStr;
                        getline(ss, idStr, '|');
                        if (!idStr.empty() && stoi(idStr) == id) {
                            line = to_string(emp.id) + "|" + emp.name + "|" + emp.department + "|" +
                                   emp.address + "|" + emp.phone + "|" +
                                   to_string(emp.basicSalary) + "|" + to_string(emp.daysPresent);
                        }
                        lines.push_back(line);
                    }
                    fin.close();

                    ofstream fout("employees.txt", ios::trunc);
                    for (auto &l : lines) fout << l << "\n";
                    fout.close();

                    found = true;
                    break;
                }
            }

            if (!found) {
                Employee temp(0, "", "", "", "", 0);
                if (Employee::loadEmployeeFromFile(id, temp)) {
                    getValidatedInt("Enter number of leaves: ", leaves);
                    temp.markAttendanceByLeaves(leaves);
                    vector<string> lines;
                    ifstream fin("employees.txt");
                    string line;
                    while (getline(fin, line)) {
                        stringstream ss(line);
                        string idStr;
                        getline(ss, idStr, '|');
                        if (!idStr.empty() && stoi(idStr) == id) {
                            line = to_string(temp.id) + "|" + temp.name + "|" + temp.department + "|" +
                                   temp.address + "|" + temp.phone + "|" +
                                   to_string(temp.basicSalary) + "|" + to_string(temp.daysPresent);
                        }
                        lines.push_back(line);
                    }
                    fin.close();

                    ofstream fout("employees.txt", ios::trunc);
                    for (auto &l : lines) fout << l << "\n";
                    fout.close();

                    cout << "Attendance Updated & Saved in File!\n";
                } else {
                    cout << "Employee Not Found!\n";
                }
            }
        }

        else if (choice == 3) {
            int id;
            getValidatedInt("Enter Employee ID: ", id);
            bool found = false;

            for (auto &emp : employees) {
                if (emp.id == id) {
                    emp.generatePaySlip();
                    found = true;
                    break;
                }
            }

            if (!found) {
                Employee temp(0, "", "", "", "", 0);
                if (Employee::loadEmployeeFromFile(id, temp)) {
                    temp.generatePaySlip();
                } else {
                    cout << "Employee Not Found!\n";
                }
            }
        }

        else if (choice == 4) {
            Employee::showAllFromFile();
        }

        else if (choice == 5) {
            cout << "Exiting Payroll System...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}