#include <iostream>
using namespace std;
class employee
{
    private:
    string name;
    int ID_no;
    float salary;

    public:
    employee()          //constructor
    {
        cout<<"enter a name:";
        cin>>name;
        cout<<"enter ID no. :";
        cin>>ID_no;
        cout<<"enter a salary: ";
        cin>>salary;
    }
    void display()
    {
        cout<<"\n Name = " <<name<<endl;
        cout<<"\n ID_no = "<<ID_no<<endl;
        cout<<"\n salary = "<<salary<<endl;
    }  
};
int main()
{
    employee e1;
    e1.display();
    return 0;
}