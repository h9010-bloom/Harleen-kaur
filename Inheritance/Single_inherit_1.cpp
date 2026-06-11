#include <iostream>
#include <string>
using namespace std;
class person
{
    string name;
    int age;

    public:
    void setdata(string n,int a)
    {
        name=n;
        age=a;
    }
    void getdata()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"AGE: "<<age<<endl;
    }
};
class student:public person
{
    string course;
    int roll_no;

    public:
    void setdata(string n,int a,string c,int r)
    {
        person::setdata(n,a);
        person();
        course=c;
        roll_no=r;
    }
    void getdata()
    {
        person::getdata();
        cout<<"COURSE: "<<course<<endl;
        cout<<"ROLL NO: "<<roll_no<<endl;
    }
};
int main()
{
    student s;
    s.setdata("radhika",29,"BCA",101);
    s.getdata();

    return 0;
}