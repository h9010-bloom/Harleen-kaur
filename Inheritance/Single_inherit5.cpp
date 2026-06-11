#include <iostream>
using namespace std;
class student
{
    public:
    void input()
    {
        string name;
        int roll_no;
        int marks[3];

        cout<<"enter the name of student: ";
        cin>>name;
        cout<<"enter the roll no: ";
        cin>>roll_no;
        cout<<"enter the marks of 3 subjects: ";
        for(int i=0 ;i<=3;i++)
        {
            cin>>marks[i];
        }

    }
    void display()
    {
        cout<<"NAME OF THE STUDENT: "<<name<<endl;
        cout<<"ROLL NO: "<<roll_no<<endl;
        cout<<"MARKS: ";
        for(int i=0 ;i<=3;i++)
        {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};
class result:public student
{
    public:
    int total;
    int percentage;
    void calculation()
    {
        total = 0;
        for(int i=0; i<3; i++)
        {
            total += marks[i];
        }
        percentage=(total/300)*100;
    }
    void display ()
    {
        cout<<"TOTAL MARKS: "<<total<<endl;
        cout<<"PERCENTAGE: "<<percentage<<"%"<<endl;
    }

};