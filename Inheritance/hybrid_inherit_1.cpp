#include<iostream>
#include<string>
using namespace std;
class Employee
{
    public:
    string name;
    int employee_ID;

    void employeedata()
    {
        cout<<"enter the name of employee: ";
        cin>>name;
        cout<<"enter the ID of "<<name<<" : ";
        cin>>employee_ID;
    }
};
class Department:public virtual Employee
{
    public:
    string depart_name;

    void departdata()
    {
        cout<<"enter the department of "<<name<<" : ";
        cin>>depart_name;
    }
};
class Salary:public virtual Employee
{
    public:
    int basic_salary;
    int HRA;
    int DA;

    void salarydata()
    {
        cout<<"enter the basic salary of "<<name<<" : ";
        cin>>basic_salary;
        cout<<"enter the HRA of "<<name<<" : ";
        cin>>HRA;
        cout<<"enter the DA of "<<name<<" : ";
        cin>>DA;
    }
};
class Totalsalary:public Salary, public Department
{
    public:
    int total_salary;

    void calculate_totalsalary()
    {
        total_salary=basic_salary + HRA + DA;

        cout<<"------Employee Salary Details------"<<endl;
        cout<<"NAME: "<<name<<endl;
        cout<<"EMPLOYEE ID: "<<employee_ID<<endl;
        cout<<"DEPARTMENT: "<<depart_name<<endl;
        cout<<"TOTAL SALARY: "<<total_salary<<endl;
    }
};
int main()
{
    Totalsalary t;
    t.employeedata();
    t.departdata();
    t.salarydata();
    t.calculate_totalsalary();
}