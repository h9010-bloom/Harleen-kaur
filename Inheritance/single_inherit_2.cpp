#include<iostream>
#include<string>
using namespace std;
class Employee
{
    string name;
    int ID;
    int salary;

    public:
    void setEdata(string n,int id,int s)
    {
        name=n;
        ID=id;
        salary=s;
    }
    void getEdata()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"SALARY: "<<salary<<endl;
    }
};
class Manager:public Employee
{
    string department;
    
    public:
    void setMdata(string n,int id,int s,string d)
    {
        Employee::setEdata(n,id,s);
        department=d;
    }
    void getMdata()
    {
        Employee::getEdata();
        cout<<"DEPARTMENT: "<<department<<endl;
    }
};
int main()
{
    Manager M;
    M.setMdata("Anirudh",1001,70000,"finanace");
    M.getMdata();

    return 0;
}