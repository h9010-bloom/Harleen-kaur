#include<iostream>
using namespace std;
class student
{
    int roll;
    string name;
    public:
    student(int r, string n)//parametrized constructor
    {
        roll=r;
        name=n;
        cout<<"The name of the student is: "<<name<<endl;
        cout<<"The roll no of the student is: "<<roll<<endl;
    }
};
int main()
{
    student s(102,"Amit");
}