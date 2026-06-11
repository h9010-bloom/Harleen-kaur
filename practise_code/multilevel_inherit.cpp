#include <iostream>
#include <string>
using namespace std;
class employee
{
    string name;
    int id;

    public:
    void setemployee()
    {
        cout<<"enter name of employee: ";
        cin >>name;

        cout<<"enter id  number of employee: ";
        cin>>id;
    }
    void getemployee()
    {
        cout<<"EMPLOYEE NAME: "<<name<<endl;
        cout<<"EMPLOYEE ID NUMBER: "<<id<<endl;
    }
};
class manager:public employee
{
    string department;

    public:
    void setmanager()
    {
        setemployee();
        cout <<"enter department of employee: ";
        cin>>department;
    }
    void getmanager()
    {
        getemployee();
        cout<<"EMPLOYEE DEPARTMENT: "<<department<<endl;
    }
};
class general_manager:public manager
{
    int bonus;

    public:
    void setgeneral_manager()
    {
        setmanager();
        cout<<"enter bonus of employee: ";
        cin>>bonus;
    }
    void getgeneral_manager()
    {
        getmanager();
        cout<<"EMPLOYEE BONUS: "<<bonus<<endl;
    }
};
int main()
{
    general_manager gm;
    cout<<"Here the input details of employee--------"<<endl;
    gm.setgeneral_manager();

    cout<<"Here is the EMPLOYEE INFORMATION--------"<<endl;
    gm.getgeneral_manager();

    return 0;
}