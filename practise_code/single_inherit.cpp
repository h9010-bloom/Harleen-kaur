#include <iostream>
using namespace std;
class Employee_staff
{
  int id_no;
  string name;
  int age;
  float salary;

  public:
  void setdata()
  {
    cout<<"Enter ID_NO: ";
    cin>>id_no;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Salary: ";
    cin>>salary;
  }
  void getdata()
  {
    cout<<"\tID_NO  : "<<id_no<<endl;
    cout<<"\tName   : "<<name<<endl;
    cout<<"\tAge    : "<<age<<endl;
    cout<<"\tSalary : "<<salary<<endl;
  }
};
class Helper_staff : public Employee_staff
{
  public:
  void work()
  {
    void setdata();
    void getdata();
  }
};
int main()
{
  Employee_staff es;
  es.setdata();
  es.getdata();
  Helper_staff hs;
  hs.setdata();
  hs.getdata();
  return 0;
}