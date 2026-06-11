#include<iostream>
using namespace std;
class Student
{
    string name;
    int rollno;

    public:
    Student()
    {
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter roll no: ";
        cin>>rollno;

        cout<<"constructor called for "<<name<<endl;
    }
    void display()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"ROLL NO: "<<rollno<<endl;
    }
    ~Student()
    {
        cout<<"destructor called for "<<name<<endl;
    }
};
int main()
{
    cout<<"----- CREATING OBJECT STUDENT 'S' -----"<<endl;
    Student s;
    s.display();
    cout<<"----END OF MAIN FUNCTION----"<<endl;
    return 0;
}