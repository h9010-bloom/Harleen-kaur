#include<iostream>
using namespace std;
class base
{
    public:
    int l;
    int b;

    void input()
    {
        cout<<"enter the value for length: "<<endl;
        cin>>l;

        cout<<"enter the value for breadth: "<<endl;
        cin>>b;
    }
};
class derive:public base
{
    public:
    void display()
    {
        int area=l*b;
        cout<<"AREA OF THE RECTANGLE: "<<area<<endl;
    }
};
int main()
{
    derive d;
    d.input();
    d.display();

    return 0;
}