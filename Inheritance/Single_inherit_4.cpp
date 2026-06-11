#include<iostream>
using namespace std;
class employee
{
    public:
    string name;
    int id;
    int basic_salary;

    void input()
    {
        cout<<"enter the name: ";
        cin>>name;
        cout<<"enter ID: ";
        cin>>id;
        cout<<"enter basic salry: ";
        cin>>basic_salary;
    }
};
class calculate_salary:public employee
{
    public:
    void calculation()
    {
        int HRA=0.10 * basic_salary;
        int DA=0.05 * basic_salary;

        int total_salary=basic_salary+HRA+DA;
        
        cout<<"TOTAL SALARY OF "<<name<<" IS: "<<total_salary<<endl;
    }
};
int main()
{
    calculate_salary cs;
    
    cout<<"\n------INPUTTED DETAIL ABOUT EMPLOYEE------\n"<<endl;
    cs.input();

    cout<<"\n------TOTAL SALARY OF EMPLOYEE------\n"<<endl;
    cs.calculation();

    return 0;
}