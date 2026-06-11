#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
    int roll_no;
    void studentdata()
    {
        name="Divya";
        roll_no=808;

        cout<<"NAME: "<<name<<endl;
        cout<<"ROLL NO: "<<roll_no<<endl;
    }
};
class Marks:public virtual Student
{
    public:
    int phy_marks;
    int chem_marks;
    void marksdata()
    {
        phy_marks=80;
        chem_marks=85;

        cout<<"PHYSICS MARKS of "<<name<<" :"<<phy_marks<<endl;
        cout<<"CHEMISTRY MARKS of "<<name<<" :"<<chem_marks<<endl;
    }
};
class Sports:public virtual Student
{
    public:
    int sports_marks;
    void sportsdata()
    {
        sports_marks=10;

        cout<<"SPORTS MARKS of "<<name<<" :"<<sports_marks<<endl;
    }
};
class Result:public Marks,public Sports
{
    public:
    void calculateResult()
    {
        int total_marks= phy_marks + chem_marks + sports_marks;
        cout<<"TOTAL MARKS: "<<total_marks<<endl;
    }
};
int main ()
{
    Result r;
    r.studentdata();
    r.marksdata();
    r.sportsdata();
    r.calculateResult();
    return 0;
}